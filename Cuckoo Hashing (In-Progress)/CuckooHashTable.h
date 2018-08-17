//
//  CuckooHashTable.h
//  CuckooHashTable
//

#ifndef CuckooHashTable_h
#define CuckooHashTable_h

#include<string>
#include<vector>
#include<cmath>
#include<iostream>
#include<cstdlib>

using namespace std;
class CuckooHashTable {
  private:
  
  vector < vector < string >> contents; // the two hash tables are implemented as a 2D vector
  int size;
  
  public:
    CuckooHashTable(); // Constructor
  CuckooHashTable(int size); // Constructor
  int hashCode(string value, int which); // compute hash function for input 'value', table 'which'
  
  void Rehash();
  
  vector < string > VectorOfElements();
  void add(string value); // insert 'value' to hash table
  void print(); // print the content of the hash table in the specified format
  int Number_Of_Added_Elements();
};


#endif /* CuckooHashTable_h */
