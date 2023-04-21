// Copyright (c) 2022 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

// Includes
#include "testIcaroDas.h"
#include "ConcreteArrays.h"

int main(int argc, char** argv)
{
	IcaroDas *device;
	bool quit=false;
	int option;
	int result=0;

	// Init ACE
	ACE::init();

	char* devicename;
	int updateProfile=0;
	int corbaDebug=0;
	int mode=0;
	long priority=128;
	unsigned threads=4;
	CommandLine::current(argc, argv);
	CommandLine cl(argc, argv);
	updateProfile = cl.getFlag("-update");
	corbaDebug = cl.getFlag("-corbaDebug");
	mode = cl.getFlag("-integrated");
	priority = atoi(cl.getOption("-p", "128"));
	threads = atoi(cl.getOption("-t", "4"));
	devicename = cl.getOption("-name", "Test/IcaroDas_1");

	// Start test
	printf("---------------------------------------------------------------------\n");
	printf("MyDevice TEST: \n");
	printf("Instance = %s\n",devicename);
	if(mode==1)
	{
		printf("Mode     = INTEGRATED  ");
		if(updateProfile) printf("*** Update profile requested");
	}
	else if(mode==0) 
	{
		printf("Mode     = STANDALONE  ");
		if(updateProfile) printf("*** Update option ignored in this mode");
		updateProfile=0;
	}
	printf("\n");
	printf("Priority = %ld \n",priority);
	printf("Threads  = %d \n",threads);

	helpShow();
	
	do
	{
		//taskDelay(20);
		printf("IcaroDas-> ");
		scanf("%d", &option);
		switch(option)
		{
		case 0: // Help
			helpShow();
			break;

		case 1: // Create new device
			try
			{
				device = new IcaroDas(devicename);
				device->connect("orb",corbaDebug,threads,priority,mode,updateProfile);
			}
			catch(GCSException& ex)
			{
				ex.addToTrace("testIcaroDas::constructor");
				cerr << ex;
				result = 1;
				quit   = true;
			}
			break;

		case 2: // Start
			try
			{
				device->start();
			}
			catch(GCSException& ex)
			{
				ex.addToTrace("testIcaroDas::start");
				cerr << ex;
			}
			break;

		case 3: // Init
			try
			{
				device->init();
			}
			catch(GCSException& ex)
			{
				ex.addToTrace("testIcaroDas::init");
				cerr << ex;
			}
			break;

		case 4: // State
			try
			{
				if(device!=NULL) cerr << "State = " << device->state();
				else cerr << "Device is not created" << endl;
			}
			catch(GCSException& ex)
			{
				ex.addToTrace("testIcaroDas::state");
				cerr << ex;
			}
			break;

		case 5: // Report
			try
			{
				cerr << device->report(0);
			}
			catch(GCSException& ex)
			{
				ex.addToTrace("testIcaroDas::report");
				cerr << ex;
			}
			break;

		case 6: // Enable/disable
			try
			{
				if(device->isDisabled()) device->enable();
				else device->disable();
			}
			catch(GCSException& ex)
			{
				ex.addToTrace("testIcaroDas::enable/disable");
				cerr << ex;
			}
			break;

		case 7: // Halt
			try
			{
				device->halt();
			}
			catch(GCSException& ex)
			{
				ex.addToTrace("testIcaroDas::halt");
				cerr << ex;
			}
			break;

		case 8: // Shutdown
			try
			{
				device->shutdown();
			}
			catch(GCSException& ex)
			{
				ex.addToTrace("testIcaroDas::shutdown");
				cerr << ex;
			}
			break;

		case 9: // Destroy
			try
			{
				if (device!=NULL)
				{
					device->disconnect();
					delete device;
					device=NULL;
				}
			}
			catch(GCSException& ex )
			{
				ex.addToTrace("testIcaroDas::destructor");
				cerr << ex;
			}
			break;

		case 10: // Call specific methods
			try
			{
				if (device!=NULL)
				{
					//## call specific methods of your device
					cerr << "Add your tests here" << endl;
				}
			}
			catch(GCSException& ex )
			{
				ex.addToTrace("testIcaroDas::specific methods");
				cerr << ex;
			}
			break;

		case 99: // Quit program
			quit = true;
			break;

		default:
			cerr << "Unknown option" << endl;
			break;

		}
		printf("\n");
	} while(quit == false);
	cerr << "Bye" << endl;
	return(result);  // On error return 1; On success return 0
}


void helpShow(void)
{
	printf("\n");
	printf("--------Select Option------------------------------------\n");
	printf("|                           |                           |\n");
	printf("| 0- Show this menu         | 10- Specific methods      |\n");
	printf("| 1- Create device          |                           |\n");
	printf("| 2- Start device           |                           |\n");
	printf("| 3- Init device            |                           |\n");
	printf("| 4- Get device state       |                           |\n");
	printf("| 5- Report device          |                           |\n");
	printf("| 6- Enable/Disable device  |                           |\n");
	printf("| 7- Halt device            |                           |\n");
	printf("| 8- Shutdown device        |                           |\n");
	printf("| 9- Destroy device         | 99- Quit Test Program     |\n");
	printf("|                           |                           |\n");
	printf("---------------------------------------------------------\n");
}
