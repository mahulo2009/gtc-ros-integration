// Copyright (c) 2020 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

// GCS Includes
#include "IcaroDasApp.h"
#include "IcaroDas.h"

// Constructor
IcaroDasApp::IcaroDasApp(char* name)
:Application(name)
{
}

// Destructor
IcaroDasApp::~IcaroDasApp()
{
}

// Create the Devices of the application
int IcaroDasApp::run(int update)  //Only for compatibility reasons with DCF Application interface class
{
	return 0;
}

int IcaroDasApp::run(int update, int corbaDebug)
{
	// Create Devices
	try
	{
		// Create Device 1
		icaroDas_  = new IcaroDas(const_cast<char *>("ICARO/IcaroDas"));

		icaroDas_->connect("orb1", corbaDebug, 2, 50, Device::INTEGRATED, update);
	}
	catch(GCSException& ex)
	{
		ex.addToTrace("IcaroDasApp:run");
		cerr << "Error creating Device for this application" << endl;
		throw;
	}
	// Start Devices (if required)
	try
	{
		icaroDas_->start();
	}
	catch(GCSException& ex)
	{
		ex.addToTrace("IcaroDasApp:run");
		cerr << "Error starting Device" << endl;
		throw;
	}
	// Init Devices (if required)
	try
	{
		icaroDas_->init();
	}
	catch(GCSException& ex)
	{
		ex.addToTrace("IcaroDasApp:run");
		cerr << "Error initialising Device" << endl;
		throw;
	}
	return(0);
}

// Delete the Devices of the family 
int IcaroDasApp::quit()
{
	try
	{

		// Delete Device 
		icaroDas_->halt();
		icaroDas_->shutdown();
		icaroDas_->disconnect();
		delete icaroDas_;
	}
	catch(GCSException& ex)
	{
		ex.addToTrace("IcaroDasApp:quit");
		cerr << ex;
	}
	return(0);
}

#ifdef VXWORKS
//---------------------------------------------------------------------------
// These functions can be called from the VxWorks shell or VxWorks scripts
//---------------------------------------------------------------------------
IcaroDasApp* _icaroDasApp_;

extern "C" void run_IcaroDasApp(int update=0, int corbaDebug=0)
{
	_icaroDasApp_ = new IcaroDasApp(const_cast<char *>("IcaroDasApp"));
	_icaroDasApp_->run(update, corbaDebug); 
}

extern "C" void quit_IcaroDasApp(void)
{
	_icaroDasApp_->quit(); 
	delete _icaroDasApp_;
}
#endif
