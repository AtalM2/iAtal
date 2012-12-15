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

class Utils {
public:
	static std::vector<std::string> stringExplode(std::string str, std::string separator);
	static std::string intToString(int i);
	static int stringToInt(std::string s);
	static std::string stringReplace(std::string str, std::string oldStr, char newStr);
private:

};

#endif	/* UTILS_H */

