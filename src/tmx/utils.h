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

    /**
     * Permet de découper une chaine selon un séparateur pour la stocker dans un tableau
     * 
     * @param str La chaine à découper
     * @param separator Le séparateur
     * @return Un tableau de chaines de caractères
     */
    vector<string> stringExplode(string str, string separator);

    /**
     * Permet de convertir un int en string
     * 
     * @param i L'entier à convertir
     * @return La string correspondante à l'int
     */
    string intToString(int i);
    
    /**
     * Permet de convertir un string en int
     * 
     * @param i La string à convertir
     * @return L'int correspondant à la string
     */
    int stringToInt(string s);
};

#endif	/* UTILS_H */

