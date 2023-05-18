// Copyright (c) 2023 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

#ifndef _ImageDetector_h_
#define _ImageDetector_h_

// Includes
#include "ImageDetectorBase.h"

#include <Frame.h>
#include "FrameAgent.h"

/**
* 
*/
class ImageDetector : public ImageDetectorBase
{
 //--------------------------------------------------
 // public section 
 //--------------------------------------------------
 public:

	//####################### CONSTRUCTOR & DESTRUCTOR #####################
	
	/** Device Constructor */
	ImageDetector(string name);

	/** Destructor */
	virtual ~ImageDetector();

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
	* Expose
	*/
	void expose();

	/**
	* Set exposure time in seconds
	*/
	void setExposureTimeSeconds(double time);
	

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

#endif // _ImageDetector_h_ 

