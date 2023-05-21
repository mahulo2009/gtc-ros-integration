// Copyright (c) 2023 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

// Includes
#include "FilterWheel.h"
#include "FilterWheelAdapter.h"
#include "FilterWheelConfigAgent.h"

//----------------------------------------------------------------------
// Device Constructor
//----------------------------------------------------------------------
FilterWheelBase::FilterWheelBase(string name)
: Device(name)
{
	trace_.out("FilterWheelBase constructor\n");
	className_ = "FilterWheelBase";
	isComposite_ = FALSE;
	
	// Init some properties with hardcoded values
	
	// Init monitors to avoid they contain garbage
	filterWheelMoving_  = 0;
}

//----------------------------------------------------------------------
// Device destructor
//----------------------------------------------------------------------
FilterWheelBase::~FilterWheelBase()
{
  trace_.out("destructor\n");
}

/************************************************************************
*************************************************************************
**                                                                     **
**            Virtual methods inherited from Device interface          **
**                                                                     **
*************************************************************************
************************************************************************/
	
//----------------------------------------------------------------------
// Connects device with GCS services
//----------------------------------------------------------------------
void FilterWheelBase::connect(string orbname, bool corbaDebug, unsigned threads, long priority, bool mode, bool update)
{
	try
	{
		Device::connect(orbname, corbaDebug, threads, priority, mode, update);
		corbaDebug_ = corbaDebug;
		update_ = update;
		
		// Create IDL/CORBA Adapter
		try
		{
			trace_.out("creating IDL adapter\n");
			adapter_ = new FilterWheelAdapter(this);
		}
		catch(GCSException& ex)
		{
			trace_.err("IDL adapter can't be created\n");
			throw;
		}
		
		// Connect adapter with CORBA context
		try
		{
			trace_.out("connecting adapter with CORBA\n");
			adapter_->setupCorba((PortableServer::Servant)adapter_,corbaContext_);
		}
		catch(GCSException& ex)
		{
			trace_.err("IDL adapter can't be connected to CORBAContext\n");
			throw;
		}
		
		// Create the MonitorAgent for this class
		try
		{
			trace_.out("creating monitor agent\n");
			monitorAgent_ = new MonitorAgent(name_.c_str());
		}
		catch(GCSException& ex)
		{
			if(ex.isA("CorbaException")) trace_.err("MonitorManager is down or unreachable\n");
			else trace_.err("unable to create monitor agent\n");
			throw;
		}
		
		// Create the ConfigAgent for this class
		try
		{
			trace_.out("creating configuration agent\n");
			configAgent_ = new FilterWheelConfigAgent(this,mode_,lowPriorityTimer_);
		}
		catch(GCSException& ex)
		{
			if(ex.isA("CorbaException")) trace_.err("ConfigManager is down or unreachable\n");
			else trace_.err("unable to create config agent\n");
			throw;
		}
		
		// Update profile if required
		try
		{
			if (update) updateProfile_();
		}
		catch(GCSException& ex)
		{
			if(ex.isA("CorbaException")) trace_.err("AlarmManager or ConfigManager are down or unreachable\n");
			else trace_.err("unable to update Profile\n");
			throw;
		}
		
		
		trace_.out("connected\n");
	}
	catch(GCSException& ex)
	{
		ex.addToTrace("FilterWheelBase::connect()"); 
		trace_.err("FilterWheelBase::connect() - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs starting procedure: OFF-->STARTING-->ON
//----------------------------------------------------------------------
void FilterWheelBase::start()
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
		
		createMonitors_();
		
		// ## Create other classes required for this Device
		
		// ## Create other threads required for this Device
		
		goOn_();
	}
	catch(GCSException& ex)
	{
		goFault_();
		ex.addToTrace("FilterWheelBase::start()"); 
		trace_.err("FilterWheelBase::start() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs initialization procedure: ON-->INITIALISING-->READY
//----------------------------------------------------------------------
void FilterWheelBase::init()
{
	trace_.out("init()\n");
	
	try
	{
		goInitialising_();
		
		// ## Initialization procedure
		
		
		cout << endl << "FilterWheel READY!!!" << endl << endl;
		
		goIdle_();  // or goRunning_();
	}
	catch(GCSException& ex)
	{
		goFault_();
		ex.addToTrace("FilterWheelBase::init()"); 
		trace_.err("FilterWheelBase::init() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs halting procedure: READY-->HALTING-->ON
//----------------------------------------------------------------------
void FilterWheelBase::halt()
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
		ex.addToTrace("FilterWheelBase::halt()"); 
		trace_.err("FilterWheelBase::halt() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs shutdown procedure: ON-->SHUTTING_DOWN-->OFF
//----------------------------------------------------------------------
void FilterWheelBase::shutdown()
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
		ex.addToTrace("FilterWheelBase::shutdown()"); 
		trace_.err("FilterWheelBase::shutdown() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs reset procedure: FAULT-->RESETTING-->ON
//----------------------------------------------------------------------
void FilterWheelBase::reset()
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
		ex.addToTrace("FilterWheelBase::reset()"); 
		trace_.err("FilterWheelBase::reset() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs restore procedure: goes to previous state
//----------------------------------------------------------------------
void FilterWheelBase::restore()
{
	trace_.out("restore()\n");
	
	if (isFault()==FALSE)
	{
		logError_("Restore is only posible in FAULT state");
		throw WrongState(name_.c_str(),"Not in FAULT state. Unable to restore");
	}
	
	// ## Restore procedure
	
	goPreviousState_();
	
	if (isRunning())
		goIdle_();
	else
		if (isInitialising())
			goOn_();
		else
			if (isStarting())
				goOff_();
			else
				if (isHalting())
					goIdle_();
				else
				if (isShuttingDown())
					goOn_();
	
	cancelAlarm_(const_cast<char *>("DeviceFault"),const_cast<char *>("Device is restored"));
}

//----------------------------------------------------------------------
// Performs test procedure: only possible in ON state
//----------------------------------------------------------------------
void FilterWheelBase::test()
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
		ex.addToTrace("FilterWheelBase::test()"); 
		trace_.err("FilterWheelBase::test() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs abort: interrupt any current operation and goes to FAULT
//----------------------------------------------------------------------
void FilterWheelBase::abort()
{
	trace_.out("abort()\n");
	
	// ## Abort procedure
	
	goFault_();
}

//----------------------------------------------------------------------
// Report device status: returns static memory, do not delete! 
//----------------------------------------------------------------------
char* FilterWheelBase::report(short level)
{
	trace_.out("report(%d)\n",level);
	char* dev_reply = new char[DEVICE_REPORT_SIZE_];
	ostrstream ost(dev_reply, DEVICE_REPORT_SIZE_);
	memset(dev_reply,0,DEVICE_REPORT_SIZE_);
	
	// Generic Device info
	ost << Device::report(level);
	
	// ## Use level parameter to show more/less info
	// Current Device report
	ost << endl << "Device Properties" << endl;   
	ost << "-------------------------------------------------------" << endl;
	// ## Add here your other properties
	
	ost << endl << "Device Magnitudes" << endl;   
	ost << "-------------------------------------------------------" << endl;
	ost << "filterWheelMoving   :" << filterWheelMoving() << endl;
	// ## Add here your other monitors
	
	// ## Add more information if required
	
	
	return(dev_reply);
}

//----------------------------------------------------------------------
// Returns SVN module version. (TODO)  
//----------------------------------------------------------------------
const char* FilterWheelBase::version()
{
	trace_.out("version()\n");
	return("UNKNOWN");
}

//----------------------------------------------------------------------
// Create monitors of this Device  
//----------------------------------------------------------------------
void FilterWheelBase::createMonitors_()
{
	trace_.out("creating monitors\n");
	
	try
	{
		if (monitorAgent_ != NULL)
		{
		}
	}
	catch(GCSException& ex)
	{
		ex.addToTrace("FilterWheelBase::createMonitors_()"); 
		throw;
	}
}

/************************************************************************
*************************************************************************
**                                                                     **
**           Monitorable attributes (device magnitudes)                **
**                                                                     **
*************************************************************************
*************************************************************************
* All get monitor methods:                                              *
* - Can be invoked in any state of the Device                           *
* - Do not modify the state of the Device                               *
* - It is required to check the ranges of the monitored values          *
* - If an alarm is detected use sendAlarm_()                            *
* - Shall be as fast as possible (due to high monitoring rate)          *
* - Acces to a DeviceDriver or aggregated Device can be required        *
* - In bool & enum monitors use magnitudeChange_() to inform of change  *
* All set monitor methods:                                              *
* - Shall make a transition to RUNNING (even when is already running)   *
* - Shall make a transition to IDLE when the Device in really idle      *
* - Use ACE_Guard only for thread safe operations                       *
* - If an error is detected use logError_() & throw GCSException        *
* - If an alarm is detected use sendAlarm_()                            *
* - If a failure is detected use goIdle_()                              *
************************************************************************/
	
//----------------------------------------------------------------------
// Get filterWheelFilter Monitor
//----------------------------------------------------------------------
FilterWheelBase::Filter FilterWheelBase::filterWheelFilter()
{
	//trace_.out("filterWheelFilter()\n");
	
	// ## Obtain the filterWheelFilter_ value, if required. Example:
	// filterWheelFilter_ = adcConversion();
	
	// ## check ranges: use magnitudeLowerLimit_() and magnitudeUpperLimit_()
	
	return filterWheelFilter_;
}

//----------------------------------------------------------------------
// Get filterWheelMoving Monitor
//----------------------------------------------------------------------
bool FilterWheelBase::filterWheelMoving()
{
	//trace_.out("filterWheelMoving()\n");
	
	// ## Obtain the filterWheelMoving_ value, if required. Example:
	// filterWheelMoving_ = memoryMap.bit(15);
	// If value has changed use:
	//magnitudeChange_("filterWheelMoving",filterWheelMoving_); // inform of change
	
	return filterWheelMoving_;
}

/************************************************************************
*************************************************************************
**                                                                     **
**          Configurable attributes (device properties)                **
**                                                                     **
*************************************************************************
*************************************************************************
* All property methods:                                                 *
* - Used ONLY in STARTING,ON,IDLE,FAULT. Use checkConfigurability_()    *
* - Do not modify the state of the Device                               *
* - Both get/set methods shall be provided for each property            *
* - Properties shall have a default value initialized at startup        *
* - It is required to check the ranges before to apply properties       *
* - If an error is detected: use logError_() & throw GCSException       *
* - Inform that a property is changed: use propertyChange_()            *
************************************************************************/
	
