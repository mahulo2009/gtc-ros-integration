// Copyright (c) 2023 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

#ifndef _ImageDetectorBase_h_
#define _ImageDetectorBase_h_

// Includes
#include <Device.h>
#include <ConcreteArrays.h>

/**
* This class is automaticaly regenerated when devBuilder-gev is invoked,
* and therefore it should not be edited by the developer.
*/
class ImageDetectorBase : public Device
{
//-----------------------------------------------------------------
// public section 
//-----------------------------------------------------------------
 public:

	//######################## SPECIFIC TYPES ##############################
	
	//####################### CONSTRUCTOR & DESTRUCTOR #####################
	
	/** Device Constructor */
	ImageDetectorBase(string name);

	/** Destructor */
	virtual ~ImageDetectorBase();

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
	* Expose
	*/
	virtual void expose() = 0;

	/**
	* Set exposure time in seconds
	*/
	virtual void setExposureTimeSeconds(double time) = 0;
	
	//####################### MONITORS #####################################

	/**
	* ImageDetectorExposing
	*
	* @magnitude:
	* @description:ImageDetectorExposing
	* @maximum:true
	* @minimum:false
	* @units:None
	* @sampling:100s
	* @storage:600s
	*/
	virtual bool idExposing();

	/**
	* ImageDetectorExposureTimeLeft
	*
	* @magnitude:
	* @description:ImageDetectorExposureTimeLeft
	* @maximum:100000
	* @minimum:0
	* @units:Second
	* @sampling:2s
	* @storage:60.0s
	*/
	virtual double idExposureTimeLeft();
	
	//####################### PROPERTIES ##################################
	
	
//-----------------------------------------------------------------
// protected section 
//-----------------------------------------------------------------
protected:

	bool corbaDebug_; ///<Activate/deactivate corba debugging
	bool update_    ; ///<Activate/deactivate profile updating
	
	// Read-only attributes (monitorable magnitudes)
	bool   idExposing_        ; ///<ImageDetectorExposing
	double idExposureTimeLeft_; ///<ImageDetectorExposureTimeLeft
	
	/// Method to create monitors
	void createMonitors_();
};

#endif // _ImageDetectorBase_h_ 

