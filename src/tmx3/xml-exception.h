#ifndef TMX_XML_EXCEPTION_H
#define TMX_XML_EXCEPTION_H

#include "exception.h"

namespace tmx
{
	/*!
	  \brief Exception thrown when an error append with Tinyxml2.
	 */
  class XmlException : public Exception
  {
  public:

    XmlException(const std::string & complement)
      throw ()
      : Exception("XML error: " + complement) { }

    virtual ~XmlException() throw () { }
  };
}

#endif // TMX_XML_EXCEPTION_H
