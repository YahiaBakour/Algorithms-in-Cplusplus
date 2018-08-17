// CopyRight @ 2018
// Author : Yahia Bakour 

/*
Algorithm explanation:

IDEA: Use the basic cuckoo hashing principles : Apply first hash function on the value x, place value x in table 1 -> 
-> if cell is occupied by another value y, swap values x and y ,move value y to table 2 -> Repeat Recursively if you run into same issue in table 2

*** TO DETECT CYCLE : CHECK IF NUMBER OF SWAPS EXCEEDS 35

Constructor:

Step 1: Fill the 2d vector with "-" strings to signify an empty slot


Hash Function:

Step 1:Used an if else statement to decide which function to use depending on which table is selected

Add Function:

Step 1: Check if you are adding to first or second table using a (bool first flag), if the slot is empty, simply add the value to the slot and set (bool first flag) to the other table
Step 2: If slot is not empty, set temp equal to the current slot value -> replace slot value with the new value -> recursively call ADD(replaced value)


 */


#include "CuckooHashTable.h"
#include <iostream>
#include <fstream> 
#include <string> 
#include <cctype> 
#include <limits> 
#include <stdlib.h>
  using namespace std;
bool first = true;
int counter = 0;

CuckooHashTable::CuckooHashTable() { // Constructor
  this ->contents.reserve(13 * 2);
  size = 13;
  for (int i = 0; i != 2; i++) {
    for (int j = 0; j != 11; j++) {
      this ->contents[i].push_back("-");
    }
  }
}

CuckooHashTable::CuckooHashTable(int size) { // Constructor
  this -> contents.reserve(size * 2);
  for (int i = 0; i != 2; i++) {
    for (int j = 0; j != size; j++) {
      this -> contents[i].push_back("-");
    }
  }
}

int CuckooHashTable::hashCode(string value, int ID) { // compute hash function for input 'value', table 'which'
  int y = stoi(value);
  int z;
  switch (ID) {
  case 0:
    z = y % 11;
  case 1:
    z = (y / 11) % 11;
  }
  return z;
}

int CuckooHashTable::Number_Of_Added_Elements() {
  int Numberofelements = 0;
  for (int i = 0; i != 2; i++) {
    for (int j = 0; j != size; j++) {
      if (contents[i][j] != "-") Numberofelements++;
    }
  }
  return Numberofelements;
}
void CuckooHashTable::add(string value) { // insert 'value' to hash table
  // check if cycle, by checking if counter goes over 36
  // if (counter > 36) {
    // cout << "CYCLE : INFINITE LOOP DETECTED,EXIT" << endl;
    // Rehash();
  // }
  // if (Number_Of_Added_Elements() / (2 * size) > 0.5) {
    // cout << "LOAD FACTOR IS ABOUT TO BE LESS THAN HALF" << endl;
    // Rehash();
  // }
  int V1 = hashCode(value, 0);
  int V2 = hashCode(value, 1);

  int temppos;
  string temp;
  //check if key is already there, if it is then do nothing
  if (contents[0][V1] == value) return;
  if (contents[1][V2] == value) return;

  if (contents[0][V1] == "-" && first) {
    contents[0][V1] = value;
    counter = 0;
    return;
  } // if you want to add to table 1 and slot is empty, do this
  if (contents[1][V2] == "-" && !first) {
    contents[1][V2] = value;
    counter = 0;
    first = true;
    return;
  } // if you want to add to table 2 and slot is empty, do this
  if (first) { // if swapping and moving from table 1 to table 2, do this
    temp = contents[0][V1];
    contents[0][V1] = value;
    first = false;
    counter++;
    add(temp);
  }
  if (!first) { // if swapping and moving from table 2 to table 1, do this
    temp = contents[1][V2];
    contents[1][V2] = value;
    first = true;
    counter++;
    add(temp);
  }

}

vector < string > CuckooHashTable::VectorOfElements() {
  int Numberofelements = 0;
  vector < string > V;
  for (int i = 0; i != 2; i++) {
    for (int j = 0; j != size; j++) {
      if (contents[i][j] != "-") V.push_back(contents[i][j]);
    }
  }
  return V;
}
void CuckooHashTable::Rehash() {
  vector < string > Vec = VectorOfElements();
  contents.clear();
  for (int i = 0; i != 2; i++) {
    for (int j = 0; j != 2 * size; j++) {
      this ->contents[i].push_back("-");
    }
  }
  for (int i = 0; i != Vec.size(); i++) {
    add(Vec[i]);
  }
}

void CuckooHashTable::print() { // print the content of the hash table in the specified format
  for (int i = 0; i != 2; i++) {
    if (i == 0) {
      cout << "Table 1:" << endl;
    } else {
      cout << "Table 2:" << endl;
    }
    for (int j = 0; j != size; j++) {
      cout << "   " << contents[i][j] << endl;
    }
    cout << endl;
  }
}