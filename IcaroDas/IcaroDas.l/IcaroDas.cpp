// Copyright (c) 2020 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

// Includes
#include <ConcreteArrays.h>
#include "IcaroDas.h"
#include "Task.h"
#include "IDL_Adapters_DGT.h"
#include "IDL_Adapters_DPKF.h"
#include "FrameAgent.h"
#include "AddNoise.h"
#include "AddStar.h"

//----------------------------------------------------------------------
// Device Constructor
//----------------------------------------------------------------------
IcaroDas::IcaroDas(string name)
: IcaroDasBase(name),
  	frameAgent_(name, "ICARODFAgent"),
	windows_(1,4)
{
	trace_.out("IcaroDas constructor\n");
	className_ = "IcaroDas";

	(windows_)[0][0] = 1;
    (windows_)[0][1] = 1;
    (windows_)[0][2] = 1024;
    (windows_)[0][3] = 1024;
}

//----------------------------------------------------------------------
// Device destructor
//----------------------------------------------------------------------
IcaroDas::~IcaroDas()
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
void IcaroDas::connect(string orbname, bool corbaDebug, unsigned threads, long priority, bool mode, bool update)
{
	trace_.out("IcaroDas::connect()\n");
	IcaroDasBase::connect(orbname, corbaDebug, threads, priority, mode, update);
	
	//## Add code as required
	
}

