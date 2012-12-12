// -*- c-basic-offset: 2; -*-
#ifndef FILE_NOT_FOUND_EXCEPTION_H
#define  FILE_NOT_FOUND_EXCEPTION_H

#include "exceptions/exception.h"

class FileNotFoundException : public Exception 
{
public:
  FileNotFoundException(const Glib::ustring & complement) throw()
    : Exception("File not found: " + complement) {}
  virtual ~FileNotFoundException() throw () {}
};

#endif // FILE_NOT_FOUND_EXCEPTION_H
