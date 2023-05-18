// Copyright (c) 2023 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

#ifndef _FilterWheelConfigAgent_h_
#define _FilterWheelConfigAgent_h_

// Includes
#include "FilterWheelBase.h"
#include "Trace.h"
#include "ConfigAgent.h"

class FilterWheel;

// Class used to configure FilterWheelConfigAgent objects
class FilterWheelConfigAgent : public ConfigAgent
{

 //--------------------------------------------------
 // public section 
 //--------------------------------------------------
 public:

	// Constructor
	FilterWheelConfigAgent(FilterWheelBase* device, const int mode, TimerEngine* timer);

	// Destructor
	virtual ~FilterWheelConfigAgent();

	// This method applies the stored configuration to the Device
	void applyProperties();
	
	// This method obtains the properties from the Device
	int readProperties();
	
	// Converts the Device properties to a Configuration
	void toConfiguration(CONFIG::Configuration& c);
	
	// Converts a Configuration to the Device format
	void fromConfiguration(const CONFIG::Configuration& c);
	

 //-----------------------------------------------------------------
 // protected section 
 //-----------------------------------------------------------------
 protected:
	
	Trace trace_;
	
	

 //--------------------------------------------------
 // private section 
 //--------------------------------------------------
 private:

	FilterWheelBase* device_;
};

#endif // _FilterWheelConfigAgent_h_ 

