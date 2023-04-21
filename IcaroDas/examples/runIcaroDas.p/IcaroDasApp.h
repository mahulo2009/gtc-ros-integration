// Copyright (c) 2020 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

#ifndef _IcaroDasApp_h_
#define _IcaroDasApp_h_

// GCS Includes
#include "Application.h"

// Forward declarations
class IcaroDas;

/** This class manages a group of related Device instances */
class IcaroDasApp : public Application
{

 //--------------------------------------------------
 // public section 
 //--------------------------------------------------
 public:

	/** Constructor */
	IcaroDasApp(char* name);

	/** Destructor */
	virtual ~IcaroDasApp();

	/** Creates devices */
	int run(int update=0); //Only for compatibility reasons with DCF Application interface class
	int run(int update=0, int corbaDebug=0);

	/** Destroy devices */
	int quit();


 //--------------------------------------------------
 // private section 
 //--------------------------------------------------
 private:

	IcaroDas* icaroDas_;
};

#endif  // _IcaroDasApp_h_
