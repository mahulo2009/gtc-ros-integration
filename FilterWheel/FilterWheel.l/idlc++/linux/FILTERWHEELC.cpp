// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.2.0
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.cs.wustl.edu/~schmidt/TAO.html
 **/

// TAO_IDL - Generated from
// be/be_codegen.cpp:376


#include "FILTERWHEELC.h"
#include "tao/AnyTypeCode/Null_RefCount_Policy.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Alias_TypeCode_Static.h"
#include "tao/AnyTypeCode/Enum_TypeCode_Static.h"
#include "tao/AnyTypeCode/Objref_TypeCode_Static.h"
#include "tao/CDR.h"
#include "tao/Exception_Data.h"
#include "tao/Invocation_Adapter.h"
#include "tao/Object_T.h"
#include "tao/CDR.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/AnyTypeCode/Any_Impl_T.h"
#include "tao/AnyTypeCode/Any_Basic_Impl_T.h"
#include "ace/OS_NS_string.h"

#if !defined (__ACE_INLINE__)
#include "FILTERWHEELC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be/be_visitor_typecode/enum_typecode.cpp:31
static char const * const _tao_enumerators_FILTERWHEEL_Filter[] =
  {
    "UV",
    "PURPLE",
    "BLUE",
    "GREEN",
    "YELLOW",
    "ORANGE",
    "RED",
    "IR"
    
  };

static TAO::TypeCode::Enum<char const *,
                           char const * const *,
                           TAO::Null_RefCount_Policy>
  _tao_tc_FILTERWHEEL_Filter (
    "IDL:gtc/FILTERWHEEL/Filter:1.0",
    "Filter",
    _tao_enumerators_FILTERWHEEL_Filter,
    8);
  

namespace FILTERWHEEL
{
  ::CORBA::TypeCode_ptr const _tc_Filter =
    &_tao_tc_FILTERWHEEL_Filter;
}

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:51

// Traits specializations for FILTERWHEEL::FilterWheel_ifce.

FILTERWHEEL::FilterWheel_ifce_ptr
TAO::Objref_Traits<FILTERWHEEL::FilterWheel_ifce>::duplicate (
    FILTERWHEEL::FilterWheel_ifce_ptr p)
{
  return FILTERWHEEL::FilterWheel_ifce::_duplicate (p);
}

void
TAO::Objref_Traits<FILTERWHEEL::FilterWheel_ifce>::release (
    FILTERWHEEL::FilterWheel_ifce_ptr p)
{
  ::CORBA::release (p);
}

FILTERWHEEL::FilterWheel_ifce_ptr
TAO::Objref_Traits<FILTERWHEEL::FilterWheel_ifce>::nil (void)
{
  return FILTERWHEEL::FilterWheel_ifce::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<FILTERWHEEL::FilterWheel_ifce>::marshal (
    const FILTERWHEEL::FilterWheel_ifce_ptr p,
    TAO_OutputCDR & cdr)
{
  return ::CORBA::Object::marshal (p, cdr);
}

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_cs.cpp:91

void
FILTERWHEEL::FilterWheel_ifce::moveCommand (
  ::FILTERWHEEL::Filter position)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  TAO::Arg_Traits< void>::ret_val _tao_retval;
  TAO::Arg_Traits< ::FILTERWHEEL::Filter>::in_arg_val _tao_position (position);

  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval,
      &_tao_position
    };

  static TAO::Exception_Data
  _tao_FILTERWHEEL_FilterWheel_ifce_moveCommand_exceptiondata [] = 
    {
      {
        "IDL:gtc/DGT/GCSException:1.0",
        DGT::GCSException::_alloc
#if TAO_HAS_INTERCEPTORS == 1
        , DGT::_tc_GCSException
#endif /* TAO_HAS_INTERCEPTORS */
      }
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      2,
      "moveCommand",
      11,
      TAO::TAO_CO_NONE | TAO::TAO_CO_THRU_POA_STRATEGY
    );

  _tao_call.invoke (
      _tao_FILTERWHEEL_FilterWheel_ifce_moveCommand_exceptiondata,
      1
    );
}

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_cs.cpp:91

::FILTERWHEEL::Filter
FILTERWHEEL::FilterWheel_ifce::filterWheelFilter (
  void)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  TAO::Arg_Traits< ::FILTERWHEEL::Filter>::ret_val _tao_retval;

  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      1,
      "_get_filterWheelFilter",
      22,
      TAO::TAO_CO_NONE | TAO::TAO_CO_THRU_POA_STRATEGY
    );

  _tao_call.invoke (0, 0);

  return _tao_retval.retn ();
}

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_cs.cpp:91

