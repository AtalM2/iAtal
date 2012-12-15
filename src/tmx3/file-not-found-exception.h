#ifndef FILE_NOT_FOUND_EXCEPTION_H
#define  FILE_NOT_FOUND_EXCEPTION_H

#include "exception.h"

class FileNotFoundException : public Exception {
public:

	FileNotFoundException(const std::string & complement) throw ()
	: Exception("FileNotFound: " + complement) {
	}

	virtual ~FileNotFoundException() throw () {
	}
};

#endif // FILE_NOT_FOUND_EXCEPTION_H
