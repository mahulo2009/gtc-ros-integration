// Copyright (c) 2022 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

// Includes
#include <IDL_Adapters_DGT.h>

#include "IcaroDasAdapter.h"
//----------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------
IcaroDasAdapter::IcaroDasAdapter(IcaroDasBase* device)
: DeviceAdapter(device)
{
	device_=device;
}

//----------------------------------------------------------------------
// Destructor
//----------------------------------------------------------------------
IcaroDasAdapter::~IcaroDasAdapter()
{
}


//----------------------------------------------------------------------
// Device specific operations
//----------------------------------------------------------------------


//----------------------------------------------------------------------
// expose
void IcaroDasAdapter::expose()
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
// exposeFromFile
void IcaroDasAdapter::exposeFromFile(const char* filename)
{
	try
	{
		device_->exposeFromFile(filename);
	}
	catch(GCSException& ex)
	{
		throw toIDL(ex);
	}
}

//----------------------------------------------------------------------
// abortAcquisition
void IcaroDasAdapter::abortAcquisition()
{
	try
	{
		device_->abortAcquisition();
	}
	catch(GCSException& ex)
	{
		throw toIDL(ex);
	}
}

//----------------------------------------------------------------------
// setupNumberOfExposures
void IcaroDasAdapter::setupNumberOfExposures(CORBA::Long num)
{
	try
	{
		device_->setupNumberOfExposures(num);
	}
	catch(GCSException& ex)
	{
		throw toIDL(ex);
	}
}

//----------------------------------------------------------------------
// setupExposureTimeSeconds
void IcaroDasAdapter::setupExposureTimeSeconds(CORBA::Double time)
{
	try
	{
		device_->setupExposureTimeSeconds(time);
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
// Monitor ccdState
ICARODAS::CCDState IcaroDasAdapter::ccdState()
{
	int enumerated = (int)device_->ccdState();
	return (ICARODAS::CCDState)enumerated;
}
//----------------------------------------------------------------------
// Monitor exposureTimeLeft
CORBA::Double IcaroDasAdapter::exposureTimeLeft()
{
	return device_->exposureTimeLeft();
}
//----------------------------------------------------------------------
// Monitor currentExposure
CORBA::Long IcaroDasAdapter::currentExposure()
{
	return device_->currentExposure();
}

//----------------------------------------------------------------------
// Configurable attributes (device properties) 
//----------------------------------------------------------------------


//----------------------------------------------------------------------
// get dataFactoryAgentInstanceCorbaName
char* IcaroDasAdapter::dataFactoryAgentInstanceCorbaName()
{
	return CORBA::string_dup( (char*) device_->dataFactoryAgentInstanceCorbaName());
}
//-------------------------------
// set dataFactoryAgentInstanceCorbaName
void IcaroDasAdapter::dataFactoryAgentInstanceCorbaName(const char* value)
{
	try
	{
		device_->dataFactoryAgentInstanceCorbaName(value);
	}
	catch(GCSException& ex)
	{
		throw CORBA::BAD_PARAM();
	}
}

//----------------------------------------------------------------------
// get dataFactoryManagerInstanceCorbaName
char* IcaroDasAdapter::dataFactoryManagerInstanceCorbaName()
{
	return CORBA::string_dup( (char*) device_->dataFactoryManagerInstanceCorbaName());
}
//-------------------------------
// set dataFactoryManagerInstanceCorbaName
void IcaroDasAdapter::dataFactoryManagerInstanceCorbaName(const char* value)
{
	try
	{
		device_->dataFactoryManagerInstanceCorbaName(value);
	}
	catch(GCSException& ex)
	{
		throw CORBA::BAD_PARAM();
	}
}

/**************************************************************
 *                private methods                             *
 **************************************************************/

