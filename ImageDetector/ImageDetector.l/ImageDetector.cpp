// Copyright (c) 2023 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

// Includes
#include <ConcreteArrays.h>
#include "ImageDetector.h"
#include "IDL_Adapters_DGT.h"
#include "IDL_Adapters_DPKF.h"
#include "FrameAgent.h"
#include "AddNoise.h"
#include "AddStar.h"

//----------------------------------------------------------------------
// Device Constructor
//----------------------------------------------------------------------
ImageDetector::ImageDetector(string name)
: ImageDetectorBase(name),
	frameAgent_(name, "DF/Manager1"),
	windows_(1,4)
{
	trace_.out("ImageDetector constructor\n");
	className_ = "ImageDetector";
	(windows_)[0][0] = 1;
	(windows_)[0][1] = 1;
	(windows_)[0][2] = 1024;
	(windows_)[0][3] = 1024;

}

//----------------------------------------------------------------------
// Device destructor
//----------------------------------------------------------------------
ImageDetector::~ImageDetector()
{
  trace_.out("destructor\n");
}

/************************************************************************
*************************************************************************
**                                                                     **
**       Virtual methods inherited from Device interface               **
**                                                                     **
*************************************************************************
************************************************************************/
	
//----------------------------------------------------------------------
// Connects device with GCS services
//----------------------------------------------------------------------
void ImageDetector::connect(string orbname, bool corbaDebug, unsigned threads, long priority, bool mode, bool update)
{
	trace_.out("ImageDetector::connect()\n");
	ImageDetectorBase::connect(orbname, corbaDebug, threads, priority, mode, update);
	
	//## Add code as required
	
}

