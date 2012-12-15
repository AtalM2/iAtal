#ifndef _UTILS_EXCEPTIONS_H_
#define _UTILS_EXCEPTIONS_H_

#include "exception.h"

class ConversionException : public Exception {
public:

	ConversionException(const std::string & complement) throw ()
        : Exception("Conversion error: " + complement) {
	}

	virtual ~ConversionException() throw () {
	}
};

#endif /* _UTILS_EXCEPTIONS_H_ */
