#--------------------------------------------------------------
# Osiris/FilterWheel_1 Device profile
# File generated: 18/4/2023  
#--------------------------------------------------------------

[ Header Osiris/FilterWheel_1.header ]
instance   = Osiris/FilterWheel_1
class_name = FilterWheel
version    = 0.1
panels     = gtc.AL.Inspector.Panels.Device
tabs       = Commands|Alarms|Configs|Monitors
ifr_id     = IDL:gtc/FILTERWHEEL/FilterWheel_ifce:1.0

#--------------------------------------------------------------
# Properties
#--------------------------------------------------------------
#--------------------------------------------------------------
# Magnitudes
#--------------------------------------------------------------
[ Magnitude Osiris/FilterWheel_1.filterWheelFilter ]
description     = FilterWheelFilter
units           = None
type            = short
upper_limit     = short : 7
lower_limit     = short : 0
default_sampling_period = TimeValue : 0.2s
default_storage_period  = TimeValue : 60.0s

[ Magnitude Osiris/FilterWheel_1.filterWheelMoving ]
description     = FilterWheelMoving
units           = None
type            = boolean
upper_limit     = bool : true
lower_limit     = bool : false
default_sampling_period = TimeValue : 0.2s
default_storage_period  = TimeValue : 60.0s

#--------------------------------------------------------------
# Alarms
#--------------------------------------------------------------
[ Alarm Osiris/FilterWheel_1.DeviceFault ]
severity = LEVEL5
req_ack  = Yes
actions  = "Check this Device"

#--------------------------------------------------------------
# Default configuration
#--------------------------------------------------------------
[ Configuration Osiris/FilterWheel_1.Default ]