//----------------------------------------------------------------------
// Performs starting procedure: OFF-->STARTING-->ON
//----------------------------------------------------------------------
void ImageDetector::start()
{
	trace_.out("start()\n");
	
	try
	{
		goStarting_();
	
		// Configure device
		try
		{
			configure("Default");
		}
		catch(GCSException& ex)
		{
			//logError_("unable to configure device");
			throw;
		}
		
		createMonitors_();
		
		// ## Create other classes required for this Device
		
		// ## Create other threads required for this Device
		
		goOn_();
	}
	catch(GCSException& ex)
	{
		goFault_();
		ex.addToTrace("ImageDetector::start()"); 
		trace_.err("ImageDetector::start() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs initialization procedure: ON-->INITIALISING-->READY
//----------------------------------------------------------------------
void ImageDetector::init()
{
	trace_.out("init()\n");
	
	try
	{
		goInitialising_();
		
		// ## Initialization procedure
		exposureTimeSeconds_=1;
		frameAgent_.connect(logAgent_, alarmAgent_, "", "DF/Manager1");
		
		cout << endl << "ImageDetector READY!!!" << endl << endl;
		
		goIdle_();  // or goRunning_();
	}
	catch(GCSException& ex)
	{
		goFault_();
		ex.addToTrace("ImageDetector::init()"); 
		trace_.err("ImageDetector::init() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs halting procedure: READY-->HALTING-->ON
//----------------------------------------------------------------------
void ImageDetector::halt()
{
	trace_.out("halt()\n");
	
	try
	{
		goHalting_();
		
		// ## Halting procedure
		
		goOn_();
	}
	catch(GCSException& ex)
	{
		goFault_();
		ex.addToTrace("ImageDetector::halt()"); 
		trace_.err("ImageDetector::halt() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs shutdown procedure: ON-->SHUTTING_DOWN-->OFF
//----------------------------------------------------------------------
void ImageDetector::shutdown()
{
	trace_.out("shutdown()\n");
	
	try
	{
		goShuttingDown_();
		
		// ## Shutdown procedure
		
		goOff_();
	}
	catch(GCSException& ex)
	{
		goFault_();
		ex.addToTrace("ImageDetector::shutdown()"); 
		trace_.err("ImageDetector::shutdown() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs reset procedure: FAULT-->RESETTING-->ON
//----------------------------------------------------------------------
void ImageDetector::reset()
{
	trace_.out("reset()\n");
	
	try
	{
		goResetting_();
		
		// ## Resetting procedure
		
		goOn_();
	}
	catch(GCSException& ex)
	{
		goFault_();
		ex.addToTrace("ImageDetector::reset()"); 
		trace_.err("ImageDetector::reset() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs test procedure: only possible in ON state
//----------------------------------------------------------------------
void ImageDetector::test()
{
	trace_.out("test()\n");
	
	try
	{
		if (isOn()==FALSE)
		{
			//logError_("Test is only posible in ON state");
			throw WrongState(name_.c_str(),"Not in ON state. Unable to test");
		}
		
		// ## Test procedure
		
	}
	catch(GCSException& ex)
	{
		goFault_();
		ex.addToTrace("ImageDetector::test()"); 
		trace_.err("ImageDetector::test() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs abort: interrupt any current operation and goes to FAULT
//----------------------------------------------------------------------
void ImageDetector::abort()
{
	trace_.out("abort()\n");
	
	// ## Abort procedure
	
	goFault_();
}

//----------------------------------------------------------------------
// Report device status: returns static memory, do not delete! 
//----------------------------------------------------------------------
char* ImageDetector::report(short level)
{
	trace_.out("report(%d)\n",level);
	char* dev_reply = new char[DEVICE_REPORT_SIZE_];
	ostrstream ost(dev_reply, DEVICE_REPORT_SIZE_);
	memset(dev_reply,0,DEVICE_REPORT_SIZE_);
	
	// Generic Device info
	ost << ImageDetectorBase::report(level);
	
	// ## Add here your other monitors
	
	// ## Add more information if required
	
	return(dev_reply);
}

/************************************************************************
*************************************************************************
**                                                                     **
**                 Specific methods of this Device                     **
**                                                                     **
*************************************************************************
*************************************************************************
* All specific methods:                                                 *
* - Shall make a transition to RUNNING (even when is already running)   *
* - Shall make a transition to IDLE when the Device in really idle      *
* - Use ACE_Guard only for thread safe operations                       *
* - If an error is detected use //logError_() & throw GCSException        *
* - If an alarm is detected use sendAlarm_()                            *
* - If a failure is detected use goFault_(method)                       *
* - Access to a DeviceDriver or aggregated Device can be required       *
************************************************************************/
	
//----------------------------------------------------------------------
// expose 
//----------------------------------------------------------------------
void ImageDetector::expose()
{
	ACE_Guard<ACE_Thread_Mutex> guard(deviceGuardMutex_);

	trace_.out("expose()\n");

	try
	{
		goRunning_();

		if ( ! isDisabled())
		{
			//logInfo_("expose()");
			
			//## Add code as required
			idExposing_ = true;
			idExposureTimeLeft_ = exposureTimeSeconds_;
			TimeService::sleep( exposureTimeSeconds_);
			Frame<double,2> frame;
			buildFrame_(frame);
			frameAgent_.sendFrame(frame,exposureTimeSeconds_, windows_);
			idExposing_ = false;
			idExposureTimeLeft_ = 0;

			
			//logInfo_("expose() completed successfully");
		}
		else
			//logInfo_("Device disabled. expose not executed");

		goIdle_();
	}
	catch(GCSException& ex)
	{
		goIdle_();
		ex.addToTrace("ImageDetector::expose()");
		//logError_("ImageDetector::expose() exception - %s\n", ex.toString());
		trace_.err("ImageDetector::expose() exception - %s\n", ex.toString());
		throw;
	}
}

void ImageDetector::buildFrame_(Frame<double,2> & frame)
{

	TinyVector<unsigned long,2> size ((windows_)[0][2]-(windows_)[0][0]+1,(windows_)[0][3]-(windows_)[0][1]+1);
	frame.resize(size);

	//Add Keywords
	frame.addKeyword (DPKF::Keyword<string>("CCD-MODE", "FAST"));

	double random_px = (double)rand() / RAND_MAX;
	random_px = -5 + random_px * (5 - (-5));

	TinyVector<unsigned long,2> sizeWindow ((windows_)[0][2]-(windows_)[0][0]+1,(windows_)[0][3]-(windows_)[0][1]+1);

	double middleX = (sizeWindow[0])/2.0 + random_px;
	double middleY = (sizeWindow[1])/2.0 + random_px;

	TinyVector<double,2> starCoordinate(middleX,middleY);

	AddNoise<double,2> addNoise_;
	addNoise_.run(frame,POISSON,900,900);

	AddStar<double,2> addStarFilter;
	addStarFilter.run(frame,middleX,middleY,5.0,60e4);
}


//----------------------------------------------------------------------
// setExposureTimeSeconds 
//----------------------------------------------------------------------
void ImageDetector::setExposureTimeSeconds(double time)
{
	ACE_Guard<ACE_Thread_Mutex> guard(deviceGuardMutex_);

	trace_.out("setExposureTimeSeconds(%lf)\n",time);

	try
	{
		goRunning_();

		//## check if input parameters are valid here

		if ( ! isDisabled())
		{
			//logInfo_("setExposureTimeSeconds()");
			
			//## Add code as required
			exposureTimeSeconds_ = time;
			
			
			//logInfo_("setExposureTimeSeconds() completed successfully");
		}
		else
			//logInfo_("Device disabled. setExposureTimeSeconds not executed");

		goIdle_();
	}
	catch(GCSException& ex)
	{
		goIdle_();
		ex.addToTrace("ImageDetector::setExposureTimeSeconds()");
		//logError_("ImageDetector::setExposureTimeSeconds() exception - %s\n", ex.toString());
		trace_.err("ImageDetector::setExposureTimeSeconds() exception - %s\n", ex.toString());
		throw;
	}
}

/************************************************************************
*************************************************************************
**                                                                     **
**                        Specific private methods                     **
**                                                                     **
*************************************************************************
************************************************************************/
	
