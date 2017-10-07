#include <iostream>
#include <string>
#include "stemming/english_stem.h"

using namespace std;

int main()
{
	string str;

	while ( cin >> str )
	{
		wstring word(str.begin(), str.end());
	
		stemming::english_stem<> eng;
		eng(word);
		
		wcout << word.c_str() << "\n";
	}
	
	return 0;
}