::CORBA::Boolean
FILTERWHEEL::FilterWheel_ifce::filterWheelMoving (
  void)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  TAO::Arg_Traits< ::ACE_InputCDR::to_boolean>::ret_val _tao_retval;

  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      1,
      "_get_filterWheelMoving",
      22,
      TAO::TAO_CO_NONE | TAO::TAO_CO_THRU_POA_STRATEGY
    );

  _tao_call.invoke (0, 0);

  return _tao_retval.retn ();
}

FILTERWHEEL::FilterWheel_ifce::FilterWheel_ifce (void)
{
}

FILTERWHEEL::FilterWheel_ifce::~FilterWheel_ifce (void)
{
}

void
FILTERWHEEL::FilterWheel_ifce::_tao_any_destructor (void *_tao_void_pointer)
{
  FilterWheel_ifce *_tao_tmp_pointer =
    static_cast<FilterWheel_ifce *> (_tao_void_pointer);
  ::CORBA::release (_tao_tmp_pointer);
}

FILTERWHEEL::FilterWheel_ifce_ptr
FILTERWHEEL::FilterWheel_ifce::_narrow (
    ::CORBA::Object_ptr _tao_objref)
{
  return
    TAO::Narrow_Utils<FilterWheel_ifce>::narrow (
        _tao_objref,
        "IDL:gtc/FILTERWHEEL/FilterWheel_ifce:1.0");
}

FILTERWHEEL::FilterWheel_ifce_ptr
FILTERWHEEL::FilterWheel_ifce::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref)
{
  return
    TAO::Narrow_Utils<FilterWheel_ifce>::unchecked_narrow (
        _tao_objref);
}

FILTERWHEEL::FilterWheel_ifce_ptr
FILTERWHEEL::FilterWheel_ifce::_nil (void)
{
  return 0;
}

