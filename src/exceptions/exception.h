// -*- c-basic-offset: 2; -*-
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

