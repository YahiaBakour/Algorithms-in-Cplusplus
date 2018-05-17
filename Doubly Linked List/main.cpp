#include <iostream>
#include <limits>
#include "DLL.h"

int main() {
  DoubleLinkedList<double> *myLL = new DoubleLinkedList<double>();
  DoubleLinkedList<int> *myLL2 = new DoubleLinkedList<int>();
  DoubleLinkedList<char> *myLL3 = new DoubleLinkedList<char>();

  // Insert method 1
  myLL->insert(0.04);
  myLL->insert(0.1);
  myLL->insert(0.0);
  myLL->insert(1.2);
  myLL->insert(0.7);
  myLL->insert(0.8);

  // Insert method 2
  vector<int> v{0, 4, 1, 2, 5, 6, 3, 200, 34, 54, -2, -5, -6};
  myLL2->insert_from_vector(v);

  // Insert method 3
  Node<char> *NewLocation;
  NewLocation = myLL3->search(myLL3->head, 'c');
  myLL3->insert(NewLocation, 'c');
  NewLocation = myLL3->search(myLL3->head, 'b');
  myLL3->insert(NewLocation, 'b');
  NewLocation = myLL3->search(myLL3->head, 'a');
  myLL3->insert(NewLocation, 'a');
  NewLocation = myLL3->search(myLL3->head, 'd');
  myLL3->insert(NewLocation, 'd');

  // Print Stuff
  cout << "Linked list data: \n";
  cout << "LINKED LIST 1 : " << endl;
  myLL->printData();
  cout << endl;
  cout << "LINKED LIST 2 : " << endl;
  myLL2->printData();
  cout << endl;
  cout << "LINKED LIST 3 : " << endl;
  myLL3->printData();
  cout << endl;

  cout << endl;
  cout << "After Deletion of Stuff :  \n" << endl;

  cout << "LINKED LIST 1 after deleting 0.1: " << endl;
  myLL->Delete(0.1);
  myLL->printData();
  cout << endl;
  cout << "LINKED LIST 2 after deleting 4: " << endl;
  myLL2->Delete(4);
  myLL2->printData();
  cout << endl;
  cout << "LINKED LIST 3 after deleting a: " << endl;
  myLL3->Delete('a');
  myLL3->printData();
  cout << endl;

  return 0;
}