FILTERWHEEL::FilterWheel_ifce_ptr
FILTERWHEEL::FilterWheel_ifce::_duplicate (FilterWheel_ifce_ptr obj)
{
  if (! ::CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  return obj;
}

void
FILTERWHEEL::FilterWheel_ifce::_tao_release (FilterWheel_ifce_ptr obj)
{
  ::CORBA::release (obj);
}

::CORBA::Boolean
FILTERWHEEL::FilterWheel_ifce::_is_a (const char *value)
{
  if (
      ACE_OS::strcmp (
          value,
          "IDL:gtc/MM/Monitor_ifce:1.0"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:gtc/DCF/Device_ifce:1.0"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:gtc/FILTERWHEEL/FilterWheel_ifce:1.0"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        ) == 0
    )
    {
      return true; // success using local knowledge
    }
  else
    {
      return this->::CORBA::Object::_is_a (value);
    }
}

const char* FILTERWHEEL::FilterWheel_ifce::_interface_repository_id (void) const
{
  return "IDL:gtc/FILTERWHEEL/FilterWheel_ifce:1.0";
}

::CORBA::Boolean
FILTERWHEEL::FilterWheel_ifce::marshal (TAO_OutputCDR &cdr)
{
  return (cdr << this);
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/objref_typecode.cpp:72

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_FILTERWHEEL_FilterWheel_ifce (
    ::CORBA::tk_objref,
    "IDL:gtc/FILTERWHEEL/FilterWheel_ifce:1.0",
    "FilterWheel_ifce");
  

namespace FILTERWHEEL
{
  ::CORBA::TypeCode_ptr const _tc_FilterWheel_ifce =
    &_tao_tc_FILTERWHEEL_FilterWheel_ifce;
}

// TAO_IDL - Generated from
// be/be_visitor_enum/any_op_cs.cpp:38

TAO_BEGIN_VERSIONED_NAMESPACE_DECL


TAO_END_VERSIONED_NAMESPACE_DECL



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace FILTERWHEEL
{
  void operator<<= (
      ::CORBA::Any &_tao_any,
      ::FILTERWHEEL::Filter _tao_elem
    )
  {
    TAO::Any_Basic_Impl_T< ::FILTERWHEEL::Filter>::insert (
        _tao_any,
        ::FILTERWHEEL::_tc_Filter,
        _tao_elem
      );
  }

  ::CORBA::Boolean operator>>= (
      const ::CORBA::Any &_tao_any,
      ::FILTERWHEEL::Filter &_tao_elem
    )
  {
    return
      TAO::Any_Basic_Impl_T< ::FILTERWHEEL::Filter>::extract (
          _tao_any,
          ::FILTERWHEEL::_tc_Filter,
          _tao_elem 
        );
  }
}

#else

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

void operator<<= (
    ::CORBA::Any &_tao_any,
    FILTERWHEEL::Filter _tao_elem
  )
{
  TAO::Any_Basic_Impl_T<FILTERWHEEL::Filter>::insert (
      _tao_any,
      FILTERWHEEL::_tc_Filter,
      _tao_elem
    );
}

::CORBA::Boolean operator>>= (
    const ::CORBA::Any &_tao_any,
    FILTERWHEEL::Filter &_tao_elem
  )
{
  return
    TAO::Any_Basic_Impl_T<FILTERWHEEL::Filter>::extract (
        _tao_any,
        FILTERWHEEL::_tc_Filter,
        _tao_elem 
      );
}
TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:41
TAO_BEGIN_VERSIONED_NAMESPACE_DECL



namespace TAO
{
  template<>
  ::CORBA::Boolean
  Any_Impl_T<FILTERWHEEL::FilterWheel_ifce>::to_object (
      ::CORBA::Object_ptr &_tao_elem) const
  {
    _tao_elem = ::CORBA::Object::_duplicate (this->value_);
    return true;
  }
}
TAO_END_VERSIONED_NAMESPACE_DECL



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace FILTERWHEEL
{
  

  /// Copying insertion.
  void
  operator<<= (
      ::CORBA::Any &_tao_any,
      FilterWheel_ifce_ptr _tao_elem)
  {
    FilterWheel_ifce_ptr _tao_objptr =
      FilterWheel_ifce::_duplicate (_tao_elem);
    _tao_any <<= &_tao_objptr;
  }

  /// Non-copying insertion.
  void
  operator<<= (
      ::CORBA::Any &_tao_any,
      FilterWheel_ifce_ptr *_tao_elem)
  {
    TAO::Any_Impl_T<FilterWheel_ifce>::insert (
        _tao_any,
        FilterWheel_ifce::_tao_any_destructor,
        _tc_FilterWheel_ifce,
        *_tao_elem);
  }

  ::CORBA::Boolean
  operator>>= (
      const ::CORBA::Any &_tao_any,
      FilterWheel_ifce_ptr &_tao_elem)
  {
    return
      TAO::Any_Impl_T<FilterWheel_ifce>::extract (
          _tao_any,
          FilterWheel_ifce::_tao_any_destructor,
          _tc_FilterWheel_ifce,
          _tao_elem);
  }
}

#else

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



/// Copying insertion.
void
operator<<= (
    ::CORBA::Any &_tao_any,
    FILTERWHEEL::FilterWheel_ifce_ptr _tao_elem)
{
  FILTERWHEEL::FilterWheel_ifce_ptr _tao_objptr =
    FILTERWHEEL::FilterWheel_ifce::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

/// Non-copying insertion.
void
operator<<= (
    ::CORBA::Any &_tao_any,
    FILTERWHEEL::FilterWheel_ifce_ptr *_tao_elem)
{
  TAO::Any_Impl_T<FILTERWHEEL::FilterWheel_ifce>::insert (
      _tao_any,
      FILTERWHEEL::FilterWheel_ifce::_tao_any_destructor,
      FILTERWHEEL::_tc_FilterWheel_ifce,
      *_tao_elem);
}

::CORBA::Boolean
operator>>= (
    const ::CORBA::Any &_tao_any,
    FILTERWHEEL::FilterWheel_ifce_ptr &_tao_elem)
{
  return
    TAO::Any_Impl_T<FILTERWHEEL::FilterWheel_ifce>::extract (
        _tao_any,
        FILTERWHEEL::FilterWheel_ifce::_tao_any_destructor,
        FILTERWHEEL::_tc_FilterWheel_ifce,
        _tao_elem);
}

TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from
// be/be_visitor_enum/cdr_op_cs.cpp:37


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (TAO_OutputCDR &strm, FILTERWHEEL::Filter _tao_enumerator)
{
  return strm << static_cast< ::CORBA::ULong> (_tao_enumerator);
}

::CORBA::Boolean operator>> (TAO_InputCDR &strm, FILTERWHEEL::Filter & _tao_enumerator)
{
  ::CORBA::ULong _tao_temp = 0;
  ::CORBA::Boolean const _tao_success = strm >> _tao_temp;
  
  if (_tao_success)
    {
      _tao_enumerator = static_cast<FILTERWHEEL::Filter> (_tao_temp);
    }
  
  return _tao_success;
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_interface/cdr_op_cs.cpp:54

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const FILTERWHEEL::FilterWheel_ifce_ptr _tao_objref)
{
  ::CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    FILTERWHEEL::FilterWheel_ifce_ptr &_tao_objref)
{
  ::CORBA::Object_var obj;

  if (!(strm >> obj.inout ()))
    {
      return false;
    }
  
  typedef ::FILTERWHEEL::FilterWheel_ifce RHS_SCOPED_NAME;

  // Narrow to the right type.
  _tao_objref =
    TAO::Narrow_Utils<RHS_SCOPED_NAME>::unchecked_narrow (obj.in ());
    
  return true;
}

TAO_END_VERSIONED_NAMESPACE_DECL



