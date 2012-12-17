#ifndef TMX_EXCEPTION_H
#define TMX_EXCEPTION_H

#include <exception>

namespace tmx
{
	/*!
	  \brief Default exception class for the TMX parser library.
	 */
  class Exception : public std::exception
  {
  public:

    virtual ~Exception() throw () { }

    const char* what() const throw () {
      return message_.c_str();
    }

  protected:

    Exception(const std::string & message)
      throw ()
      : message_(message) { }

  private:
    const std::string message_;
  };
}

#endif // TMX_EXCEPTION_H
