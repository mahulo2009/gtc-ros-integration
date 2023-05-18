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
void FilterWheelAdapter::moveCommand(CORBA::Short position)
{
	try
	{
		device_->moveCommand(position);
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
CORBA::Short FilterWheelAdapter::filterWheelFilter()
{
	return device_->filterWheelFilter();
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

