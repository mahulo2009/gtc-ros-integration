// Copyright (c) 2020 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

#ifndef _IcaroDas_h_
#define _IcaroDas_h_

// Includes
#include "IcaroDasBase.h"

#include <Frame.h>
#include "FrameAgent.h"

/**
* 
*/
class IcaroDas : public IcaroDasBase
{
 //--------------------------------------------------
 // public section 
 //--------------------------------------------------
 public:

	//####################### CONSTRUCTOR & DESTRUCTOR #####################
	
	/** Device Constructor */
	IcaroDas(string name);

	/** Destructor */
	virtual ~IcaroDas();

	//########################## DEVICE METHODS ############################
	
	/** Connects the device with a CORBA and other GCS Services*/
	void  connect(string orbname, bool corbaDebug, unsigned threads,long priority,
	              bool mode  =Device::INTEGRATED,
	              bool update=Device::DO_NOT_UPDATE);
	
	/** Starting procedure */
	void  start();
	
	/** Initialization procedure */
	void  init();
	
	/** Halting procedure */
	void  halt();
	
	/** Shutdown procedure */
	void  shutdown();
	
	/** Reset procedure */
	void  reset();
	
	/** Test procedure */
	void  test();
	
	/** Stops all commands and goes to fault */
	void  abort();
	
	/** Report device info */
	char* report(double level);
	
	//####################### SPECIFIC METHODS #############################

	/**
	* Expose
	*/
	void expose();

	/**
	* Expose
	*/
	void exposeFromFile(const char* filename);

	/**
	* Abort Acquisition
	*/
	void abortAcquisition();

	/**
	* Setup number of exposures
	*/
	void setupNumberOfExposures(long num);

	/**
	* Setup exposure time in seconds
	*/
	void setupExposureTimeSeconds(double time);
	

 //-----------------------------------------------------------------
 // protected section 
 //-----------------------------------------------------------------
 protected:

 	double numberOfExposures_;
	double exposureTimeSeconds_;
	bool abortAcquisition_;
	ShortArray2D windows_;

 private:

	FrameAgent frameAgent_;

	void expose_();
	void buildFrame_(Frame<double,2> & frame);

};

#endif // _IcaroDas_h_ 

