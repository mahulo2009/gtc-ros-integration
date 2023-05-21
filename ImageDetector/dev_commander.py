#!/usr/bin/python
from omniORB import CORBA, PortableServer
from gtc.DSL.DAF.GCSNameService import GCSNameService

import DGT
import IMAGEDETECTOR
import IMAGEDETECTOR__POA
import sys

if __name__ == "__main__":    
    print("Hello Monitor Manager!")

    orb = CORBA.ORB_init(sys.argv, CORBA.ORB_ID)
    poa = orb.resolve_initial_references("RootPOA")
    poaManager = poa._get_the_POAManager()
    poaManager.activate()

    ns = GCSNameService(orb)
 
    imageDetector = ns.resolve("Osiris/ImageDetector_1",IMAGEDETECTOR.ImageDetector_ifce)
    imageDetector.ping()
    #imageDetector.setExposureTimeSeconds(5.)
    imageDetector.expose()
    
    #orb.run()