//----------------------------------------------------------------------
// Performs starting procedure: OFF-->STARTING-->ON
//----------------------------------------------------------------------
void IcaroDas::start()
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
			logError_("unable to configure device");
			throw;
		}
		
		//createMonitors_();
	
		
		// ## Create other threads required for this Device
		
		goOn_();
	}
	catch(GCSException& ex)
	{
		goFault_();
		ex.addToTrace("IcaroDas::start()"); 
		trace_.err("IcaroDas::start() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs initialization procedure: ON-->INITIALISING-->READY
//----------------------------------------------------------------------
void IcaroDas::init()
{
	trace_.out("init()\n");
	
	try
	{
		goInitialising_();
		
		// ## Initialization procedure
		ccdState_ = CCD_IDLE;
		magnitudeChange_("ccdState",ccdState_);
		numberOfExposures_=1;
		exposureTimeSeconds_=1;
		frameAgent_.connect(logAgent_, alarmAgent_, dataFactoryAgentInstanceCorbaName_, dataFactoryManagerInstanceCorbaName_);
		
		cout << endl << "IcaroDas READY!!!" << endl << endl;
		
		goIdle_();  // or goRunning_();
	}
	catch(GCSException& ex)
	{
		goFault_();
		ex.addToTrace("IcaroDas::init()"); 
		trace_.err("IcaroDas::init() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs halting procedure: READY-->HALTING-->ON
//----------------------------------------------------------------------
void IcaroDas::halt()
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
		ex.addToTrace("IcaroDas::halt()"); 
		trace_.err("IcaroDas::halt() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs shutdown procedure: ON-->SHUTTING_DOWN-->OFF
//----------------------------------------------------------------------
void IcaroDas::shutdown()
{
	trace_.out("shutdown()\n");
	
	try
	{
		goShuttingDown_();
		
		// ## Shutdown procedure

		frameAgent_.disconnect();
		
		goOff_();
	}
	catch(GCSException& ex)
	{
		goFault_();
		ex.addToTrace("IcaroDas::shutdown()"); 
		trace_.err("IcaroDas::shutdown() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs reset procedure: FAULT-->RESETTING-->ON
//----------------------------------------------------------------------
void IcaroDas::reset()
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
		ex.addToTrace("IcaroDas::reset()"); 
		trace_.err("IcaroDas::reset() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs test procedure: only possible in ON state
//----------------------------------------------------------------------
void IcaroDas::test()
{
	trace_.out("test()\n");
	
	try
	{
		if (isOn()==FALSE)
		{
			logError_("Test is only posible in ON state");
			throw WrongState(name_.c_str(),"Not in ON state. Unable to test");
		}
		
		// ## Test procedure
		
	}
	catch(GCSException& ex)
	{
		goFault_();
		ex.addToTrace("IcaroDas::test()"); 
		trace_.err("IcaroDas::test() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs abort: interrupt any current operation and goes to FAULT
//----------------------------------------------------------------------
void IcaroDas::abort()
{
	trace_.out("abort()\n");
	
	// ## Abort procedure
	
	goFault_();
}

//----------------------------------------------------------------------
// Report device status: returns static memory, do not delete! 
//----------------------------------------------------------------------
char* IcaroDas::report(double level)
{
	trace_.out("report(%d)\n",level);
	char* dev_reply = new char[DEVICE_REPORT_SIZE_];
	ostrstream ost(dev_reply, DEVICE_REPORT_SIZE_);
	memset(dev_reply,0,DEVICE_REPORT_SIZE_);
	
	// Generic Device info
	ost << IcaroDasBase::report(level);
	
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
* - If an error is detected use logError_() & throw GCSException        *
* - If an alarm is detected use sendAlarm_()                            *
* - If a failure is detected use goFault_(method)                       *
* - Access to a DeviceDriver or aggregated Device can be required       *
************************************************************************/
	
//----------------------------------------------------------------------
// expose 
//----------------------------------------------------------------------
void IcaroDas::expose()
{
	ACE_Guard<ACE_Thread_Mutex> guard(deviceGuardMutex_);

	trace_.out("expose()\n");

	if (!this->isIdle() || ccdState_ != CCD_IDLE)
	{
		WrongState ex ("IcaroDas::expose()", "expose() only allowed in IDLE state");
		cout<<"ERROR: "<<ex.toString()<<endl;
		logError_ (ex.toString());
		throw ex;
	}	

	try
	{
		goRunning_();

		if ( ! isDisabled())
		{
			logInfo_("expose()");
			
			//## Add code as required
			Task * expose_task_ = new Task("expose_task", FunctionAdaptorHelper::adapt(this,&IcaroDas::expose_));
			expose_task_->priority(100);
			expose_task_->stackSize(65536);
			expose_task_->spawn();
			
			logInfo_("expose() completed successfully");
		}
		else
			logInfo_("Device disabled. expose not executed");

		goIdle_();
	}
	catch(GCSException& ex)
	{
		goIdle_();
		ex.addToTrace("IcaroDas::expose()");
		logError_("IcaroDas::expose() exception - %s\n", ex.toString());
		trace_.err("IcaroDas::expose() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// expose 
//----------------------------------------------------------------------
void IcaroDas::exposeFromFile(const char* filename)
{
	ACE_Guard<ACE_Thread_Mutex> guard(deviceGuardMutex_);

	trace_.out("expose()\n");

	if (!this->isIdle() || ccdState_ != CCD_IDLE)
	{
		WrongState ex ("IcaroDas::expose()", "expose() only allowed in IDLE state");
		cout<<"ERROR: "<<ex.toString()<<endl;
		logError_ (ex.toString());
		throw ex;
	}	

	try
	{
		goRunning_();

		if ( ! isDisabled())
		{
			logInfo_("exposeFromFile()");
			
			//## Add code as required

			/* Send Fits image file */
			frameAgent_.sendFitsFile(filename, exposureTimeSeconds_, windows_);
			
			logInfo_("exposeFromFile() completed successfully");
		}
		else
			logInfo_("Device disabled. expose not executed");

		goIdle_();
	}
	catch(GCSException& ex)
	{
		goIdle_();
		ex.addToTrace("IcaroDas::expose()");
		logError_("IcaroDas::expose() exception - %s\n", ex.toString());
		trace_.err("IcaroDas::expose() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// abortAcquisition 
//----------------------------------------------------------------------
void IcaroDas::abortAcquisition()
{
	ACE_Guard<ACE_Thread_Mutex> guard(deviceGuardMutex_);

	trace_.out("abortAcquisition()\n");

	try
	{
		goRunning_();

		if ( ! isDisabled())
		{
			logInfo_("abortAcquisition()");
			
			//## Add code as required
			abortAcquisition_=true;
			
			logInfo_("abortAcquisition() completed successfully");
		}
		else
			logInfo_("Device disabled. abortAcquisition not executed");

		goIdle_();
	}
	catch(GCSException& ex)
	{
		goIdle_();
		ex.addToTrace("IcaroDas::abortAcquisition()");
		logError_("IcaroDas::abortAcquisition() exception - %s\n", ex.toString());
		trace_.err("IcaroDas::abortAcquisition() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// setupNumberOfExposures 
//----------------------------------------------------------------------
void IcaroDas::setupNumberOfExposures(long num)
{
	ACE_Guard<ACE_Thread_Mutex> guard(deviceGuardMutex_);

	trace_.out("setupNumberOfExposures(%ld)\n",num);

	try
	{
		goRunning_();

		//## check if input parameters are valid here

		if ( ! isDisabled())
		{
			logInfo_("setupNumberOfExposures()");
			
			//## Add code as required
 			numberOfExposures_=num;			
			
			logInfo_("setupNumberOfExposures() completed successfully");
		}
		else
			logInfo_("Device disabled. setupNumberOfExposures not executed");

		goIdle_();
	}
	catch(GCSException& ex)
	{
		goIdle_();
		ex.addToTrace("IcaroDas::setupNumberOfExposures()");
		logError_("IcaroDas::setupNumberOfExposures() exception - %s\n", ex.toString());
		trace_.err("IcaroDas::setupNumberOfExposures() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// setupExposureTimeSeconds 
//----------------------------------------------------------------------
void IcaroDas::setupExposureTimeSeconds(double exposureTime)
{
	ACE_Guard<ACE_Thread_Mutex> guard(deviceGuardMutex_);

	trace_.out("setupExposureTimeSeconds(%lf)\n",time);

	try
	{
		goRunning_();

		//## check if input parameters are valid here

		if ( ! isDisabled())
		{
			logInfo_("setupExposureTimeSeconds()");
			
			//## Add code as required
			exposureTimeSeconds_=exposureTime;	
			
			logInfo_("setupExposureTimeSeconds() completed successfully");
		}
		else
			logInfo_("Device disabled. setupExposureTimeSeconds not executed");

		goIdle_();
	}
	catch(GCSException& ex)
	{
		goIdle_();
		ex.addToTrace("IcaroDas::setupExposureTimeSeconds()");
		logError_("IcaroDas::setupExposureTimeSeconds() exception - %s\n", ex.toString());
		trace_.err("IcaroDas::setupExposureTimeSeconds() exception - %s\n", ex.toString());
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
	
void IcaroDas::expose_()
{
	//signal the transfer task
	ccdState_ = CCD_EXPOSING;
	magnitudeChange_ ("ccdState", ccdState_);

	//## Add code as required
	for (int i=0;i< numberOfExposures_;i++)
	{
			if (abortAcquisition_)
			{
					abortAcquisition_=false;
					break;
			}

			trace_.out("EXPOSITION (%d)\n",i);

			TimeService::sleep( exposureTimeSeconds_);

			/* Create synthetic image */
			Frame<double,2> frame;
			buildFrame_(frame);

			/* Send image */
			frameAgent_.sendFrame(frame,exposureTimeSeconds_, windows_);
	}

	//signal the transfer task
	ccdState_ = CCD_IDLE;
	magnitudeChange_ ("ccdState", ccdState_);
}


void IcaroDas::buildFrame_(Frame<double,2> & frame)
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
