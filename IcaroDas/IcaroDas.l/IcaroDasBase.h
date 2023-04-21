// Copyright (c) 2022 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

#ifndef _IcaroDasBase_h_
#define _IcaroDasBase_h_

// Includes
#include <Device.h>
#include <ConcreteArrays.h>

/**
* This class is automaticaly regenerated when devBuilder-gev is invoked,
* and therefore it should not be edited by the developer.
*/
class IcaroDasBase : public Device
{
//-----------------------------------------------------------------
// public section 
//-----------------------------------------------------------------
 public:

	//######################## SPECIFIC TYPES ##############################
	
	/**
	 *  The state of the CCD
	 */
	enum CCDState
	{
		CCD_OFF, CCD_IDLE, CCD_EXPOSING, CCD_READING
	};

	//####################### CONSTRUCTOR & DESTRUCTOR #####################
	
	/** Device Constructor */
	IcaroDasBase(string name);

	/** Destructor */
	virtual ~IcaroDasBase();

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
	* Expose
	*/
	virtual void exposeFromFile(const char* filename) = 0;

	/**
	* Abort Acquisition
	*/
	virtual void abortAcquisition() = 0;

	/**
	* Setup number of exposures
	*/
	virtual void setupNumberOfExposures(long num) = 0;

	/**
	* Setup exposure time in seconds
	*/
	virtual void setupExposureTimeSeconds(double time) = 0;
	
	//####################### MONITORS #####################################

	/**
	* The state of the CCD
	*
	* @magnitude:
	* @description:CCD and controller state
	* @values:CCD_OFF, CCD_IDLE, CCD_EXPOSING, CCD_READING
	* @sampling:100s
	* @storage:600s
	*/
	virtual IcaroDasBase::CCDState ccdState();

	/**
	* Time left to finish the exposition
	*
	* @magnitude:
	* @description:Time left to finish the exposition
	* @maximum:36000
	* @minimum:0
	* @units:Second
	* @sampling:1s
	* @storage:60s
	*/
	virtual double exposureTimeLeft();

	/**
	* Number of the current exposure
	*
	* @magnitude:
	* @description:Number of the current exposure
	* @maximum:2000000000
	* @minimum:0
	* @sampling:1s
	* @storage:60s
	*/
	virtual long currentExposure();
	
	//####################### PROPERTIES ##################################

	/**
	* Instance name of the Data Factory agent that will receive the adquired frames
	*
	* @property:
	* @description:Instance name of the Data Factory agent that will receive the adquired frames
	* @default:ICARODFAgent
	*/
	virtual const char* dataFactoryAgentInstanceCorbaName();
	virtual void dataFactoryAgentInstanceCorbaName(const char* new_value); 

	/**
	* Instance name of the Data Factory that will receive the adquired frames
	*
	* @property:
	* @description:Instance name of the Data Factory that will receive the adquired frames
	* @default:ICARODFAgent
	*/
	virtual const char* dataFactoryManagerInstanceCorbaName();
	virtual void dataFactoryManagerInstanceCorbaName(const char* new_value); 
	
	
//-----------------------------------------------------------------
// protected section 
//-----------------------------------------------------------------
protected:

	bool corbaDebug_; ///<Activate/deactivate corba debugging
	bool update_    ; ///<Activate/deactivate profile updating
	
	// Read-only attributes (monitorable magnitudes)
	CCDState ccdState_        ; ///<The state of the CCD
	double   exposureTimeLeft_; ///<Time left to finish the exposition
	long     currentExposure_ ; ///<Number of the current exposure
	
	// Modifiable attributes (device properties)
	std::string dataFactoryAgentInstanceCorbaName_  ; ///<Instance name of the Data Factory agent that will receive the adquired frames
	std::string dataFactoryManagerInstanceCorbaName_; ///<Instance name of the Data Factory that will receive the adquired frames
	
	/// Method to create monitors
	void createMonitors_();
};

#endif // _IcaroDasBase_h_ 

