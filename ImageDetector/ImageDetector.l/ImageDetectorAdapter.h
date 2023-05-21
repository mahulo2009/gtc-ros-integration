// Copyright (c) 2023 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

#ifndef _ImageDetectorAdapter_h_
#define _ImageDetectorAdapter_h_

// Includes
#include <DeviceAdapter.h>
#include "IMAGEDETECTORS.h"
#include "ImageDetectorBase.h"

class ImageDetector;

//This class implements the IDL interface ImageDetector_ifce
class ImageDetectorAdapter : public virtual POA_IMAGEDETECTOR::ImageDetector_ifce,  public DeviceAdapter
{

 //--------------------------------------------------
 // public section 
 //--------------------------------------------------
 public:

	// Constructor
	ImageDetectorAdapter(ImageDetectorBase* device);

	// Destructor
	~ImageDetectorAdapter();


	//----------------------------------------------------------------------
	// Device specific operations
	//----------------------------------------------------------------------
	void   expose                ();
	void   setExposureTimeSeconds(CORBA::Double time);

	//----------------------------------------------------------------------
	// Monitorable attributes (device magnitudes) 
	//----------------------------------------------------------------------
	CORBA::Boolean idExposing        ();
	CORBA::Double  idExposureTimeLeft();

	//----------------------------------------------------------------------
	// Configurable attributes (device properties) 
	//----------------------------------------------------------------------


 //-----------------------------------------------------------------
 // protected section 
 //-----------------------------------------------------------------
 protected:

	//--------------------------------------------------
	// private section 
	//--------------------------------------------------
	private:

	ImageDetectorBase* device_;
};

#endif // _ImageDetectorAdapter_h_ 

