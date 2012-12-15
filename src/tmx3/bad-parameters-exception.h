
#ifndef BAD_PARAMETERS_EXCEPTION_H
#define BAD_PARAMETERS_EXCEPTION_H

#include "exception.h"

class BadParametersException : public Exception {
public:

	BadParametersException(const std::string & complement) throw ()
	: Exception("Bad parameters: " + complement) {
	}

	virtual ~BadParametersException() throw () {
	}
};

#endif // BAD_PARAMETERS_EXCEPTION_H
