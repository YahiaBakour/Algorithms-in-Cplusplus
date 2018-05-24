#include <iostream>
#include <limits>
#include "SkipList.h"

int main() {
  SkipList<int> *mySL = new SkipList<int>();
  
  cout << "SKIP LIST DATA : " << endl;
  mySL->insert(4);
  mySL->insert(5);
  mySL->insert(6);
  mySL->insert(2);
  mySL->insert(3);
  mySL->insert(7); 
  mySL->insert(10);
  mySL->insert(311);
  mySL->insert(0); 
  mySL->insert(8);
  mySL->insert(9);
  mySL->insert(11);
  mySL->printData();
  //mySL->Search(4);

  int i = 4; // Node to be deleted
  
  mySL->Delete(i);
  
  cout <<"\n \n \n AFTER DELETION OF : " << i << endl;
  cout << "\n \n \n " << endl;
  mySL->printData();

  cout<< endl;


  return 0;
}