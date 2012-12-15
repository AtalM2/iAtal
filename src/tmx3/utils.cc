#include "utils.h"
#include <sstream>

/**
 * Permet de remplacer des caractères d'une chaine par un autre caractère
 * 
 * @param str La chaine dans laquelle on veut effectuer le remplacement
 * @param oldStr La liste des caractères à remplacer
 * @param newStr Le caractère de remplacement
 * @return Une nouvelle chaine avec les remplacements effectués
 */
std::string
Utils::stringReplace(std::string str, std::string oldStr, char newStr) {
	std::string results(str);
	size_t found;

	found = results.find_first_of(oldStr);
	while (found != std::string::npos) {
		results[found] = newStr;
		found = str.find_first_of(oldStr, found + 1);
	}

	return results;
}

