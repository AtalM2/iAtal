#ifndef XML_EXCEPTION_H
#define XML_EXCEPTION_H

#include "exception.h"

namespace tmx
{
  class XmlException : public Exception
  {
  public:

    XmlException(const std::string & complement)
      throw ()
      : Exception("XML error: " + complement) { }

    virtual ~XmlException() throw () { }
  };
}

#endif // XML_EXCEPTION_H
