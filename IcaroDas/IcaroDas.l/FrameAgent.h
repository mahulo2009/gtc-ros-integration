// Copyright (c) 2020 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

#ifndef _FrameAgent_h_
#define _FrameAgent_h_

// Includes
#include <Trace.h>
#include <AlarmAgent.h>
#include <LogAgent.h>
#include <IntegratedCORBAConnector.h>
#include <DFAGENTC.h>
#include <DFManagerC.h>
#include <cfitsio/fitsio.h>
#include <Frame.h>
#include <ConcreteArrays.h>

/**
* 
*/
class FrameAgent
{
 //--------------------------------------------------
 // public section 
 //--------------------------------------------------
 public:

	//####################### CONSTRUCTOR & DESTRUCTOR #####################
	
	/** Device Constructor */
	FrameAgent(string name, string dfAgentName);

	/** Destructor */
	virtual ~FrameAgent();

	
	/** Connects the DF components - DFAgent and DFManager */
	void  connect(LogAgent *logAgent, AlarmAgent * alarmAgent, std::string dataFactoryAgentInstanceCorbaName, std::string dataFactoryManagerInstanceCorbaName);
	
	/** Disconnects the DF components - DFAgent and DFManager */
	void  disconnect();
	
	/**
	* sendFrame
	*/
	void sendFrame(const Frame<double,2> & frame, double exposureTimeSeconds, ShortArray2D windows);

	/**
	* sendFitsFile
	*/
	void sendFitsFile(string fitsFilename, double exposureTimeSeconds, ShortArray2D windows);

 private:

	std::string										name_;
	IntegratedCORBAConnector<DFAGENT::DFAgent_ifce>	dfAgentConnector_;
	IntegratedCORBAConnector<DF::Manager_ifce>		dfManagerConnector_;
	Trace											trace_;
};

#endif // _FrameAgent_h_ 

