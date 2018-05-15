#include "Bst.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <queue>

using namespace std;

// ADDS FILENUMBERS TO A VECTOR
vector<int> addtextfiletovector(string filename) {
  vector<int> V;
  string x;
  ifstream input;
  input.open(filename);
  while (getline(input, x)) {
    int i = stoi(x);
    V.push_back(i);
  }
  input.close();
  return V;
}

int main() {
  string test1, test2, filename;
  cout << " Please enter the name of the text file containing the integers you "
          "would like to add on seperate lines : "
       << endl;
  cin >> filename;
  cout << endl;
  vector<int> V1 = addtextfiletovector(filename);
  Bst T1(V1);
  cout << "NUMBER OF NODES IN TREE : " << T1.Count_Nodes() << endl;
  cout << "Minumum OF NODES IN TREE : " << T1.Find_Min() << endl;
  cout << "Maximum OF NODES IN TREE : " << T1.Find_Max() << endl;
  cout << "TREE IS DISPLAYED HORIZANTALLY, ROOT IS THE LEFT MOST NODE, RIGHT "
          "SUBTREE IS ABOVE IT, LEFT SUBTREE IS BELOW IT\n"
       << test1 << endl;
  T1.disp();
  cout << endl;
  //T1.Delete(20);
  //cout <<"successor of 13 is " <<
 // T1.Successor(T1.Search(T1.root,13))->value<<endl;
  //T1.disp();
  return 0;
}