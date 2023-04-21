// Copyright (c) 2022 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

// Includes
#include "IcaroDasConfigAgent.h"

//----------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------
IcaroDasConfigAgent::IcaroDasConfigAgent(IcaroDasBase* device, const int mode, TimerEngine* timer)
: ConfigAgent(device->name(),device->className(),mode,timer),trace_(device->name())
{
	device_ = device;

	// Assign default values to properties so they never contain garbage
	dataFactoryAgentInstanceCorbaName_   = "ICARODFAgent";
	dataFactoryManagerInstanceCorbaName_ = "ICARODFAgent";
}

//----------------------------------------------------------------------
// Destructor
//----------------------------------------------------------------------
IcaroDasConfigAgent::~IcaroDasConfigAgent()
{
}

//----------------------------------------------------------------------
// applyProperties: applies the stored configuration to the Device
//----------------------------------------------------------------------
void IcaroDasConfigAgent::applyProperties()
{
	trace_.out("IcaroDasConfigAgent::applyProperties()");
	
	try
	{
	
		// Apply properties one by one
		device_->dataFactoryAgentInstanceCorbaName(this->dataFactoryAgentInstanceCorbaName_);
		device_->dataFactoryManagerInstanceCorbaName(this->dataFactoryManagerInstanceCorbaName_);
	}
	catch (GCSException& ex)
	{
		ex.addToTrace("IcaroDasConfigAgent::applyProperties");
		throw;
	}
}

//----------------------------------------------------------------------
// readProperties: obtains the property values from the Device
//----------------------------------------------------------------------
int IcaroDasConfigAgent::readProperties()
{
	trace_.out("IcaroDasConfigAgent::readProperties()");
	
	try
	{
	
		// Read properties one by one
		this->dataFactoryAgentInstanceCorbaName_  = device_->dataFactoryAgentInstanceCorbaName();
		this->dataFactoryManagerInstanceCorbaName_  = device_->dataFactoryManagerInstanceCorbaName();
	}
	catch (GCSException& ex)
	{
		ex.addToTrace("IcaroDasConfigAgent::readProperties");
		throw;
	}
	return(0);
}

//----------------------------------------------------------------------
// toConfiguration: Converts the Device properties to a Configuration
//----------------------------------------------------------------------
void IcaroDasConfigAgent::toConfiguration(CONFIG::Configuration& c)
{
	trace_.out("IcaroDasConfigAgent::toConfiguration()");
	
	try
	{
	
		// Let ConfigAgent base class do the common stuff
		this->ConfigAgent::toConfiguration(c);

		addProperty(c, "dataFactoryAgentInstanceCorbaName", dataFactoryAgentInstanceCorbaName_);
		addProperty(c, "dataFactoryManagerInstanceCorbaName", dataFactoryManagerInstanceCorbaName_);
	}
	catch (GCSException& ex)
	{
		ex.addToTrace("IcaroDasConfigAgent::toConfiguration");
		throw;
	}
}

//----------------------------------------------------------------------
// fromConfiguration: Converts the configuration to the Device format
//----------------------------------------------------------------------
void IcaroDasConfigAgent::fromConfiguration(const CONFIG::Configuration& c)
{
	trace_.out("IcaroDasConfigAgent::fromConfiguration()");
	
	try
	{
	
		// Let ConfigAgent base class do the common stuff
		this->ConfigAgent::fromConfiguration(c);

		extractProperty(c, "dataFactoryAgentInstanceCorbaName", dataFactoryAgentInstanceCorbaName_);
		extractProperty(c, "dataFactoryManagerInstanceCorbaName", dataFactoryManagerInstanceCorbaName_);
	}
	catch (GCSException& ex)
	{
		ex.addToTrace("IcaroDasConfigAgent::fromConfiguration");
		throw;
	}
}

