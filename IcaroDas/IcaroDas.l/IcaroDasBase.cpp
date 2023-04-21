// Copyright (c) 2022 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

// Includes
#include "IcaroDas.h"
#include "IcaroDasAdapter.h"
#include "IcaroDasConfigAgent.h"

//----------------------------------------------------------------------
// Device Constructor
//----------------------------------------------------------------------
IcaroDasBase::IcaroDasBase(string name)
: Device(name)
{
	trace_.out("IcaroDasBase constructor\n");
	className_ = "IcaroDasBase";
	isComposite_ = FALSE;
	
	// Init some properties with hardcoded values
	dataFactoryAgentInstanceCorbaName_   = "ICARODFAgent";
	dataFactoryManagerInstanceCorbaName_ = "DF/Manager1";
	
	// Init monitors to avoid they contain garbage
	exposureTimeLeft_  = 0;
	currentExposure_ = 0;
}

//----------------------------------------------------------------------
// Device destructor
//----------------------------------------------------------------------
IcaroDasBase::~IcaroDasBase()
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
void IcaroDasBase::connect(string orbname, bool corbaDebug, unsigned threads, long priority, bool mode, bool update)
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
			adapter_ = new IcaroDasAdapter(this);
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
			configAgent_ = new IcaroDasConfigAgent(this,mode_,lowPriorityTimer_);
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
		ex.addToTrace("IcaroDasBase::connect()"); 
		trace_.err("IcaroDasBase::connect() - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs starting procedure: OFF-->STARTING-->ON
//----------------------------------------------------------------------
void IcaroDasBase::start()
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
		ex.addToTrace("IcaroDasBase::start()"); 
		trace_.err("IcaroDasBase::start() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs initialization procedure: ON-->INITIALISING-->READY
//----------------------------------------------------------------------
void IcaroDasBase::init()
{
	trace_.out("init()\n");
	
	try
	{
		goInitialising_();
		
		// ## Initialization procedure
		
		
		cout << endl << "IcaroDas READY!!!" << endl << endl;
		
		goIdle_();  // or goRunning_();
	}
	catch(GCSException& ex)
	{
		goFault_();
		ex.addToTrace("IcaroDasBase::init()"); 
		trace_.err("IcaroDasBase::init() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs halting procedure: READY-->HALTING-->ON
//----------------------------------------------------------------------
void IcaroDasBase::halt()
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
		ex.addToTrace("IcaroDasBase::halt()"); 
		trace_.err("IcaroDasBase::halt() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs shutdown procedure: ON-->SHUTTING_DOWN-->OFF
//----------------------------------------------------------------------
void IcaroDasBase::shutdown()
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
		ex.addToTrace("IcaroDasBase::shutdown()"); 
		trace_.err("IcaroDasBase::shutdown() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs reset procedure: FAULT-->RESETTING-->ON
//----------------------------------------------------------------------
void IcaroDasBase::reset()
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
		ex.addToTrace("IcaroDasBase::reset()"); 
		trace_.err("IcaroDasBase::reset() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs restore procedure: goes to previous state
//----------------------------------------------------------------------
void IcaroDasBase::restore()
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
void IcaroDasBase::test()
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
		ex.addToTrace("IcaroDasBase::test()"); 
		trace_.err("IcaroDasBase::test() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs abort: interrupt any current operation and goes to FAULT
//----------------------------------------------------------------------
void IcaroDasBase::abort()
{
	trace_.out("abort()\n");
	
	// ## Abort procedure
	
	goFault_();
}

//----------------------------------------------------------------------
// Report device status: returns static memory, do not delete! 
//----------------------------------------------------------------------
char* IcaroDasBase::report(short level)
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
	ost << "dataFactoryAgentInstanceCorbaName =" << dataFactoryAgentInstanceCorbaName() << endl;
	ost << "dataFactoryManagerInstanceCorbaName =" << dataFactoryManagerInstanceCorbaName() << endl;
	// ## Add here your other properties
	
	ost << endl << "Device Magnitudes" << endl;   
	ost << "-------------------------------------------------------" << endl;
	ost << "exposureTimeLeft    :" << exposureTimeLeft()  << endl;
	ost << "currentExposure     :" << currentExposure()   << endl;
	// ## Add here your other monitors
	
	// ## Add more information if required
	
	
	return(dev_reply);
}

//----------------------------------------------------------------------
// Returns SVN module version. (TODO)  
//----------------------------------------------------------------------
const char* IcaroDasBase::version()
{
	trace_.out("version()\n");
	return("UNKNOWN");
}

//----------------------------------------------------------------------
// Create monitors of this Device  
//----------------------------------------------------------------------
void IcaroDasBase::createMonitors_()
{
	trace_.out("creating monitors\n");
	
	try
	{
		if (monitorAgent_ != NULL)
		{
			monitorAgent_->createMonitor<IcaroDasBase,double>(this,"exposureTimeLeft",&IcaroDasBase::exposureTimeLeft);
			monitorAgent_->createMonitor<IcaroDasBase,long>(this,"currentExposure",&IcaroDasBase::currentExposure);
		}
	}
	catch(GCSException& ex)
	{
		ex.addToTrace("IcaroDasBase::createMonitors_()"); 
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
// Get ccdState Monitor
//----------------------------------------------------------------------
IcaroDasBase::CCDState IcaroDasBase::ccdState()
{
	//trace_.out("ccdState()\n");
	
	// ## Obtain the ccdState_ value, if required. Example:
	// If value has changed use:
	//magnitudeChange_("ccdState",ccdState_); // inform of change
	
	// ## check ranges: use magnitudeLowerLimit_() and magnitudeUpperLimit_()
	
	return ccdState_;
}

//----------------------------------------------------------------------
// Get exposureTimeLeft Monitor
//----------------------------------------------------------------------
double IcaroDasBase::exposureTimeLeft()
{
	//trace_.out("exposureTimeLeft()\n");
	
	// ## Obtain the exposureTimeLeft_ value, if required. Example:
	// exposureTimeLeft_ = adcConversion();
	
	// ## check ranges: use magnitudeLowerLimit_() and magnitudeUpperLimit_()
	
	return exposureTimeLeft_;
}

//----------------------------------------------------------------------
// Get currentExposure Monitor
//----------------------------------------------------------------------
long IcaroDasBase::currentExposure()
{
	//trace_.out("currentExposure()\n");
	
	// ## Obtain the currentExposure_ value, if required. Example:
	// currentExposure_ = adcConversion();
	
	// ## check ranges: use magnitudeLowerLimit_() and magnitudeUpperLimit_()
	
	return currentExposure_;
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
	
//----------------------------------------------------------------------
// Get dataFactoryAgentInstanceCorbaName property
//----------------------------------------------------------------------
const char* IcaroDasBase::dataFactoryAgentInstanceCorbaName()
{
	trace_.out("dataFactoryAgentInstanceCorbaName()\n");
	return dataFactoryAgentInstanceCorbaName_.c_str();
}

//----------------------------------------------------------------------
// Set dataFactoryAgentInstanceCorbaName property
//----------------------------------------------------------------------
void IcaroDasBase::dataFactoryAgentInstanceCorbaName(const char* new_dataFactoryAgentInstanceCorbaName)
{
	trace_.out("dataFactoryAgentInstanceCorbaName(%s)\n",new_dataFactoryAgentInstanceCorbaName);
	
	try
	{
		checkConfigurability_();
		// ## check new values before to apply the property
		
		// Change property
		dataFactoryAgentInstanceCorbaName_ = new_dataFactoryAgentInstanceCorbaName;
		
		propertyChange_("dataFactoryAgentInstanceCorbaName");
	}
	catch(GCSException& ex)
	{
		ex.addToTrace("IcaroDasBase::dataFactoryAgentInstanceCorbaName"); 
		logError_("Setting the dataFactoryAgentInstanceCorbaName property\n");
		throw;
	}
	
}

//----------------------------------------------------------------------
// Get dataFactoryManagerInstanceCorbaName property
//----------------------------------------------------------------------
const char* IcaroDasBase::dataFactoryManagerInstanceCorbaName()
{
	trace_.out("dataFactoryManagerInstanceCorbaName()\n");
	return dataFactoryManagerInstanceCorbaName_.c_str();
}

//----------------------------------------------------------------------
// Set dataFactoryManagerInstanceCorbaName property
//----------------------------------------------------------------------
void IcaroDasBase::dataFactoryManagerInstanceCorbaName(const char* new_dataFactoryManagerInstanceCorbaName)
{
	trace_.out("dataFactoryManagerInstanceCorbaName(%s)\n",new_dataFactoryManagerInstanceCorbaName);
	
	try
	{
		checkConfigurability_();
		// ## check new values before to apply the property
		
		// Change property
		dataFactoryManagerInstanceCorbaName_ = new_dataFactoryManagerInstanceCorbaName;
		
		propertyChange_("dataFactoryManagerInstanceCorbaName");
	}
	catch(GCSException& ex)
	{
		ex.addToTrace("IcaroDasBase::dataFactoryManagerInstanceCorbaName"); 
		logError_("Setting the dataFactoryManagerInstanceCorbaName property\n");
		throw;
	}
	
}

