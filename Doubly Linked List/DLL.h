// By your BOI : Yahia B
// feel free to take whatever you would like

#ifndef DLL_H
#define DLL_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

template <class T>
struct Node {
 public:
  T key;
  Node<T>* next;
  Node<T>* prev;

  Node(const T& key) {
    this->key = key;
    this->next = nullptr;
    this->prev = nullptr;
  };

  void printData() { cout << key << " "; };
  void print() {
    cout << " * " << key << ": [addr: " << this << " next: " << this->next
         << " prev: " << this->prev << "]  ";
  };
};

template <class T>
class DoubleLinkedList {
 public:
  // Constructor for Doubly Linked List
  DoubleLinkedList();

  // Destructor for Doubly Linked List
  ~DoubleLinkedList();

  // Searches for a node starting at a location and returns node if found, Else:
  // Returns location of where it should be to ensure ascending order
  Node<T>* search(Node<T>* location, T key);

  // Inserts a node at a specific location
  Node<T>* insert(Node<T>* location, T key);

  // Insert Nodes into ordered LL from a vector
  void insert_from_vector(vector<T> v);

  // Insert Node with key N to maintain Ordered Linked List
  void insert(T N);

  // Print all of Linked List Data
  void printData();

  // Delete Node with key N
  void Delete(T N);

  // Returns total number of nodes currently in linked list
  int Count_Nodes();

  Node<T>* head; // Head of Linked List
  
  int Totalnumberofnodes; // Total number of nodes currently in linked list
};

// Constructor for linked list
template <class T>
DoubleLinkedList<T>::DoubleLinkedList() {
  Totalnumberofnodes = 0;
  head = nullptr;  // construct a linked list with a null head
}

// destructor for linked list
template <class T>
DoubleLinkedList<T>::~DoubleLinkedList() {
  Node<T>* temp = head;
  while (temp != nullptr) {  // keep iterating until head is null
    temp = head->next;
    delete head;
    head = temp;
  }
  delete head;  // delete head
}

template <class T>
void DoubleLinkedList<T>::insert_from_vector(vector<T> v) {
  for (int i = 0; i != v.size(); i++) {
    cout << "V [i] is : " << v[i] << endl;
    insert(v[i]);
  }
  return;
}

template <class T>
int DoubleLinkedList<T>::Count_Nodes() {
  return Totalnumberofnodes;
}

template <class T>
void DoubleLinkedList<T>::insert(T data) {
  Totalnumberofnodes++;
  Node<T>* N = new Node<T>(data);
  Node<T>* pt = new Node<T>(data);
  N->next = nullptr;
  N->prev == nullptr;
  pt = head;
  // Case 1 : Empty LL
  if (head == nullptr) {
    head = N;
    return;
  }

  // Case 2 : Insert to Head
  if (N->key < head->key) {
    N->next = head;
    head->prev = N;
    head = N;
    return;
  }

  while (pt->next != nullptr && N->key >= pt->next->key) {
    pt = pt->next;
  }

  // Case 2 : Insert to tail
  if (pt->next == nullptr) {
    pt->next = N;
    N->prev = pt;
    N->next = nullptr;
    return;
  }
  // Case 3 : Insert to somewhere in the middle
  else {
    N->prev = pt;
    N->next = pt->next;
    pt->next = N;
    N->next->prev = N;
    return;
  }
}

// Delete Node From LL
template <class T>
void DoubleLinkedList<T>::Delete(T key) {
  Totalnumberofnodes--;
  Node<T>* temp = new Node<T>(key);
  temp = head;

  // Case 1:Node key is Head
  if (key == head->key) {
    Node<T>* NewHead = head->next;
    NewHead->prev = nullptr;
    delete (head);
    head = NewHead;
    return;
  }

  while (temp != nullptr && temp->key != key) {
    temp = temp->next;
  }

  // Case 2:Node doesn't exist
  if (temp == nullptr) {
    Totalnumberofnodes++;
    cout << " Error: Node " << key << " Does Not Exist, Cannot Be Deleted"
         << endl;
    return;
  }

  Node<T>* Next = temp->next;
  Node<T>* Prev = temp->prev;

  // Case 3: Node is Tail
  if (Next == nullptr) {
    Node<T>* NewTail = Prev;
    delete (Prev->next);
    Prev->next = nullptr;
    return;
  }
  // Case 4: Node is somewhere in between
  else {
    Prev->next = Next;
    delete (Next->prev);
    Next->prev = Prev;
  }
}

