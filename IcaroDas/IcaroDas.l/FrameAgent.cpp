// Copyright (c) 2020 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

// Includes
#include "FrameAgent.h"
#include "Task.h"
#include "IDL_Adapters_DGT.h"
#include "IDL_Adapters_DPKF.h"
#include "AddNoise.h"
#include "AddStar.h"
#include "RectangularShape.h"
#include "Roi.h"

//----------------------------------------------------------------------
// Device Constructor
//----------------------------------------------------------------------
FrameAgent::FrameAgent(string name, string dfAgentName)
:	name_(name),
	trace_(name),
	dfAgentConnector_(dfAgentName, "DFAgentUnreachable"),
	dfManagerConnector_("DFManager", "DFManagerUnreachable")
{
	trace_.out("FrameAgent constructor\n");
}

//----------------------------------------------------------------------
// Device destructor
//----------------------------------------------------------------------
FrameAgent::~FrameAgent()
{
  trace_.out("destructor\n");
}

//----------------------------------------------------------------------
// Performs connection procedure
//----------------------------------------------------------------------
void FrameAgent::connect(LogAgent *logAgent, AlarmAgent * alarmAgent, std::string dataFactoryAgentInstanceCorbaName, std::string dataFactoryManagerInstanceCorbaName)
{
	trace_.out("connect()\n");
	
	try
	{
		dfManagerConnector_.componentInterfaceName("DF::Manager_ifce");
		dfManagerConnector_.timeout(TimeValue(60,0), 1);
	   	dfManagerConnector_.changeComponentCorbaName(dataFactoryManagerInstanceCorbaName);
		dfManagerConnector_.initAgents(alarmAgent, logAgent);
		dfManagerConnector_.doubleCheckingPolicy(true);
	   	dfManagerConnector_.isEnabled(1);  /* DFManager Enabled to send Frames and Fistsfiles */
		
		dfAgentConnector_.componentInterfaceName("ICARODFAGENT::ICARODFAgent_ifce");
		dfAgentConnector_.timeout(TimeValue(60,0), 1);
	   	dfAgentConnector_.changeComponentCorbaName(dataFactoryAgentInstanceCorbaName);
		dfAgentConnector_.initAgents(alarmAgent, logAgent);
		dfAgentConnector_.doubleCheckingPolicy(true);
	   	dfAgentConnector_.isEnabled(0);  /* DFAgent Disabled, because this example don't work with the full DataFactory Reduction Pieline */
	
		if (dfManagerConnector_.isEnabled())
	    {
			trace_.out("Connecting to %s", dfManagerConnector_.componentCorbaName().c_str());
			dfManagerConnector_.connect();
        }

		if (dfAgentConnector_.isEnabled())
	    {
			trace_.out("Connecting to %s", dfAgentConnector_.componentCorbaName().c_str());
			dfAgentConnector_.connect();
        }	

		trace_.out("FrameAgent READY!!!");
	}
	catch(GCSException& ex)
	{
		ex.addToTrace("FrameAgent::init()"); 
		trace_.err("FrameAgent::init() exception - %s\n", ex.toString());
		throw;
	}
}


//----------------------------------------------------------------------
// Performs disconnect procedure
//----------------------------------------------------------------------
void FrameAgent::disconnect()
{
	trace_.out("disconnect()\n");
	
	try
	{		
		// ## disconnect procedure

		if (dfAgentConnector_.isEnabled() && dfAgentConnector_.isConnected())
	    {
			trace_.out("Disconnecting to %s", dfAgentConnector_.componentCorbaName().c_str());

			dfAgentConnector_.disconnect();
        }
		
		if (dfManagerConnector_.isEnabled() && dfManagerConnector_.isConnected())
	    {
			trace_.out("Disconnecting to %s", dfManagerConnector_.componentCorbaName().c_str());

			dfManagerConnector_.disconnect();
        }
	}
	catch(GCSException& ex)
	{
		ex.addToTrace("FrameAgent::disconnect()"); 
		trace_.err("FrameAgent::disconnect() exception - %s\n", ex.toString());
		throw;
	}
}

void FrameAgent::sendFrame(const Frame<double,2> & frame, double exposureTimeSeconds, ShortArray2D windows)
{
	DDPKF::Frame idlFrame;
	DGT::TinyVector idlTopLeft, idlBottomRight;
	TimeValue timestamp = TimeService::getTAI();

	trace_.out("sendFrame()\n");

	try
	{
		if (dfManagerConnector_.isEnabled() || dfAgentConnector_.isEnabled()) 
		{
			/* Convert C++ objects to CORBA objects */

			toIDL (frame, idlFrame);
			toIDL (TinyVector<unsigned long,2>((windows)[0][0],(windows)[0][1]), idlTopLeft);
			toIDL (TinyVector<unsigned long,2>((windows)[0][2],(windows)[0][3]), idlBottomRight);
		}


		if (dfManagerConnector_.isEnabled()) 
		{
			/* Get CORBA reference */
			DF::Manager_ifce_var dfManagerRef = dfManagerConnector_.getComponentCorbaReference(1);

			/* Send frame to DFManager */
			dfManagerRef->receiveAcquiredFrame ("ICARO", "ICARO", "image", "", "image", "", idlFrame,
												0,
												0,
												idlTopLeft,
												idlBottomRight,
												toIDL(timestamp),
												toIDL(TimeValue(exposureTimeSeconds)),
												true, true, true);
		}

		if (dfAgentConnector_.isEnabled()) 
		{

			/* Get CORBA reference */
			DFAGENT::DFAgent_ifce_var dfAgentRef = dfAgentConnector_.getComponentCorbaReference(1);

			/* Send frame to DFAgent */
			dfAgentRef->setObservationMode("image");
			dfAgentRef->receiveFrame (idlFrame,
										0,
										0,
										idlTopLeft,
										idlBottomRight,
										toIDL(timestamp),
										toIDL(TimeValue(exposureTimeSeconds)),
										name_.c_str());
		}
	}
	catch (const CORBA::Exception &ex) 
	{
		GCSException gcsex = DException::mapCORBAException(const_cast<CORBA::Exception&>(ex));
    	cout << "ERROR: " << gcsex << endl;
    }
	catch(GCSException& ex)
	{
		ex.addToTrace("FrameAgent::sendFrame_()");
		trace_.err("FrameAgent::sendFrame_() exception - %s\n", ex.toString());
		throw;
	}
}


void FrameAgent::sendFitsFile(string fitsFilename, double exposureTimeSeconds, ShortArray2D windows)
{
	fitsfile *fptr=NULL;
	int status = 0, retval;

	trace_.out("sendFitsFile()\n");
	
	try
	{
		if(! fitsFilename.empty())
		{
			if (dfManagerConnector_.isEnabled() || dfAgentConnector_.isEnabled()) 
			{
				/* Create frame from the fits file */			
				Frame<double,2> frame ( fitsFilename );
				/* Send frame */
				sendFrame(frame, exposureTimeSeconds, windows);
			}
		}
	}
	catch (const CORBA::Exception &ex) 
	{
		GCSException gcsex = DException::mapCORBAException(const_cast<CORBA::Exception&>(ex));
    	cout << "ERROR: " << gcsex << endl;
    }
	catch(GCSException& ex)
	{
		ex.addToTrace("FrameAgent::sendFitsFile_()");
		trace_.err("FrameAgent::sendFitsFile_() exception - %s\n", ex.toString());
		throw;
	}
}
