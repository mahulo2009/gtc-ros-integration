# Python stubs generated by omniidl from /work/gcsop/src_c++/gtc/FilterWheel/FilterWheel.l/FILTERWHEEL.idl
# DO NOT EDIT THIS FILE!

import omniORB, _omnipy
from omniORB import CORBA, PortableServer
_0_CORBA = CORBA


_omnipy.checkVersion(4,2, __file__, 1)

try:
    property
except NameError:
    def property(*args):
        return None


# #include "DGT.idl"
import DGT_idl
_0_DGT = omniORB.openModule("DGT")
_0_DGT__POA = omniORB.openModule("DGT__POA")

# #include "MMCommon.idl"
import MMCommon_idl
_0_MM = omniORB.openModule("MM")
_0_MM__POA = omniORB.openModule("MM__POA")

# #include "MonitorManager.idl"
import MonitorManager_idl
_0_MM = omniORB.openModule("MM")
_0_MM__POA = omniORB.openModule("MM__POA")

# #include "CONFIG.idl"
import CONFIG_idl
_0_CONFIG = omniORB.openModule("CONFIG")
_0_CONFIG__POA = omniORB.openModule("CONFIG__POA")

# #include "DCF.idl"
import DCF_idl
_0_DCF = omniORB.openModule("DCF")
_0_DCF__POA = omniORB.openModule("DCF__POA")

#
# Start of module "FILTERWHEEL"
#
__name__ = "FILTERWHEEL"
_0_FILTERWHEEL = omniORB.openModule("FILTERWHEEL", r"/work/gcsop/src_c++/gtc/FilterWheel/FilterWheel.l/FILTERWHEEL.idl")
_0_FILTERWHEEL__POA = omniORB.openModule("FILTERWHEEL__POA", r"/work/gcsop/src_c++/gtc/FilterWheel/FilterWheel.l/FILTERWHEEL.idl")


# interface FilterWheel_ifce
_0_FILTERWHEEL._d_FilterWheel_ifce = (omniORB.tcInternal.tv_objref, "IDL:gtc/FILTERWHEEL/FilterWheel_ifce:1.0", "FilterWheel_ifce")
omniORB.typeMapping["IDL:gtc/FILTERWHEEL/FilterWheel_ifce:1.0"] = _0_FILTERWHEEL._d_FilterWheel_ifce
_0_FILTERWHEEL.FilterWheel_ifce = omniORB.newEmptyClass()
class FilterWheel_ifce (_0_DCF.Device_ifce):
    _NP_RepositoryId = _0_FILTERWHEEL._d_FilterWheel_ifce[1]

    def __init__(self, *args, **kw):
        raise RuntimeError("Cannot construct objects of this type.")

    _nil = CORBA.Object._nil


_0_FILTERWHEEL.FilterWheel_ifce = FilterWheel_ifce
_0_FILTERWHEEL._tc_FilterWheel_ifce = omniORB.tcInternal.createTypeCode(_0_FILTERWHEEL._d_FilterWheel_ifce)
omniORB.registerType(FilterWheel_ifce._NP_RepositoryId, _0_FILTERWHEEL._d_FilterWheel_ifce, _0_FILTERWHEEL._tc_FilterWheel_ifce)

# FilterWheel_ifce operations and attributes
FilterWheel_ifce._d_moveCommand = ((omniORB.tcInternal.tv_short, ), (), {_0_DGT.GCSException._NP_RepositoryId: _0_DGT._d_GCSException})
FilterWheel_ifce._d__get_filterWheelFilter = ((),(omniORB.tcInternal.tv_short,),None)
FilterWheel_ifce._d__get_filterWheelMoving = ((),(omniORB.tcInternal.tv_boolean,),None)

# FilterWheel_ifce object reference
class _objref_FilterWheel_ifce (_0_DCF._objref_Device_ifce):
    _NP_RepositoryId = FilterWheel_ifce._NP_RepositoryId

    def __init__(self, obj):
        _0_DCF._objref_Device_ifce.__init__(self, obj)

    def moveCommand(self, *args):
        return self._obj.invoke("moveCommand", _0_FILTERWHEEL.FilterWheel_ifce._d_moveCommand, args)

    def _get_filterWheelFilter(self, *args):
        return self._obj.invoke("_get_filterWheelFilter", _0_FILTERWHEEL.FilterWheel_ifce._d__get_filterWheelFilter, args)

    filterWheelFilter = property(_get_filterWheelFilter)


    def _get_filterWheelMoving(self, *args):
        return self._obj.invoke("_get_filterWheelMoving", _0_FILTERWHEEL.FilterWheel_ifce._d__get_filterWheelMoving, args)

    filterWheelMoving = property(_get_filterWheelMoving)


omniORB.registerObjref(FilterWheel_ifce._NP_RepositoryId, _objref_FilterWheel_ifce)
_0_FILTERWHEEL._objref_FilterWheel_ifce = _objref_FilterWheel_ifce
del FilterWheel_ifce, _objref_FilterWheel_ifce

# FilterWheel_ifce skeleton
__name__ = "FILTERWHEEL__POA"
class FilterWheel_ifce (_0_DCF__POA.Device_ifce):
    _NP_RepositoryId = _0_FILTERWHEEL.FilterWheel_ifce._NP_RepositoryId


    _omni_op_d = {"moveCommand": _0_FILTERWHEEL.FilterWheel_ifce._d_moveCommand, "_get_filterWheelFilter": _0_FILTERWHEEL.FilterWheel_ifce._d__get_filterWheelFilter, "_get_filterWheelMoving": _0_FILTERWHEEL.FilterWheel_ifce._d__get_filterWheelMoving}
    _omni_op_d.update(_0_DCF__POA.Device_ifce._omni_op_d)

FilterWheel_ifce._omni_skeleton = FilterWheel_ifce
_0_FILTERWHEEL__POA.FilterWheel_ifce = FilterWheel_ifce
omniORB.registerSkeleton(FilterWheel_ifce._NP_RepositoryId, FilterWheel_ifce)
del FilterWheel_ifce
__name__ = "FILTERWHEEL"

#
# End of module "FILTERWHEEL"
#
__name__ = "FILTERWHEEL_idl"

_exported_modules = ( "FILTERWHEEL", )

# The end.
