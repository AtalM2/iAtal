/* 
 * File:   main.cpp
 * Author: Noemi
 *
 * Created on 23 novembre 2012, 21:48
 */

#include <iostream>
#include "tinyxml2.h"

using namespace tinyxml2;
using namespace std;

/*
 * 
 */
int main(int argc, char *argv[]) {
	XMLDocument doc;
	XMLError res = doc.LoadFile( "test.xml" );
	cout << res << endl;
	cout << argv[0] << endl;
	
	XMLElement* titleElement = doc.FirstChildElement( "PLAY" )->FirstChildElement( "TITLE" );
	const char* title = titleElement->GetText();
	printf( "Name of play (1): %s\n", title );

	XMLText* textNode = titleElement->FirstChild()->ToText();
	title = textNode->Value();
	printf( "Name of play (2): %s\n", title );
	
	return doc.ErrorID();
}

