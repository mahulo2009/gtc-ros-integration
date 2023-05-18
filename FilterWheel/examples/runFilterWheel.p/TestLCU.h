// Copyright (c) 2023 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

#ifndef _TestLCU_h_
#define _TestLCU_h_

// GCS Includes
#include "LCU.h"
#include "CommandLine.h"

// Forward declarations
class TestApplication;

/** Implements the LCU interface */
class TestLCU : public LCU
{

 //--------------------------------------------------
 // public section 
 //--------------------------------------------------
 public:

	/** Constructor */
	TestLCU(char* name);

	/** Destructor */
	virtual ~TestLCU();

	/** Start LCU services and applications */
	int start(int update=0); //Only for reasons of compatibility with DCF LCU interface class
	int start(int update=0, int corbaDebug=0);

	/** Stop LCU services and applications */
	int stop();


 //--------------------------------------------------
 // private section 
 //--------------------------------------------------
 private:

	TestApplication* Test_application_;
};

#endif  // _TestLCU_h_
