from omniORB import CORBA, PortableServer
from gtc.DSL.DAF.GCSNameService import GCSNameService

import MM
import MM__POA
import DGT

class Subscriber(MM__POA.Consumer_ifce):
    
    def receiveDataBlocks(self,msg):
        print(msg)
        
    def receiveStateChanges(self,msg):
        print(msg)
    
    def receiveMagnitudeChanges(self,msg):
        print(msg)
    

if __name__ == "__main__":    
    print("Hello Monitor Manager!")

    orb = CORBA.ORB_init(sys.argv, CORBA.ORB_ID)
    poa = orb.resolve_initial_references("RootPOA")
    poaManager = poa._get_the_POAManager()
    poaManager.activate()

    ns = GCSNameService(orb)
 
    sub = Subscriber()
    mm = ns.resolve("MonitorManagers/MM1",MM.MonitorManager_ifce)
    mm.subscribeToDataBlocks("Test/InspectorDevice_1","byteArray1DMonitor", sub._this())
    
    orb.run()
