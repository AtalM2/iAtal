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

class Utils {
public:
	static vector<string> stringExplode(string str, string separator);
	static string intToString(int i);
	static string stringReplace(string str, string oldStr, char newStr);
private:

};

#endif	/* UTILS_H */

