// Copyright (c) 2020 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

// GCS Includes
#include "IcaroDasLCU.h"
#include "IcaroDasApp.h"
#include "TimeService.h"
#include "ace/ACE.h"
#ifdef VXWORKS
#include "DDFactory.h"
#endif
#include <string>

// Constructor
IcaroDasLCU::IcaroDasLCU(char* name)
:LCU(name)
{
}

// Destructor
IcaroDasLCU::~IcaroDasLCU()
{
}

// Create the Devices of the lcu
int IcaroDasLCU::start(int update)  //Only for compatibility reasons with DCF LCU interface class
{
	return 0;
}

int IcaroDasLCU::start(int update, int corbaDebug)
{
	printf("-------------------------------------------------------------------------------\n");
	printf("Starting %s services...\n",name_);
	printf("-------------------------------------------------------------------------------\n");
#ifdef VXWORKS
	try
	{
		driverFactory_ = DDFactory::instance();
	}
	catch(GCSException& ex)
	{
		ex.addToTrace("IcaroDasLCU::start");
		ex.addToTrace("Error initialising DDFactory");
		cerr << ex;
	}
	cerr << driverFactory_->report();
#endif

	//-------------------
	// Start ACE services
	//-------------------
	ACE::init();

	//---------------------------------------
	// Initialising Time Service for this LCU
	//---------------------------------------
	try
	{
		timeService_ = TimeService::instance();
	}
	catch(GCSException& ex)
	{
		ex.addToTrace("IcaroDasLCU::start");
		ex.addToTrace("Error initialising TimeService");
		cerr << ex;
	}

	// Start your Applications and Devices here
	printf("-------------------------------------------------------------\n");
	printf("Starting %s Applications...\n",name_);
	printf("-------------------------------------------------------------\n");
	try
	{
		icaroDasApp_ = new IcaroDasApp(const_cast<char *>("IcaroDasApp"));
	}
	catch(GCSException& ex)
	{
		ex.addToTrace("IcaroDasLCU::start");
		ex.addToTrace("Error creating application");
		cerr << ex;
	}
	try
	{
		icaroDasApp_->run(update, corbaDebug);
	}
	catch(GCSException& ex)
	{
		ex.addToTrace("IcaroDasLCU::start");
		ex.addToTrace("Error running application");
		cerr << ex;
	}

	return 0;
}

// Stop services and applications
int IcaroDasLCU::stop()
{
	printf("-------------------------------------------------------------------------------\n");
	printf("Stopping %s...\n",name_);
	printf("-------------------------------------------------------------------------------\n");

	icaroDasApp_->quit();
	delete icaroDasApp_;

	// Stop services here
	//timeService_->fini();
	//delete timeService_;
	// ACE, DDFactory...
	return 0;
}

#ifdef VXWORKS
//---------------------------------------------------------------------------
// These functions can be called from the VxWorks shell or VxWorks scripts
//---------------------------------------------------------------------------
IcaroDasLCU* _icaroDasLCU_;

extern "C" void start_LCU(int update=0, int corbaDebug=0)
{
	_icaroDasLCU_ = new IcaroDasLCU(const_cast<char *>("IcaroDasLCU"));
	_icaroDasLCU_->start(update, corbaDebug); 
}

extern "C" void stop_LCU()
{
	_icaroDasLCU_->stop(); 
	delete _icaroDasLCU_;
}

extern "C" void reboot_LCU()
{
	_icaroDasLCU_->reBoot(); 
}
#else
int main(int argc, char** argv)
{
	IcaroDasLCU* _icaroDasLCU_;
	int update=0;
	int corbaDebug=0;

	printf("\n-------------------------------------------------------------------------------\n");
	printf("Usage: runIcaroDas[-update] [-corbaDebug]\n");
	printf("\n-------------------------------------------------------------------------------\n");

	CommandLine::current(argc, argv);
	CommandLine cl(argc, argv);

	update = cl.getFlag("-update");
	corbaDebug = cl.getFlag("-corbaDebug");

	_icaroDasLCU_ = new IcaroDasLCU(const_cast<char *>("IcaroDasLCU"));
	_icaroDasLCU_->start(update, corbaDebug); 

	// Leave the program running
	while(true)
	{
		sleep(2);
	};
}
#endif

