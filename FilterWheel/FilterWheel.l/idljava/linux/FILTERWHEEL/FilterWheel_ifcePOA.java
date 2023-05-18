package FILTERWHEEL;


/**
* FILTERWHEEL/FilterWheel_ifcePOA.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from FILTERWHEEL.idl
* Thursday, May 18, 2023 2:56:53 PM UTC
*/

public abstract class FilterWheel_ifcePOA extends org.omg.PortableServer.Servant
 implements FILTERWHEEL.FilterWheel_ifceOperations, org.omg.CORBA.portable.InvokeHandler
{

  // Constructors

  private static java.util.Hashtable _methods = new java.util.Hashtable ();
  static
  {
    _methods.put ("moveCommand", new java.lang.Integer (0));
    _methods.put ("_get_filterWheelFilter", new java.lang.Integer (1));
    _methods.put ("_get_filterWheelMoving", new java.lang.Integer (2));
    _methods.put ("enable", new java.lang.Integer (3));
    _methods.put ("disable", new java.lang.Integer (4));
    _methods.put ("start", new java.lang.Integer (5));
    _methods.put ("init", new java.lang.Integer (6));
    _methods.put ("halt", new java.lang.Integer (7));
    _methods.put ("shutdown", new java.lang.Integer (8));
    _methods.put ("restore", new java.lang.Integer (9));
    _methods.put ("abort", new java.lang.Integer (10));
    _methods.put ("reset", new java.lang.Integer (11));
    _methods.put ("test", new java.lang.Integer (12));
    _methods.put ("configure", new java.lang.Integer (13));
    _methods.put ("ping", new java.lang.Integer (14));
    _methods.put ("report", new java.lang.Integer (15));
    _methods.put ("internals", new java.lang.Integer (16));
    _methods.put ("isOff", new java.lang.Integer (17));
    _methods.put ("isStarting", new java.lang.Integer (18));
    _methods.put ("isShuttingDown", new java.lang.Integer (19));
    _methods.put ("isOn", new java.lang.Integer (20));
    _methods.put ("isInitialising", new java.lang.Integer (21));
    _methods.put ("isHalting", new java.lang.Integer (22));
    _methods.put ("isIdle", new java.lang.Integer (23));
    _methods.put ("isRunning", new java.lang.Integer (24));
    _methods.put ("isDisabled", new java.lang.Integer (25));
    _methods.put ("isFault", new java.lang.Integer (26));
    _methods.put ("isResetting", new java.lang.Integer (27));
    _methods.put ("isReady", new java.lang.Integer (28));
    _methods.put ("isConfigurable", new java.lang.Integer (29));
    _methods.put ("isComposite", new java.lang.Integer (30));
    _methods.put ("isIntegrated", new java.lang.Integer (31));
    _methods.put ("_get_name", new java.lang.Integer (32));
    _methods.put ("_get_className", new java.lang.Integer (33));
    _methods.put ("_get_version", new java.lang.Integer (34));
    _methods.put ("_get_state", new java.lang.Integer (35));
    _methods.put ("_get_startTime", new java.lang.Integer (36));
    _methods.put ("_get_magnitudes", new java.lang.Integer (37));
    _methods.put ("_get_properties", new java.lang.Integer (38));
    _methods.put ("_get_alarms", new java.lang.Integer (39));
    _methods.put ("_get_configuration", new java.lang.Integer (40));
    _methods.put ("_set_configuration", new java.lang.Integer (41));
    _methods.put ("startDebug", new java.lang.Integer (42));
    _methods.put ("stopDebug", new java.lang.Integer (43));
    _methods.put ("changeMonitorConfiguration", new java.lang.Integer (44));
    _methods.put ("forceSampleData", new java.lang.Integer (45));
  }

  public org.omg.CORBA.portable.OutputStream _invoke (String $method,
                                org.omg.CORBA.portable.InputStream in,
                                org.omg.CORBA.portable.ResponseHandler $rh)
  {
    org.omg.CORBA.portable.OutputStream out = null;
    java.lang.Integer __method = (java.lang.Integer)_methods.get ($method);
    if (__method == null)
      throw new org.omg.CORBA.BAD_OPERATION (0, org.omg.CORBA.CompletionStatus.COMPLETED_MAYBE);

    switch (__method.intValue ())
    {

  // Specific FilterWheel operations
       case 0:  // FILTERWHEEL/FilterWheel_ifce/moveCommand
       {
         try {
           short position = in.read_short ();
           this.moveCommand (position);
           out = $rh.createReply();
         } catch (DGT.GCSException $ex) {
           out = $rh.createExceptionReply ();
           DGT.GCSExceptionHelper.write (out, $ex);
         }
         break;
       }


  // Monitorable attributes (device magnitudes)
       case 1:  // FILTERWHEEL/FilterWheel_ifce/_get_filterWheelFilter
       {
         short $result = (short)0;
         $result = this.filterWheelFilter ();
         out = $rh.createReply();
         out.write_short ($result);
         break;
       }

       case 2:  // FILTERWHEEL/FilterWheel_ifce/_get_filterWheelMoving
       {
         boolean $result = false;
         $result = this.filterWheelMoving ();
         out = $rh.createReply();
         out.write_boolean ($result);
         break;
       }


  /**
      * Enables the device
      */
       case 3:  // DCF/Device_ifce/enable
       {
         try {
           this.enable ();
           out = $rh.createReply();
         } catch (DGT.GCSException $ex) {
           out = $rh.createExceptionReply ();
           DGT.GCSExceptionHelper.write (out, $ex);
         }
         break;
       }


  /**
      * Goes to DISABLE state. Only possible from OFF,ON,IDLE,FAULT
      */
       case 4:  // DCF/Device_ifce/disable
       {
         try {
           this.disable ();
           out = $rh.createReply();
         } catch (DGT.GCSException $ex) {
           out = $rh.createExceptionReply ();
           DGT.GCSExceptionHelper.write (out, $ex);
         }
         break;
       }


  /**
      * Starting procedure
      */
       case 5:  // DCF/Device_ifce/start
       {
         try {
           this.start ();
           out = $rh.createReply();
         } catch (DGT.GCSException $ex) {
           out = $rh.createExceptionReply ();
           DGT.GCSExceptionHelper.write (out, $ex);
         }
         break;
       }


  /**
      * Initialization procedure
      */
       case 6:  // DCF/Device_ifce/init
       {
         try {
           this.init ();
           out = $rh.createReply();
         } catch (DGT.GCSException $ex) {
           out = $rh.createExceptionReply ();
           DGT.GCSExceptionHelper.write (out, $ex);
         }
         break;
       }


  /**
      * Halting procedure
      */
       case 7:  // DCF/Device_ifce/halt
       {
         try {
           this.halt ();
           out = $rh.createReply();
         } catch (DGT.GCSException $ex) {
           out = $rh.createExceptionReply ();
           DGT.GCSExceptionHelper.write (out, $ex);
         }
         break;
       }


  /**
      * Shutdown procedure
      */
       case 8:  // DCF/Device_ifce/shutdown
       {
         try {
           this.shutdown ();
           out = $rh.createReply();
         } catch (DGT.GCSException $ex) {
           out = $rh.createExceptionReply ();
           DGT.GCSExceptionHelper.write (out, $ex);
         }
         break;
       }


  /**
      * Restore previous situation before FAULT
      */
       case 9:  // DCF/Device_ifce/restore
       {
         try {
           this.restore ();
           out = $rh.createReply();
         } catch (DGT.GCSException $ex) {
           out = $rh.createExceptionReply ();
           DGT.GCSExceptionHelper.write (out, $ex);
         }
         break;
       }


  /**
      * Stop all activity and goes to FAULT
      */
       case 10:  // DCF/Device_ifce/abort
       {
         try {
           this.abort ();
           out = $rh.createReply();
         } catch (DGT.GCSException $ex) {
           out = $rh.createExceptionReply ();
           DGT.GCSExceptionHelper.write (out, $ex);
         }
         break;
       }


  /**
      * Resets the current settings, connections, etc of the Device.
      */
       case 11:  // DCF/Device_ifce/reset
       {
         try {
           this.reset ();
           out = $rh.createReply();
         } catch (DGT.GCSException $ex) {
           out = $rh.createExceptionReply ();
           DGT.GCSExceptionHelper.write (out, $ex);
         }
         break;
       }


  /**
      * Performs some kind of test and returns a report about the results.
      */
       case 12:  // DCF/Device_ifce/test
       {
         try {
           this.test ();
           out = $rh.createReply();
         } catch (DGT.GCSException $ex) {
           out = $rh.createExceptionReply ();
           DGT.GCSExceptionHelper.write (out, $ex);
         }
         break;
       }


  /**
      * Sets a configuration by name
      */
       case 13:  // DCF/Device_ifce/configure
       {
         try {
           String config_name = in.read_string ();
           this.configure (config_name);
           out = $rh.createReply();
         } catch (DGT.GCSException $ex) {
           out = $rh.createExceptionReply ();
           DGT.GCSExceptionHelper.write (out, $ex);
         }
         break;
       }


  /**
      * Checks that communication with a Device object is possible via CORBA.
      * In TAO at least, if this method is oneway it only checks for the sanity
      * of the remote ORB, but it does not garantee anything about the concrete 
      * remote object. For this reason the oneway has been removed.
      */
       case 14:  // DCF/Device_ifce/ping
       {
         try {
           this.ping ();
           out = $rh.createReply();
         } catch (DGT.GCSException $ex) {
           out = $rh.createExceptionReply ();
           DGT.GCSExceptionHelper.write (out, $ex);
         }
         break;
       }


  /**
      * Returns a text reporting the.
      * @param level (SHORT, FULL, NORMAL) 
      */
       case 15:  // DCF/Device_ifce/report
       {
         try {
           short level = in.read_short ();
           String $result = null;
           $result = this.report (level);
           out = $rh.createReply();
           out.write_string ($result);
         } catch (DGT.GCSException $ex) {
           out = $rh.createExceptionReply ();
           DGT.GCSExceptionHelper.write (out, $ex);
         }
         break;
       }


  /**
      * Returns a text reporting internal implementation details of Device. 
      */
       case 16:  // DCF/Device_ifce/internals
       {
         try {
           String $result = null;
           $result = this.internals ();
           out = $rh.createReply();
           out.write_string ($result);
         } catch (DGT.GCSException $ex) {
           out = $rh.createExceptionReply ();
           DGT.GCSExceptionHelper.write (out, $ex);
         }
         break;
       }


  /**
      * To be able to ask for a certain state
      */
       case 17:  // DCF/Device_ifce/isOff
       {
         boolean $result = false;
         $result = this.isOff ();
         out = $rh.createReply();
         out.write_boolean ($result);
         break;
       }

       case 18:  // DCF/Device_ifce/isStarting
       {
         boolean $result = false;
         $result = this.isStarting ();
         out = $rh.createReply();
         out.write_boolean ($result);
         break;
       }

       case 19:  // DCF/Device_ifce/isShuttingDown
       {
         boolean $result = false;
         $result = this.isShuttingDown ();
         out = $rh.createReply();
         out.write_boolean ($result);
         break;
       }

       case 20:  // DCF/Device_ifce/isOn
       {
         boolean $result = false;
         $result = this.isOn ();
         out = $rh.createReply();
         out.write_boolean ($result);
         break;
       }

       case 21:  // DCF/Device_ifce/isInitialising
       {
         boolean $result = false;
         $result = this.isInitialising ();
         out = $rh.createReply();
         out.write_boolean ($result);
         break;
       }

       case 22:  // DCF/Device_ifce/isHalting
       {
         boolean $result = false;
         $result = this.isHalting ();
         out = $rh.createReply();
         out.write_boolean ($result);
         break;
       }

       case 23:  // DCF/Device_ifce/isIdle
       {
         boolean $result = false;
         $result = this.isIdle ();
         out = $rh.createReply();
         out.write_boolean ($result);
         break;
       }

       case 24:  // DCF/Device_ifce/isRunning
       {
         boolean $result = false;
         $result = this.isRunning ();
         out = $rh.createReply();
         out.write_boolean ($result);
         break;
       }

       case 25:  // DCF/Device_ifce/isDisabled
       {
         boolean $result = false;
         $result = this.isDisabled ();
         out = $rh.createReply();
         out.write_boolean ($result);
         break;
       }

       case 26:  // DCF/Device_ifce/isFault
       {
         boolean $result = false;
         $result = this.isFault ();
         out = $rh.createReply();
         out.write_boolean ($result);
         break;
       }

       case 27:  // DCF/Device_ifce/isResetting
       {
         boolean $result = false;
         $result = this.isResetting ();
         out = $rh.createReply();
         out.write_boolean ($result);
         break;
       }


  /**
      * A Device is Ready in IDLE or RUN states. NOT in DISABLED.
      */
       case 28:  // DCF/Device_ifce/isReady
       {
         boolean $result = false;
         $result = this.isReady ();
         out = $rh.createReply();
         out.write_boolean ($result);
         break;
       }


  /**
      * A Device is configurable in STARTING, ON, IDLE, FAULT
      */
       case 29:  // DCF/Device_ifce/isConfigurable
       {
         boolean $result = false;
         $result = this.isConfigurable ();
         out = $rh.createReply();
         out.write_boolean ($result);
         break;
       }


  /**
      * A Device is composite if has aggregated Devices
      */
       case 30:  // DCF/Device_ifce/isComposite
       {
         boolean $result = false;
         $result = this.isComposite ();
         out = $rh.createReply();
         out.write_boolean ($result);
         break;
       }


  /**
      * A Device is INtegrated if is connected to the rest of GCS
      */
       case 31:  // DCF/Device_ifce/isIntegrated
       {
         boolean $result = false;
         $result = this.isIntegrated ();
         out = $rh.createReply();
         out.write_boolean ($result);
         break;
       }


  /**
      * The Device's instance name.
      */
       case 32:  // DCF/Device_ifce/_get_name
       {
         String $result = null;
         $result = this.name ();
         out = $rh.createReply();
         out.write_string ($result);
         break;
       }


  /**
      * The Device's class name.
      */
       case 33:  // DCF/Device_ifce/_get_className
       {
         String $result = null;
         $result = this.className ();
         out = $rh.createReply();
         out.write_string ($result);
         break;
       }


  /**
      * The Device's version.
      */
       case 34:  // DCF/Device_ifce/_get_version
       {
         String $result = null;
         $result = this.version ();
         out = $rh.createReply();
         out.write_string ($result);
         break;
       }


  /**
      * The Device's current state: OFF, ON, STARTING, IDLE, etc.
      */
       case 35:  // DCF/Device_ifce/_get_state
       {
         DGT.State_t $result = null;
         $result = this.state ();
         out = $rh.createReply();
         DGT.State_tHelper.write (out, $result);
         break;
       }


  /**
      * The time when the Device started running.
      */
       case 36:  // DCF/Device_ifce/_get_startTime
       {
         DGT.TimeValue $result = null;
         $result = this.startTime ();
         out = $rh.createReply();
         DGT.TimeValueHelper.write (out, $result);
         break;
       }


  /**
      * The list of monitorable magnitudes names supported by this Device.
      */
       case 37:  // DCF/Device_ifce/_get_magnitudes
       {
         String $result[] = null;
         $result = this.magnitudes ();
         out = $rh.createReply();
         DGT.StringListHelper.write (out, $result);
         break;
       }


  /**
      * The list of property names supported by this Device.
      */
       case 38:  // DCF/Device_ifce/_get_properties
       {
         String $result[] = null;
         $result = this.properties ();
         out = $rh.createReply();
         DGT.StringListHelper.write (out, $result);
         break;
       }


  /**
      * The list of alarm names supported by this Device.
      */
       case 39:  // DCF/Device_ifce/_get_alarms
       {
         String $result[] = null;
         $result = this.alarms ();
         out = $rh.createReply();
         DGT.StringListHelper.write (out, $result);
         break;
       }


  /**
      * Get/set as a whole the current Configuration of the Device.
      */
       case 40:  // DCF/Device_ifce/_get_configuration
       {
         CONFIG.Configuration $result = null;
         $result = this.configuration ();
         out = $rh.createReply();
         CONFIG.ConfigurationHelper.write (out, $result);
         break;
       }


  /**
      * Get/set as a whole the current Configuration of the Device.
      */
       case 41:  // DCF/Device_ifce/_set_configuration
       {
         CONFIG.Configuration newConfiguration = CONFIG.ConfigurationHelper.read (in);
         this.configuration (newConfiguration);
         out = $rh.createReply();
         break;
       }


  /* deprecated */
       case 42:  // DCF/Device_ifce/startDebug
       {
         this.startDebug ();
         out = $rh.createReply();
         break;
       }

       case 43:  // DCF/Device_ifce/stopDebug
       {
         this.stopDebug ();
         out = $rh.createReply();
         break;
       }

       case 44:  // MM/Monitor_ifce/changeMonitorConfiguration
       {
         try {
           String magnitude = in.read_string ();
           MM.Config config = MM.ConfigHelper.read (in);
           this.changeMonitorConfiguration (magnitude, config);
           out = $rh.createReply();
         } catch (DGT.GCSException $ex) {
           out = $rh.createExceptionReply ();
           DGT.GCSExceptionHelper.write (out, $ex);
         }
         break;
       }

       case 45:  // MM/Monitor_ifce/forceSampleData
       {
         try {
           String magnitude = in.read_string ();
           this.forceSampleData (magnitude);
           out = $rh.createReply();
         } catch (DGT.GCSException $ex) {
           out = $rh.createExceptionReply ();
           DGT.GCSExceptionHelper.write (out, $ex);
         }
         break;
       }

       default:
         throw new org.omg.CORBA.BAD_OPERATION (0, org.omg.CORBA.CompletionStatus.COMPLETED_MAYBE);
    }

    return out;
  } // _invoke

  // Type-specific CORBA::Object operations
  private static String[] __ids = {
    "IDL:gtc/FILTERWHEEL/FilterWheel_ifce:1.0", 
    "IDL:gtc/DCF/Device_ifce:1.0", 
    "IDL:gtc/MM/Monitor_ifce:1.0"};

  public String[] _all_interfaces (org.omg.PortableServer.POA poa, byte[] objectId)
  {
    return (String[])__ids.clone ();
  }

  public FilterWheel_ifce _this() 
  {
    return FilterWheel_ifceHelper.narrow(
    super._this_object());
  }

  public FilterWheel_ifce _this(org.omg.CORBA.ORB orb) 
  {
    return FilterWheel_ifceHelper.narrow(
    super._this_object(orb));
  }


} // class FilterWheel_ifcePOA
