// Copyright (c) 2023 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

#ifndef _FilterWheelBase_h_
#define _FilterWheelBase_h_

// Includes
#include <Device.h>
#include <ConcreteArrays.h>

/**
* This class is automaticaly regenerated when devBuilder-gev is invoked,
* and therefore it should not be edited by the developer.
*/
class FilterWheelBase : public Device
{
//-----------------------------------------------------------------
// public section 
//-----------------------------------------------------------------
 public:

	//######################## SPECIFIC TYPES ##############################
	
	//####################### CONSTRUCTOR & DESTRUCTOR #####################
	
	/** Device Constructor */
	FilterWheelBase(string name);

	/** Destructor */
	virtual ~FilterWheelBase();

	//########################## DEVICE METHODS ############################
	
	/** Connects the device with a CORBA and other GCS Services*/
	virtual void  connect(string orbname, bool corbaDebug, unsigned threads, long priority,
	                      bool mode      =Device::INTEGRATED,
	                      bool update    =Device::DO_NOT_UPDATE);
	
	/** Starting procedure */
	virtual void  start();
	
	/** Initialization procedure */
	virtual void  init();
	
	/** Halting procedure */
	virtual void  halt();
	
	/** Shutdown procedure */
	virtual void  shutdown();
	
	/** Reset procedure */
	virtual void  reset();
	
	/** Restore procedure */
	virtual void  restore();
	
	/** Test procedure */
	virtual void  test();
	
	/** Stops all commands and goes to fault */
	virtual void  abort();
	
	/** Report device info */
	virtual char* report(short level);
	
	/** Reports device version */
	const char* version();
	
	//####################### SPECIFIC METHODS #############################

	/**
	* void command
	*/
	virtual void moveCommand(short position) = 0;
	
	//####################### MONITORS #####################################

	/**
	* FilterWheelFilter
	*
	* @magnitude:
	* @description:FilterWheelFilter
	* @maximum:7
	* @minimum:0
	* @units:None
	* @sampling:0.2s
	* @storage:60.0s
	*/
	virtual short filterWheelFilter();

	/**
	* FilterWheelMoving
	*
	* @magnitude:
	* @description:FilterWheelMoving
	* @maximum:true
	* @minimum:false
	* @units:None
	* @sampling:0.2s
	* @storage:60.0s
	*/
	virtual bool filterWheelMoving();
	
	//####################### PROPERTIES ##################################
	
	
//-----------------------------------------------------------------
// protected section 
//-----------------------------------------------------------------
protected:

	bool corbaDebug_; ///<Activate/deactivate corba debugging
	bool update_    ; ///<Activate/deactivate profile updating
	
	// Read-only attributes (monitorable magnitudes)
	short filterWheelFilter_; ///<FilterWheelFilter
	bool  filterWheelMoving_; ///<FilterWheelMoving
	
	/// Method to create monitors
	void createMonitors_();
};

#endif // _FilterWheelBase_h_ 

