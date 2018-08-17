#include "CuckooHashTable.h"
#include "CuckooHashTable.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main(int argc, char** argv){
	string s;
	cout << "INPUT THE NAME OF THE TXT FILE YOU WANT TO READ THE CONTENTS FROM:" << endl;
	cout <<"FILE MUST HAVE THE CONTENTS YOU WANT TO ADD TO THE HASH TABLE IN THE FOLLOWING FORMAT" << endl;
	cout << "NUMBER 1 \n" << "NUMBER 2 \n" << "NUMBER 3 \n" << "NUMBER 4 \n" << "NUMBER 5 \n" << endl;
	cout << "NOW PLEASE ENTER FILENAME " << endl;
	cin >> s;
	ifstream input(s);
	CuckooHashTable cht;
    string line;
    while (getline(input, line)) {

      cht.add(line);
    }
	cht.print();
	return 0;
}