bool insertright = false;  // bool to tell whether you have reached end of list
                           // and need to insert right or left
template <class T>
Node<T>* DoubleLinkedList<T>::search(Node<T>* location,
                                     T key) {  // Search for node or correct
                                               // spot to put node by checking
                                               // the location, location prev,
                                               // location next
  Node<T>* temp = new Node<T>(key);
  bool found = false;  // bool to say whether you found right spot or not

  if (location == nullptr) {
    return location;
  }  // if list is empty then return location
  if (location->prev == nullptr && key < location->key) {
    return location;
  }  // if starting at beggining of list and need to append to start return
     // location.
  while (found == false) {  // while not found
    if (location->prev == nullptr && location->next != nullptr &&
        key > location->key) {  // if the previous node is a null and key is
                                // larger than first element, iterate one
                                // element
      location = location->next;
    } else if (location->next == nullptr &&
               key > location->key) {  // if the previous node is a null and key
                                       // is larger than first element, iterate
                                       // one element
      insertright = true;
      return location;
    }  // iterate one element
    else if (key < (location->key) && key < (location->prev->key) &&
             (location->prev) != nullptr) {  // if key is less than the location
                                             // and prev location then iterate
                                             // back
      location = location->prev;
    } else if (key > location->key && key > location->prev->key &&
               location->prev != nullptr &&
               location->next != nullptr) {  // if key is greater than location
                                             // and key is greater than
                                             // location->prev iterate right
      location = location->next;
    } else if (key > location->key && key > location->prev->key &&
               location->prev != nullptr &&
               location->next == nullptr) {  // if key is greater than location
                                             // and key is greater than
                                             // location-> but we are at end of
                                             // list, return location and set
                                             // insertright bool as true
      insertright = true;
      return location;
    } else if (key > location->prev->key && key <= location->key &&
               location->prev != nullptr) {  // if key is greater than
                                             // location-> prev and key is less
                                             // than location key then its in
                                             // the right spot
      found = true;
      return location;
    }
  }
}
// insert function
template <class T>
Node<T>* DoubleLinkedList<T>::insert(Node<T>* location, T key) {
  Totalnumberofnodes++;

  Node<T>* temp = new Node<T>(key);  // make new node with key
  temp->key = key;
  temp->next = nullptr;
  temp->prev = nullptr;

  if (location == nullptr) {  // if location is null, its an empty list and
                              // youre going to create the list with the new
                              // node
    head = temp;
    head->prev = nullptr;
    head->next = nullptr;
    return location;

  } else if (location != nullptr && location->prev != nullptr &&
             insertright == false)  // if its in the middle/end of the list and
                                    // yo dont need to insert right, insert left
  {
    temp->next = location;
    location->prev->next = temp;
    temp->prev = location->prev;
    location->prev = temp;
    return (location);

  } else if (location != nullptr && location->prev != nullptr &&
             insertright == true)  // if its at the end of the list and you need
                                   // to insert right, insert right
  {
    insertright = false;
    temp->next = nullptr;
    temp->prev = location;
    location->next = temp;
    return (location);

  } else if (location != nullptr && location->prev == nullptr &&
             insertright == false)  // if the node you start at exists and the
                                    // previous node is a null then you are at
                                    // the beggining and inserting at the
                                    // beginning
  {
    temp->prev = nullptr;
    temp->next = location;
    location->prev = temp;
    head = temp;
    return location;
  } else if (location != nullptr && location->prev == nullptr &&
             insertright == true)  // if the node you start at exists and the
                                   // previous node is a null then you are at
                                   // the beggining and inserting at the
                                   // beginning
  {
    insertright = false;
    temp->next = nullptr;
    temp->prev = location;
    location->next = temp;
    return location;
  }
}

// Print linked list key
template <class T>
void DoubleLinkedList<T>::printData() {
  cout << "Current Number of Nodes : " << Count_Nodes() << endl;
  if (head == nullptr) {
    cout << "Linked list is empty" << endl;
    ;
    return;
  }

  head->printData();

  if (head->next == nullptr) {
    cout << endl;
    return;
  }

  Node<T>* currNode = head->next;
  Node<T>* prevNode = head;

  while (currNode->next != nullptr) {
    currNode->printData();
    prevNode = currNode;
    currNode = currNode->next;
  }

  currNode->printData();
  cout << endl;
}

#endif
