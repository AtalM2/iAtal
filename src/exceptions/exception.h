// -*- c-basic-offset: 2; -*-

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

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <glibmm/ustring.h>

/*!
  \brief Super class for all exceptions of the projet.

  If you whish to create new exceptions, derive Exception and set the
  message with a customized construtor.

  Example:
  @verbatim
  class NewException : public Exception
  {
  public:
    NewException(const Glib::ustring & complement) throw()
      : Exception("New exception: " + complement) {}
    virtual ~NewException() throw () {}
  };
  @endverbatim
  */
class Exception : public std::exception
{
public:

  /*!
    \brief Default destructor.

    */
  virtual ~Exception() throw() {}

  /*!
    \brief Returns a description of the Exception.

    \return A string describing the Exception.
    */
  const char* what() const throw() { return message_.c_str(); }

protected:

  /*!
    \brief Construct an Exception with the given description.

    The constructor is protected to force the creation of new
    derivative Exception rather than classic Exception with a
    customized description.

    \param m An informative message describing the Exception.
    */
  Exception(const Glib::ustring & m) throw() : message_(m) {}
	
private:
  const Glib::ustring message_; //!< The message describing the Exception.
};

#endif // EXCEPTION_H

