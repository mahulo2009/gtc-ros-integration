package FILTERWHEEL;

/**
* FILTERWHEEL/FilterHolder.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from FILTERWHEEL.idl
* Sunday, May 21, 2023 3:43:39 PM UTC
*/

public final class FilterHolder implements org.omg.CORBA.portable.Streamable
{
  public FILTERWHEEL.Filter value = null;

  public FilterHolder ()
  {
  }

  public FilterHolder (FILTERWHEEL.Filter initialValue)
  {
    value = initialValue;
  }

  public void _read (org.omg.CORBA.portable.InputStream i)
  {
    value = FILTERWHEEL.FilterHelper.read (i);
  }

  public void _write (org.omg.CORBA.portable.OutputStream o)
  {
    FILTERWHEEL.FilterHelper.write (o, value);
  }

  public org.omg.CORBA.TypeCode _type ()
  {
    return FILTERWHEEL.FilterHelper.type ();
  }

}
