#ifndef TMX_BAD_PARAMETERS_EXCEPTION_H
#define TMX_BAD_PARAMETERS_EXCEPTION_H

#include "exception.h"

namespace tmx
{
	/*!
	  \brief Exception thrown when a bad parameter is found in the TMX file.
	 */
  class BadParametersException : public Exception
  {
  public:

    BadParametersException(const std::string & complement)
      throw ()
      : Exception("Bad parameters: " + complement) { }

    virtual ~BadParametersException() throw () { }
  };
}

#endif // TMX_BAD_PARAMETERS_EXCEPTION_H
