// Copyright (c) 2023 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

// Includes
#include "ImageDetectorConfigAgent.h"

//----------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------
ImageDetectorConfigAgent::ImageDetectorConfigAgent(ImageDetectorBase* device, const int mode, TimerEngine* timer)
: ConfigAgent(device->name(),device->className(),mode,timer),trace_(device->name())
{
	device_ = device;

	// Assign default values to properties so they never contain garbage
}

//----------------------------------------------------------------------
// Destructor
//----------------------------------------------------------------------
ImageDetectorConfigAgent::~ImageDetectorConfigAgent()
{
}

//----------------------------------------------------------------------
// applyProperties: applies the stored configuration to the Device
//----------------------------------------------------------------------
void ImageDetectorConfigAgent::applyProperties()
{
	trace_.out("ImageDetectorConfigAgent::applyProperties()");
	
	try
	{
	
		// Apply properties one by one
	}
	catch (GCSException& ex)
	{
		ex.addToTrace("ImageDetectorConfigAgent::applyProperties");
		throw;
	}
}

//----------------------------------------------------------------------
// readProperties: obtains the property values from the Device
//----------------------------------------------------------------------
int ImageDetectorConfigAgent::readProperties()
{
	trace_.out("ImageDetectorConfigAgent::readProperties()");
	
	try
	{
	
		// Read properties one by one
	}
	catch (GCSException& ex)
	{
		ex.addToTrace("ImageDetectorConfigAgent::readProperties");
		throw;
	}
	return(0);
}

//----------------------------------------------------------------------
// toConfiguration: Converts the Device properties to a Configuration
//----------------------------------------------------------------------
void ImageDetectorConfigAgent::toConfiguration(CONFIG::Configuration& c)
{
	trace_.out("ImageDetectorConfigAgent::toConfiguration()");
	
	try
	{
	
		// Let ConfigAgent base class do the common stuff
		this->ConfigAgent::toConfiguration(c);

	}
	catch (GCSException& ex)
	{
		ex.addToTrace("ImageDetectorConfigAgent::toConfiguration");
		throw;
	}
}

//----------------------------------------------------------------------
// fromConfiguration: Converts the configuration to the Device format
//----------------------------------------------------------------------
void ImageDetectorConfigAgent::fromConfiguration(const CONFIG::Configuration& c)
{
	trace_.out("ImageDetectorConfigAgent::fromConfiguration()");
	
	try
	{
	
		// Let ConfigAgent base class do the common stuff
		this->ConfigAgent::fromConfiguration(c);

	}
	catch (GCSException& ex)
	{
		ex.addToTrace("ImageDetectorConfigAgent::fromConfiguration");
		throw;
	}
}

