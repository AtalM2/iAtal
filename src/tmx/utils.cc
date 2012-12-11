#include "utils.h"
#include <sstream>

/**
 * Permet de découper une chaine selon un séparateur pour la stocker dans un tableau
 * 
 * @param str La chaine à découper
 * @param separator Le séparateur
 * @return Un tableau de chaines de caractères
 */
vector<string> Utils::stringExplode(string str, string separator) {
	size_t found;
	vector<string> results;
	found = str.find_first_of(separator);
	while (found < str.length() && found < string::npos) {
		if (found > 0) {
			results.push_back(str.substr(0, found));
		}
		str = str.substr(found + 1);
		found = str.find_first_of(separator);
	}
	if (str.length() > 0) {
		results.push_back(str);
	}
	return results;
}

/**
 * Permet de convertir un int en string
 * 
 * @param i L'entier à convertir
 * @return La string correspondante à l'int
 */
string Utils::intToString(int i) {
	ostringstream oss;
	oss << i;
	return oss.str();
}

/**
 * Permet de convertir un string en int
 * 
 * @param i La string à convertir
 * @return L'int correspondant à la string
 */
int Utils::stringToInt(string s) {
    std::istringstream iss(s);
    int number;
    iss >> number;
	return number;
}

