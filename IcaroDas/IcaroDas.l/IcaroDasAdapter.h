// Copyright (c) 2022 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

#ifndef _IcaroDasAdapter_h_
#define _IcaroDasAdapter_h_

// Includes
#include <DeviceAdapter.h>
#include "ICARODASS.h"
#include "IcaroDasBase.h"

class IcaroDas;

//This class implements the IDL interface IcaroDas_ifce
class IcaroDasAdapter : public virtual POA_ICARODAS::IcaroDas_ifce,  public DeviceAdapter
{

 //--------------------------------------------------
 // public section 
 //--------------------------------------------------
 public:

	// Constructor
	IcaroDasAdapter(IcaroDasBase* device);

	// Destructor
	~IcaroDasAdapter();


	//----------------------------------------------------------------------
	// Device specific operations
	//----------------------------------------------------------------------
	void   expose                  ();
	void   exposeFromFile          (const char* filename);
	void   abortAcquisition        ();
	void   setupNumberOfExposures  (CORBA::Long num);
	void   setupExposureTimeSeconds(CORBA::Double time);

	//----------------------------------------------------------------------
	// Monitorable attributes (device magnitudes) 
	//----------------------------------------------------------------------
	ICARODAS::CCDState ccdState        ();
	CORBA::Double      exposureTimeLeft();
	CORBA::Long        currentExposure ();

	//----------------------------------------------------------------------
	// Configurable attributes (device properties) 
	//----------------------------------------------------------------------
	char* dataFactoryAgentInstanceCorbaName  ();
	void  dataFactoryAgentInstanceCorbaName  (const char* value); 
	char* dataFactoryManagerInstanceCorbaName();
	void  dataFactoryManagerInstanceCorbaName(const char* value); 


 //-----------------------------------------------------------------
 // protected section 
 //-----------------------------------------------------------------
 protected:

	//--------------------------------------------------
	// private section 
	//--------------------------------------------------
	private:

	IcaroDasBase* device_;
};

#endif // _IcaroDasAdapter_h_ 

