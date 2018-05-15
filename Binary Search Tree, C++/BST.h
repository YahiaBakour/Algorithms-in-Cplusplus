#ifndef BST_h
#define BST_h
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {
  int value;
  Node* left;
  Node* right;
  Node* Parent;
};

class Bst {
 public:
  // Constructor
  Bst();

  // creates a one-node BST with the given key
  Bst(int number);

  // constructs a BST by inserting integers from the vector into the tree
  Bst(vector<int>& List);

  // Search for given value starting at root and return where node should be
  // placed, even if its a duplicate
  Node* Search(Node* Root, int key);

  // Duplicate a tree starting at a certain node and return the root of the new
  // BST
  Node* Replicate_Sub_Tree(Node* Rootofnewtree, Node* Rootoforiginal);

  // Returns number of nodes in the entire tree
  int Count_Nodes();

  // Insert Number as new key to the entire BST
  void insert(int num);

  // Deletes Node From BST
  void Delete(int key);

  // Returns successor of a node in BST
  Node* Successor(Node* sucessee);

  // Finds Node holding minimum value in the BST
  int Find_Min();

  // Finds Node Holding maximum value in the BST
  int Find_Max();

  // Pretty Print the BST, disp() and display(Node* P, int indent) logic and
  // code are not mine
  void disp();

  void display(Node* P, int indent);

  Node* root;
};

#endif
