// Copyright (c) 2023 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

#ifndef _ImageDetectorConfigAgent_h_
#define _ImageDetectorConfigAgent_h_

// Includes
#include "ImageDetectorBase.h"
#include "Trace.h"
#include "ConfigAgent.h"

class ImageDetector;

// Class used to configure ImageDetectorConfigAgent objects
class ImageDetectorConfigAgent : public ConfigAgent
{

 //--------------------------------------------------
 // public section 
 //--------------------------------------------------
 public:

	// Constructor
	ImageDetectorConfigAgent(ImageDetectorBase* device, const int mode, TimerEngine* timer);

	// Destructor
	virtual ~ImageDetectorConfigAgent();

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

	ImageDetectorBase* device_;
};

#endif // _ImageDetectorConfigAgent_h_ 

