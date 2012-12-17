#ifndef TMX_FILE_NOT_FOUND_EXCEPTION_H
#define TMX_FILE_NOT_FOUND_EXCEPTION_H

#include "exception.h"

namespace tmx
{
	/*!
	  \brief Exception thrown when the file doesn't exist.
	 */
  class FileNotFoundException : public Exception {
  public:

    FileNotFoundException(const std::string & complement)
      throw ()
      : Exception("FileNotFound: " + complement) { }
  
    virtual ~FileNotFoundException() throw () { }
  };
}

#endif // TMX_FILE_NOT_FOUND_EXCEPTION_H
