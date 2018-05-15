/*BST CLASS AND FUNCTIONS BY YOUR BOI: YAHIA B.

All of this code is open_Source so feel free to take whatever you'd like.

Note: disp() and display(Node* P, int indent) logic and code are NOT mine.
 */

#include "Bst.h"
#include <iomanip>
int numberofnodes;

// Create an Empty Binary Search Tree
Bst::Bst() { root = nullptr; }

// Create a One Node BST with the value of the node as num
Bst::Bst(int num) {
  root = new Node;
  root->value = num;
  root->left = root->right = nullptr;
}

// create a BST by inserting ints from the vector into the bst in order
Bst::Bst(vector<int>& List) {
  root = new Node;
  root->value = List[0];
  root->left = nullptr;
  root->right = nullptr;
  for (int i = 1; i < List.size(); i++) insert(List[i]);
}

/* Searches throughout Bst using Regular Bst Search, Returns where node should
 * be placed or where node is located*/
Node* Bst::Search(Node* Root, int key) {
  if (root == nullptr)
    return root;
  else if ((Root->value > key && Root->left == nullptr) ||
           (Root->value < key && Root->right == nullptr))
    return Root;  // IF ABOUT TO FALL OFF TREE
  else if (Root->value == key)
    return Root;
  else if (key > Root->value)
    Search(Root->right, key);
  else if (key < Root->value)
    Search(Root->left, key);
}

// insert num as a new value to the Bst
void Bst::insert(int num) {
  Node* node = new Node;
  if (root == nullptr) {
    Bst(num);
  } else {
    node->Parent = Search(root, num);
    node->left = node->right = nullptr;
    node->value = num;
    if (num >= node->Parent->value)
      node->Parent->right = node;
    else if (num < node->Parent->value)
      node->Parent->left = node;
  }
}

// Replicate the BST IF Given the root of the new tree and root of the original,
// returns the root of the newly copied tree/subtree
Node* Replicate_Sub_Tree(Node* Rootofnewtree,
                         Node* Rootoforiginal) {  // FUNCTION TO COPY A TREE
  Node* NEWNODE = new Node;
  if (Rootoforiginal != nullptr) {
    NEWNODE->value = Rootoforiginal->value;
    NEWNODE->left = Replicate_Sub_Tree(NEWNODE->left, Rootoforiginal->left);
    NEWNODE->right = Replicate_Sub_Tree(NEWNODE->right, Rootoforiginal->right);
    return NEWNODE;
  } else {
    NEWNODE = nullptr;
    return NEWNODE;
  }
}

// Counts the number of nodes in the BST
void Count(Node* Root) {
  if (Root == nullptr) return;
  numberofnodes++;
  Count(Root->left);
  Count(Root->right);
}

int Bst::Count_Nodes() {
  numberofnodes = 0;
  Count(root);
  return numberofnodes;
}

// Returns the Min Value in the BST
int Bst::Find_Min() {
  Node* p = new Node;
  p = root;
  if (p->left == nullptr) return p->value;
  while (p->left != nullptr) {
    p = p->left;
  }
  return p->value;
}

// Returns the Max Value in the BST
int Bst::Find_Max() {
  Node* p = new Node;
  p = root;
  if (p->right == nullptr) return p->value;
  while (p->right != nullptr) {
    p = p->right;
  }
  return p->value;
}

// Returns the successor of the given node in the BST
Node* Bst::Successor(Node* sucessee) {
  if (sucessee->right != nullptr) {
    Node* p = new Node;
    p = sucessee->right;
    if (p->left == nullptr) return p;
    while (p->left != nullptr) {
      p = p->left;
    }
    return p;
  } else {
    Node* p = new Node;
    p = sucessee;
    while (p->value > p->Parent->value) {
      p = p->Parent;
    }
    return p->Parent;
  }
}

// Deletes the Node with the Given Key in the BST
void Bst::Delete(int key) {
  Node* temp = Search(root, key);
  if (temp->value != key) {
    return;
  }
  // case 1: it is a leaf
  if (temp->right == nullptr && temp->left == nullptr) {
    if (temp->value > temp->Parent->value) temp->Parent->right = nullptr;
    if (temp->value < temp->Parent->value) temp->Parent->left = nullptr;
  }
  // case 2 : one child
  if (temp->left == nullptr && temp->right != nullptr) {
    temp->Parent->right = temp->right;
    temp->right->Parent = temp->Parent;
  }

  if (temp->right == nullptr && temp->left != nullptr) {
    temp->Parent->left = temp->left;
    temp->left->Parent = temp->Parent;
  }
  // case 3: 2 children
  if (temp->right != nullptr && temp->left != nullptr) {
    Node* p = Successor(temp);
    Node* success = Search(root, p->value);
    int k = temp->value;
    temp->value = success->value;
    success->value += k;
    Delete(success->value);
  }
}

// Displays BST horizantally, Not my Code
void Bst::disp() { display(root, 10); }
void Bst::display(Node* p, int indent) {
  if (p != NULL) {
    if (p->right) {
      display(p->right, indent + 4);
    }
    if (indent) {
      std::cout << setw(indent) << ' ';
    }
    if (p->right) std::cout << " /\n" << setw(indent) << ' ';
    std::cout << p->value << "\n ";
    if (p->left) {
      std::cout << setw(indent) << ' ' << " \\\n";
      display(p->left, indent + 4);
    }
  }
}
