// -*- c-basic-offset: 2; c-indentation-style: ellemtel; -*-

//  Copyright (C) 2012

// This file is part of iAtal.

// iAtal is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// iAtal is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with iAtal.  If not, see <http://www.gnu.org/licenses/>.

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
