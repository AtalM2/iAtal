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
    vector<string> stringExplode(string str, string separator);
    string intToString(int i);
    int stringToInt(string s);
};

#endif	/* UTILS_H */

