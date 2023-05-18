// Copyright (c) 2023 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

// Includes
#include "FilterWheelConfigAgent.h"

//----------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------
FilterWheelConfigAgent::FilterWheelConfigAgent(FilterWheelBase* device, const int mode, TimerEngine* timer)
: ConfigAgent(device->name(),device->className(),mode,timer),trace_(device->name())
{
	device_ = device;

	// Assign default values to properties so they never contain garbage
}

//----------------------------------------------------------------------
// Destructor
//----------------------------------------------------------------------
FilterWheelConfigAgent::~FilterWheelConfigAgent()
{
}

//----------------------------------------------------------------------
// applyProperties: applies the stored configuration to the Device
//----------------------------------------------------------------------
void FilterWheelConfigAgent::applyProperties()
{
	trace_.out("FilterWheelConfigAgent::applyProperties()");
	
	try
	{
	
		// Apply properties one by one
	}
	catch (GCSException& ex)
	{
		ex.addToTrace("FilterWheelConfigAgent::applyProperties");
		throw;
	}
}

//----------------------------------------------------------------------
// readProperties: obtains the property values from the Device
//----------------------------------------------------------------------
int FilterWheelConfigAgent::readProperties()
{
	trace_.out("FilterWheelConfigAgent::readProperties()");
	
	try
	{
	
		// Read properties one by one
	}
	catch (GCSException& ex)
	{
		ex.addToTrace("FilterWheelConfigAgent::readProperties");
		throw;
	}
	return(0);
}

//----------------------------------------------------------------------
// toConfiguration: Converts the Device properties to a Configuration
//----------------------------------------------------------------------
void FilterWheelConfigAgent::toConfiguration(CONFIG::Configuration& c)
{
	trace_.out("FilterWheelConfigAgent::toConfiguration()");
	
	try
	{
	
		// Let ConfigAgent base class do the common stuff
		this->ConfigAgent::toConfiguration(c);

	}
	catch (GCSException& ex)
	{
		ex.addToTrace("FilterWheelConfigAgent::toConfiguration");
		throw;
	}
}

//----------------------------------------------------------------------
// fromConfiguration: Converts the configuration to the Device format
//----------------------------------------------------------------------
void FilterWheelConfigAgent::fromConfiguration(const CONFIG::Configuration& c)
{
	trace_.out("FilterWheelConfigAgent::fromConfiguration()");
	
	try
	{
	
		// Let ConfigAgent base class do the common stuff
		this->ConfigAgent::fromConfiguration(c);

	}
	catch (GCSException& ex)
	{
		ex.addToTrace("FilterWheelConfigAgent::fromConfiguration");
		throw;
	}
}

