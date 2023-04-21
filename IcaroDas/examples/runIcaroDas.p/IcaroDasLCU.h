// Copyright (c) 2020 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

#ifndef _IcaroDasLCU_h_
#define _IcaroDasLCU_h_

// GCS Includes
#include "LCU.h"
#include "CommandLine.h"

// Forward declarations
class IcaroDasApp;

/** Implements the LCU interface */
class IcaroDasLCU : public LCU
{

 //--------------------------------------------------
 // public section 
 //--------------------------------------------------
 public:

	/** Constructor */
	IcaroDasLCU(char* name);

	/** Destructor */
	virtual ~IcaroDasLCU();

	/** Start LCU services and applications */
	int start(int update=0); //Only for reasons of compatibility with DCF LCU interface class
	int start(int update=0, int corbaDebug=0);

	/** Stop LCU services and applications */
	int stop();


 //--------------------------------------------------
 // private section 
 //--------------------------------------------------
 private:

	IcaroDasApp* icaroDasApp_;
};

#endif  // _IcaroDasLCU_h_
