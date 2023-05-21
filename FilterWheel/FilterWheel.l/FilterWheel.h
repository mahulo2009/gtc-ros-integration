// Copyright (c) 2023 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

#ifndef _FilterWheel_h_
#define _FilterWheel_h_

// Includes
#include "FilterWheelBase.h"

/**
* 
*/
class FilterWheel : public FilterWheelBase
{
 //--------------------------------------------------
 // public section 
 //--------------------------------------------------
 public:

	//####################### CONSTRUCTOR & DESTRUCTOR #####################
	
	/** Device Constructor */
	FilterWheel(string name);

	/** Destructor */
	virtual ~FilterWheel();

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
	char* report(short level);
	
	//####################### SPECIFIC METHODS #############################

	/**
	* void command
	*/
	void moveCommand(FilterWheelBase::Filter position);
	

 //-----------------------------------------------------------------
 // protected section 
 //-----------------------------------------------------------------
 protected:
};

#endif // _FilterWheel_h_ 

