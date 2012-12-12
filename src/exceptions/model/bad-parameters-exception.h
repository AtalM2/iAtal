// -*- c-basic-offset: 2; -*-
#ifndef BAD_PARAMETERS_EXCEPTION_H
#define  BAD_PARAMETERS_EXCEPTION_H

#include "exceptions/exception.h"

class BadParametersException : public Exception 
{
public:
  BadParametersException(const Glib::ustring & complement) throw()
    : Exception("Bad parameters: " + complement) {}
  virtual ~BadParametersException() throw () {}
};

#endif // BAD_PARAMETERS_EXCEPTION_H
