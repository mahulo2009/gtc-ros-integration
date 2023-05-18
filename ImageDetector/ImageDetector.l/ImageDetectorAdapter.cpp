// Copyright (c) 2023 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

// Includes
#include <IDL_Adapters_DGT.h>

#include "ImageDetectorAdapter.h"
//----------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------
ImageDetectorAdapter::ImageDetectorAdapter(ImageDetectorBase* device)
: DeviceAdapter(device)
{
	device_=device;
}

//----------------------------------------------------------------------
// Destructor
//----------------------------------------------------------------------
ImageDetectorAdapter::~ImageDetectorAdapter()
{
}


//----------------------------------------------------------------------
// Device specific operations
//----------------------------------------------------------------------


//----------------------------------------------------------------------
// expose
void ImageDetectorAdapter::expose()
{
	try
	{
		device_->expose();
	}
	catch(GCSException& ex)
	{
		throw toIDL(ex);
	}
}

//----------------------------------------------------------------------
// setExposureTimeSeconds
void ImageDetectorAdapter::setExposureTimeSeconds(CORBA::Double time)
{
	try
	{
		device_->setExposureTimeSeconds(time);
	}
	catch(GCSException& ex)
	{
		throw toIDL(ex);
	}
}

//----------------------------------------------------------------------
// Monitorable attributes (device magnitudes) 
//----------------------------------------------------------------------
//----------------------------------------------------------------------
// Monitor idExposing
CORBA::Boolean ImageDetectorAdapter::idExposing()
{
	return device_->idExposing();
}
//----------------------------------------------------------------------
// Monitor idExposureTimeLeft
CORBA::Boolean ImageDetectorAdapter::idExposureTimeLeft()
{
	return device_->idExposureTimeLeft();
}

//----------------------------------------------------------------------
// Configurable attributes (device properties) 
//----------------------------------------------------------------------


/**************************************************************
 *                private methods                             *
 **************************************************************/

