// Copyright (c) 2023 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

#ifndef _FilterWheelAdapter_h_
#define _FilterWheelAdapter_h_

// Includes
#include <DeviceAdapter.h>
#include "FILTERWHEELS.h"
#include "FilterWheelBase.h"

class FilterWheel;

//This class implements the IDL interface FilterWheel_ifce
class FilterWheelAdapter : public virtual POA_FILTERWHEEL::FilterWheel_ifce,  public DeviceAdapter
{

 //--------------------------------------------------
 // public section 
 //--------------------------------------------------
 public:

	// Constructor
	FilterWheelAdapter(FilterWheelBase* device);

	// Destructor
	~FilterWheelAdapter();


	//----------------------------------------------------------------------
	// Device specific operations
	//----------------------------------------------------------------------
	void   moveCommand(CORBA::Short position);

	//----------------------------------------------------------------------
	// Monitorable attributes (device magnitudes) 
	//----------------------------------------------------------------------
	CORBA::Short   filterWheelFilter();
	CORBA::Boolean filterWheelMoving();

	//----------------------------------------------------------------------
	// Configurable attributes (device properties) 
	//----------------------------------------------------------------------


	//--------------------------------------------------
	// private section 
	//--------------------------------------------------
	private:

	FilterWheelBase* device_;
};

#endif // _FilterWheelAdapter_h_ 

