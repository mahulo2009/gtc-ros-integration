#--------------------------------------------------------------
# ICARO/IcaroDas Device profile
# File generated: 14/11/2022  
#--------------------------------------------------------------

[ Header ICARO/IcaroDas.header ]
instance   = ICARO/IcaroDas
class_name = IcaroDas
version    = 0.1
panels     = gtc.AL.Inspector.Panels.Device
tabs       = Commands|Alarms|Configs|Monitors
ifr_id     = IDL:gtc/ICARODAS/IcaroDas_ifce:1.0

#--------------------------------------------------------------
# Properties
#--------------------------------------------------------------
[ Property ICARO/IcaroDas.dataFactoryAgentInstanceCorbaName ]
description = Instance name of the Data Factory agent that will receive the adquired frames
units       = None
type        = string
max_value   = string : 0
min_value   = string : 0

[ Property ICARO/IcaroDas.dataFactoryManagerInstanceCorbaName ]
description = Instance name of the Data Factory that will receive the adquired frames
units       = None
type        = string
max_value   = string : 0
min_value   = string : 0

#--------------------------------------------------------------
# Magnitudes
#--------------------------------------------------------------
[ Magnitude ICARO/IcaroDas.ccdState ]
description     = CCD and controller state
units           = None
type            = enum
upper_limit     = CCDState : 0
lower_limit     = CCDState : 0
default_sampling_period = TimeValue : 100s
default_storage_period  = TimeValue : 600s

[ Magnitude ICARO/IcaroDas.exposureTimeLeft ]
description     = Time left to finish the exposition
units           = Second
type            = double
upper_limit     = double : 36000
lower_limit     = double : 0
default_sampling_period = TimeValue : 1s
default_storage_period  = TimeValue : 60s

[ Magnitude ICARO/IcaroDas.currentExposure ]
description     = Number of the current exposure
units           = None
type            = long
upper_limit     = long : 2000000000
lower_limit     = long : 0
default_sampling_period = TimeValue : 1s
default_storage_period  = TimeValue : 60s

#--------------------------------------------------------------
# Alarms
#--------------------------------------------------------------
[ Alarm ICARO/IcaroDas.DeviceFault ]
severity = LEVEL1
req_ack  = Yes
actions  = "Check status"

#--------------------------------------------------------------
# Default configuration
#--------------------------------------------------------------
[ Configuration ICARO/IcaroDas.Default ]
dataFactoryAgentInstanceCorbaName   = string : ICARODFAgent
dataFactoryManagerInstanceCorbaName = string : DF/Manager1
