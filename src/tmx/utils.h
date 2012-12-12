/* 
 * File:   utils.h
 * Author: Noemi
 *
 * Created on 10 décembre 2012, 19:13
 */

#ifndef UTILS_H
#define	UTILS_H

#include <string>
#include <vector>

using namespace std;

namespace Utils {

    /*!
      \brief Split a string according to a given sepator.

      Example:
      @verbatim
      stringExplode("this;is;a;test", ";");
      → ["this", "is", "a", "test"]
      @endverbatim
      
      \param str The string to split.
      \param separator The separator to be used.
      \return A vector of strings.
    */
    vector<string> stringExplode(string str, string separator);

    /*!
      \brief Convert an int to a string

      \param i The int to be converted.
      \return A string representing i.
    */
    string intToString(int i);
    
    /*!
      \brief Convert a string to an int.

      \param s The string to be converted.
      \return A int representing s.
    */
    int stringToInt(string s);
};

#endif	/* UTILS_H */

