/*
Timothy Queva
CS2010 Lab8
December 1, 2020
*/

/*
This file uses the class interface of dictionary.h and for all intents and purposes
*/

#include "dictionary.h"
#include <iostream>
#include <iomanip>

typedef string WORD;


DICTION::DICTION(int size){
	limit = size;
}

//locateWord returns location of found word or -1 if not found
itr DICTION::locateWord(WORD w){
	int tsize=d.size();
	itr index=0;
	while(index<tsize){
		if(d[index].w==w) return index;
		index++;
	}
	return -1;
}

//inserts WORD w in dictionary if not there. else increases frequency by 1 (this is what operator+() does below)
void DICTION::insert(WORD w){
	if((*this).d.size()==(*this).limit) cout << "ERROR: Dictionary is full. Cannot add " << w << endl;
	
	int index=DICTION::locateWord(w);
	if(index==-1) d.push_back(ENTRY{w,1});
	else d[index].freq++;
}

//overloaded addition operator insert word w in dictionary if not already there. else, increases frequency by 1
DICTION DICTION::operator+(WORD w){
	(*this).insert(w);
	return *this;
}

//dumps first i words in dictionary to ostream or all if i=-1
void DICTION::dump(ostream &o,int i){
	o << string("/------------\\ \n")
	+ ("| Dictionary |\n")
	+ ("\\------------/ \n \n ")
	+ ("Word		Frequency\n")
	+ ("-------------------------") << endl;
	
	//Outputs word and their total
	if(i==-1) i=d.size();
	else if(i>d.size()) i=d.size(); 
	for(itr index=0;index<i;index++){
		o << setw(15) << left << d[index].w << "	" << setw(8) << right << d[index].freq << endl;
	}
}

//this is just dump() re-written as an overloaded operator. note that it should dump the WHOLE dictionary
ostream &operator<<(ostream &o,DICTION &d){
	d.dump(o);
	return o;
}

WORD GetNextWord(){
	WORD w;
	char ch;
	bool inword = false;
	
	while(cin.good()){
		ch = cin.get();
		if(isalpha(ch)){  /* function test if ch is A-Z, a-z */
			w.push_back(ch);
			inword= true;
		}
		else if (inword) return w;
	}

	return w;
}