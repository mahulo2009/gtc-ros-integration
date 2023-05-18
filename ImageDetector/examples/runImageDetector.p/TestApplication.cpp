// Copyright (c) 2023 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

// GCS Includes
#include "TestApplication.h"
#include "ImageDetector.h"

// Constructor
TestApplication::TestApplication(char* name)
:Application(name)
{
}

// Destructor
TestApplication::~TestApplication()
{
}

// Create the Devices of the application
int TestApplication::run(int update)  //Only for compatibility reasons with DCF Application interface class
{
	return 0;
}

int TestApplication::run(int update, int corbaDebug)
{
	// Create Devices
	try
	{
		// Create Device 1
		ImageDetector_1_  = new ImageDetector(const_cast<char *>("Osiris/ImageDetector_1"));

		ImageDetector_1_->connect("orb1", corbaDebug, 4, 100, Device::INTEGRATED, update);
	}
	catch(GCSException& ex)
	{
		ex.addToTrace("TestApplication:run");
		cerr << "Error creating Device for this application" << endl;
		throw;
	}
	// Start Devices (if required)
	try
	{
		ImageDetector_1_->start();
	}
	catch(GCSException& ex)
	{
		ex.addToTrace("TestApplication:run");
		cerr << "Error starting Device" << endl;
		throw;
	}
	// Init Devices (if required)
	try
	{
		ImageDetector_1_->init();
	}
	catch(GCSException& ex)
	{
		ex.addToTrace("TestApplication:run");
		cerr << "Error initialising Device" << endl;
		throw;
	}
	return(0);
}

// Delete the Devices of the family 
int TestApplication::quit()
{
	try
	{

		// Delete Device 
		ImageDetector_1_->halt();
		ImageDetector_1_->shutdown();
		ImageDetector_1_->disconnect();
		delete ImageDetector_1_;
	}
	catch(GCSException& ex)
	{
		ex.addToTrace("TestApplication:quit");
		cerr << ex;
	}
	return(0);
}

