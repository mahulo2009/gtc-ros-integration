// Copyright (c) 2023 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

// Includes
#include <IDL_Adapters_DGT.h>

#include "FilterWheelAdapter.h"
//----------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------
FilterWheelAdapter::FilterWheelAdapter(FilterWheelBase* device)
: DeviceAdapter(device)
{
	device_=device;
}

//----------------------------------------------------------------------
// Destructor
//----------------------------------------------------------------------
FilterWheelAdapter::~FilterWheelAdapter()
{
}


//----------------------------------------------------------------------
// Device specific operations
//----------------------------------------------------------------------


//----------------------------------------------------------------------
// moveCommand
void FilterWheelAdapter::moveCommand(const FILTERWHEEL::Filter position)
{
	try
	{
		device_->moveCommand((FilterWheelBase::Filter)position);
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
// Monitor filterWheelFilter
FILTERWHEEL::Filter FilterWheelAdapter::filterWheelFilter()
{
	int enumerated = (int)device_->filterWheelFilter();
	return (FILTERWHEEL::Filter)enumerated;
}
//----------------------------------------------------------------------
// Monitor filterWheelMoving
CORBA::Boolean FilterWheelAdapter::filterWheelMoving()
{
	return device_->filterWheelMoving();
}

//----------------------------------------------------------------------
// Configurable attributes (device properties) 
//----------------------------------------------------------------------


/**************************************************************
 *                private methods                             *
 **************************************************************/

