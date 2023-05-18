// Copyright (c) 2023 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

// GCS Includes
#include "TestLCU.h"
#include "TestApplication.h"
#include "TimeService.h"
#include "ace/ACE.h"
#include <string>

// Constructor
TestLCU::TestLCU(char* name)
:LCU(name)
{
}

// Destructor
TestLCU::~TestLCU()
{
}

// Create the Devices of the lcu
int TestLCU::start(int update)  //Only for compatibility reasons with DCF LCU interface class
{
	return 0;
}

int TestLCU::start(int update, int corbaDebug)
{
	printf("-------------------------------------------------------------------------------\n");
	printf("Starting %s services...\n",name_);
	printf("-------------------------------------------------------------------------------\n");

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
		ex.addToTrace("TestLCU::start");
		ex.addToTrace("Error initialising TimeService");
		cerr << ex;
	}

	// Start your Applications and Devices here
	printf("-------------------------------------------------------------\n");
	printf("Starting %s Applications...\n",name_);
	printf("-------------------------------------------------------------\n");
	try
	{
		Test_application_ = new TestApplication(const_cast<char *>("TestApplication"));
	}
	catch(GCSException& ex)
	{
		ex.addToTrace("TestLCU::start");
		ex.addToTrace("Error creating application");
		cerr << ex;
	}
	try
	{
		Test_application_->run(update, corbaDebug);
	}
	catch(GCSException& ex)
	{
		ex.addToTrace("TestLCU::start");
		ex.addToTrace("Error running application");
		cerr << ex;
	}

	return 0;
}

// Stop services and applications
int TestLCU::stop()
{
	printf("-------------------------------------------------------------------------------\n");
	printf("Stopping %s...\n",name_);
	printf("-------------------------------------------------------------------------------\n");

	Test_application_->quit();
	delete Test_application_;

	// Stop services here
	//timeService_->fini();
	//delete timeService_;
	// ACE, DDFactory...
	return 0;
}

int main(int argc, char** argv)
{
	TestLCU* _Test_lcu_;
	int update=0;
	int corbaDebug=0;

	printf("\n-------------------------------------------------------------------------------\n");
	printf("Usage: runFilterWheel[-update] [-corbaDebug]\n");
	printf("\n-------------------------------------------------------------------------------\n");

	CommandLine::current(argc, argv);
	CommandLine cl(argc, argv);

	update = cl.getFlag("-update");
	corbaDebug = cl.getFlag("-corbaDebug");

	_Test_lcu_ = new TestLCU(const_cast<char *>("TestLCU"));
	_Test_lcu_->start(update, corbaDebug); 

	// Leave the program running
	while(true)
	{
		sleep(2);
	};
}

