// -*- c-basic-offset: 2; -*-
#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <glibmm/ustring.h>

class Exception : public std::exception
{
 public:
	virtual ~Exception() throw() {}

	const char* what() const throw() { return message_.c_str(); }

 protected:
	Exception(const Glib::ustring & m) throw() : message_(m) {}
	
 private:
	const Glib::ustring message_;
};

#endif // EXCEPTION_H

