// Copyright (c) 2022 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

#ifndef _IcaroDasConfigAgent_h_
#define _IcaroDasConfigAgent_h_

// Includes
#include "IcaroDasBase.h"
#include "Trace.h"
#include "ConfigAgent.h"

class IcaroDas;

// Class used to configure IcaroDasConfigAgent objects
class IcaroDasConfigAgent : public ConfigAgent
{

 //--------------------------------------------------
 // public section 
 //--------------------------------------------------
 public:

	// Constructor
	IcaroDasConfigAgent(IcaroDasBase* device, const int mode, TimerEngine* timer);

	// Destructor
	virtual ~IcaroDasConfigAgent();

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

	IcaroDasBase* device_;
	
	//
	// Configurable attributes (properties)
	//
	String dataFactoryAgentInstanceCorbaName_ ; 
	String dataFactoryManagerInstanceCorbaName_ ; 
};

#endif // _IcaroDasConfigAgent_h_ 

