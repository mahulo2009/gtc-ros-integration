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
// be/be_codegen.cpp:152

#ifndef _TAO_IDL_IDLC___LINUX_IMAGEDETECTORC_H_
#define _TAO_IDL_IDLC___LINUX_IMAGEDETECTORC_H_


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include "tao/AnyTypeCode/AnyTypeCode_methods.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Basic_Types.h"
#include "tao/ORB_Constants.h"
#include "tao/Object.h"
#include "tao/String_Manager_T.h"
#include "tao/Objref_VarOut_T.h"
#include "tao/Arg_Traits_T.h"
#include "tao/Basic_Arguments.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/Any_Insert_Policy_T.h"
#include "tao/Fixed_Size_Argument_T.h"
#include "tao/Var_Size_Argument_T.h"
#include "tao/Object_Argument_T.h"
#include "tao/Special_Basic_Arguments.h"
#include /**/ "tao/Version.h"
#include /**/ "tao/Versioned_Namespace.h"

#include "DCFC.h"

#if TAO_MAJOR_VERSION != 2 || TAO_MINOR_VERSION != 2 || TAO_BETA_VERSION != 0
#error This file should be regenerated with TAO_IDL
#endif

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO 

// TAO_IDL - Generated from
// be/be_visitor_root/root_ch.cpp:160
TAO_BEGIN_VERSIONED_NAMESPACE_DECL



namespace TAO
{
  template<typename T> class Narrow_Utils;
}
TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:38

namespace IMAGEDETECTOR
{

  // TAO_IDL - Generated from
  // be/be_interface.cpp:750

#if !defined (_IMAGEDETECTOR_IMAGEDETECTOR_IFCE__VAR_OUT_CH_)
#define _IMAGEDETECTOR_IMAGEDETECTOR_IFCE__VAR_OUT_CH_

  class ImageDetector_ifce;
  typedef ImageDetector_ifce *ImageDetector_ifce_ptr;

  typedef
    TAO_Objref_Var_T<
        ImageDetector_ifce
      >
    ImageDetector_ifce_var;
  
  typedef
    TAO_Objref_Out_T<
        ImageDetector_ifce
      >
    ImageDetector_ifce_out;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_interface/interface_ch.cpp:43

  class  ImageDetector_ifce
    : public virtual ::DCF::Device_ifce
  
  {
  public:
    friend class TAO::Narrow_Utils<ImageDetector_ifce>;

    // TAO_IDL - Generated from
    // be/be_type.cpp:307

    typedef ImageDetector_ifce_ptr _ptr_type;
    typedef ImageDetector_ifce_var _var_type;
    typedef ImageDetector_ifce_out _out_type;

    static void _tao_any_destructor (void *);

    // The static operations.
    static ImageDetector_ifce_ptr _duplicate (ImageDetector_ifce_ptr obj);

    static void _tao_release (ImageDetector_ifce_ptr obj);

    static ImageDetector_ifce_ptr _narrow (::CORBA::Object_ptr obj);
    static ImageDetector_ifce_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static ImageDetector_ifce_ptr _nil (void);

    virtual void expose (
      void);

    virtual void setExposureTimeSeconds (
      ::CORBA::Double time);

    virtual ::CORBA::Boolean idExposing (
      void);

    virtual ::CORBA::Boolean idExposureTimeLeft (
      void);

    // TAO_IDL - Generated from
    // be/be_visitor_interface/interface_ch.cpp:140

    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Concrete interface only.
    ImageDetector_ifce (void);

    // Concrete non-local interface only.
    ImageDetector_ifce (
        ::IOP::IOR *ior,
        TAO_ORB_Core *orb_core);
    
    // Non-local interface only.
    ImageDetector_ifce (
        TAO_Stub *objref,
        ::CORBA::Boolean _tao_collocated = false,
        TAO_Abstract_ServantBase *servant = 0,
        TAO_ORB_Core *orb_core = 0);

    virtual ~ImageDetector_ifce (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    ImageDetector_ifce (const ImageDetector_ifce &);

    void operator= (const ImageDetector_ifce &);
  };

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:37

  extern  ::CORBA::TypeCode_ptr const _tc_ImageDetector_ifce;

// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:67

} // module IMAGEDETECTOR

// TAO_IDL - Generated from
// be/be_visitor_arg_traits.cpp:68

TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:147

#if !defined (_IMAGEDETECTOR_IMAGEDETECTOR_IFCE__ARG_TRAITS_)
#define _IMAGEDETECTOR_IMAGEDETECTOR_IFCE__ARG_TRAITS_

  template<>
  class  Arg_Traits< ::IMAGEDETECTOR::ImageDetector_ifce>
    : public
        Object_Arg_Traits_T<
            ::IMAGEDETECTOR::ImageDetector_ifce_ptr,
            ::IMAGEDETECTOR::ImageDetector_ifce_var,
            ::IMAGEDETECTOR::ImageDetector_ifce_out,
            TAO::Objref_Traits<IMAGEDETECTOR::ImageDetector_ifce>,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

#endif /* end #if !defined */
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_traits.cpp:62

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{

#if !defined (_IMAGEDETECTOR_IMAGEDETECTOR_IFCE__TRAITS_)
#define _IMAGEDETECTOR_IMAGEDETECTOR_IFCE__TRAITS_

  template<>
  struct  Objref_Traits< ::IMAGEDETECTOR::ImageDetector_ifce>
  {
    static ::IMAGEDETECTOR::ImageDetector_ifce_ptr duplicate (
        ::IMAGEDETECTOR::ImageDetector_ifce_ptr p);
    static void release (
        ::IMAGEDETECTOR::ImageDetector_ifce_ptr p);
    static ::IMAGEDETECTOR::ImageDetector_ifce_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::IMAGEDETECTOR::ImageDetector_ifce_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */
}
TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_ch.cpp:44



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace IMAGEDETECTOR
{
   void operator<<= ( ::CORBA::Any &, ImageDetector_ifce_ptr); // copying
   void operator<<= ( ::CORBA::Any &, ImageDetector_ifce_ptr *); // non-copying
   ::CORBA::Boolean operator>>= (const ::CORBA::Any &, ImageDetector_ifce_ptr &);
}

#else


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 void operator<<= (::CORBA::Any &, IMAGEDETECTOR::ImageDetector_ifce_ptr); // copying
 void operator<<= (::CORBA::Any &, IMAGEDETECTOR::ImageDetector_ifce_ptr *); // non-copying
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, IMAGEDETECTOR::ImageDetector_ifce_ptr &);
TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from
// be/be_visitor_interface/cdr_op_ch.cpp:44

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const IMAGEDETECTOR::ImageDetector_ifce_ptr );
 ::CORBA::Boolean operator>> (TAO_InputCDR &, IMAGEDETECTOR::ImageDetector_ifce_ptr &);

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_codegen.cpp:1703
#if defined (__ACE_INLINE__)
#include "IMAGEDETECTORC.inl"
#endif /* defined INLINE */

#endif /* ifndef */

