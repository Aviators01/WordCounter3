#ifndef dictionary_h
#define dictionary_h

#include <vector>
#include <stdio.h>
#include <string>

using namespace std;
using std::string;

typedef string WORD;
typedef int itr;
 
struct ENTRY{
  WORD w;
  int freq;
};

class DICTION{
private:
	vector<ENTRY> d;
	int limit;
public :
	DICTION(int size = 0);		//Constructor. Size is initial size of dictionary
	itr locateWord(WORD w);		//locateWord returns location of found word or -1 if not found
	void insert(WORD w);		//inserts WORD w in dictionary if not there. else increases frequency by 1 (this is what operator+() does below)
	DICTION operator+(WORD w);	//overloaded addition operator insert word w in dictionary if not already there. else, increases frequency by 1
	void dump(ostream &o,int i = -1); //dumps first i words in dictionary to ostream or all if i=-1
	friend ostream &operator<<(ostream &,DICTION &);
};

//this is just dump() re-written as an overloaded operator. note that it should dump the WHOLE dictionary
ostream &operator<<(ostream &,DICTION &);
WORD GetNextWord();
#endif