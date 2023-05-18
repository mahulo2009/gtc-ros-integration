// Copyright (c) 2023 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

#ifndef _TestApplication_h_
#define _TestApplication_h_

// GCS Includes
#include "Application.h"

// Forward declarations
class ImageDetector;

/** This class manages a group of related Device instances */
class TestApplication : public Application
{

 //--------------------------------------------------
 // public section 
 //--------------------------------------------------
 public:

	/** Constructor */
	TestApplication(char* name);

	/** Destructor */
	virtual ~TestApplication();

	/** Creates devices */
	int run(int update=0); //Only for compatibility reasons with DCF Application interface class
	int run(int update=0, int corbaDebug=0);

	/** Destroy devices */
	int quit();


 //--------------------------------------------------
 // private section 
 //--------------------------------------------------
 private:

	ImageDetector* ImageDetector_1_;
};

#endif  // _TestApplication_h_
