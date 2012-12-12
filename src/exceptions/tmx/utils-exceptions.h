// -*- c-basic-offset: 2; -*-
#ifndef _UTILS_EXCEPTIONS_H_
#define _UTILS_EXCEPTIONS_H_

#include "exceptions/exception.h"

class ConversionException : public Exception 
{
public:
  ConversionException(const Glib::ustring & complement) throw()
    : Exception("Cannot convert " + complement) {}
  virtual ~ConversionException() throw () {}
};

#endif /* _UTILS_EXCEPTIONS_H_ */
