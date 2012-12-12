// -*- c-basic-offset: 2; -*-
#ifndef TMX_EXCEPTION_H
#define  TMX_EXCEPTION_H

#include "exceptions/exception.h"

class TmxException : public Exception 
{
public:
  TmxException(const Glib::ustring & complement) throw() :
    Exception("TMX error: " + complement) {}
  virtual ~TmxException() throw () {}
};

#endif // TMX_EXCEPTION_H
