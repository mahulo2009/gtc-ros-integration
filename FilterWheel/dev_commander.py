#!/usr/bin/python
from omniORB import CORBA, PortableServer
from gtc.DSL.DAF.GCSNameService import GCSNameService

import DGT
import FILTERWHEEL
import FILTERWHEEL__POA
import sys

if __name__ == "__main__":    
    print("Hello Monitor Manager!")

    orb = CORBA.ORB_init(sys.argv, CORBA.ORB_ID)
    poa = orb.resolve_initial_references("RootPOA")
    poaManager = poa._get_the_POAManager()
    poaManager.activate()

    ns = GCSNameService(orb)
 
    filterWheel = ns.resolve("Osiris/FilterWheel_1",FILTERWHEEL.FilterWheel_ifce)
    filterWheel.ping()
    #filterWheel.setExposureTimeSeconds(5.)
    filterWheel.moveCommand(FILTERWHEEL.YELLOW)
    
    #orb.run()
