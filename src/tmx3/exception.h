#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>

class Exception : public std::exception {
public:

	virtual ~Exception() throw () {
	}

	const char* what() const throw () {
		return message_.c_str();
	}

protected:

	Exception(const std::string & message) throw () : message_(message) {
	}

private:
	const std::string message_;
};

#endif // EXCEPTION_H

