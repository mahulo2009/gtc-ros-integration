#--------------------------------------------------------------
# Osiris/ImageDetector_1 Device profile
# File generated: 21/4/2023  
#--------------------------------------------------------------

[ Header Osiris/ImageDetector_1.header ]
instance   = Osiris/ImageDetector_1
class_name = ImageDetector
version    = 0.1
panels     = gtc.AL.Inspector.Panels.Device
tabs       = Commands|Alarms|Configs|Monitors
ifr_id     = IDL:gtc/IMAGEDETECTOR/ImageDetector_ifce:1.0

#--------------------------------------------------------------
# Properties
#--------------------------------------------------------------
#--------------------------------------------------------------
# Magnitudes
#--------------------------------------------------------------
[ Magnitude Osiris/ImageDetector_1.idExposing ]
description     = ImageDetectorExposing
units           = None
type            = boolean
upper_limit     = bool : true
lower_limit     = bool : false
default_sampling_period = TimeValue : 100s
default_storage_period  = TimeValue : 600s

[ Magnitude Osiris/ImageDetector_1.idExposureTimeLeft ]
description     = ImageDetectorExposureTimeLeft
units           = Second
type            = double
upper_limit     = double : 100000
lower_limit     = double : 0
default_sampling_period = TimeValue : 2s
default_storage_period  = TimeValue : 60.0s

#--------------------------------------------------------------
# Alarms
#--------------------------------------------------------------
[ Alarm Osiris/ImageDetector_1.DeviceFault ]
severity = LEVEL5
req_ack  = Yes
actions  = "Check this Device"

#--------------------------------------------------------------
# Default configuration
#--------------------------------------------------------------
[ Configuration Osiris/ImageDetector_1.Default ]
