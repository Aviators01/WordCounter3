#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include "dictionary.h"

using namespace std;
using std::string;

const int MAX = 100;

DICTION dictionary(MAX);  //your dictionary 
WORD word;

int main (void){
	while(true){
		word = GetNextWord();
		if(0==word.length()){
			cout << endl;
			cout << "dumping whole dictionary..." << endl;
			cout << dictionary;
			int n  = 5;
			cout << endl;
			cout << "dumping first "<< n << " words in dictionary...." << endl;
			dictionary.dump(cout,n);
			break;
		}
		
		if((dictionary.locateWord(word))>=0) cout << "word " << word << " already in dictionary\n";
		dictionary = dictionary + word;
	}
    return 0;
}