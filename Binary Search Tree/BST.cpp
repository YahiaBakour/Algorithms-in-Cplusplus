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
 * be placed even if there is duplicates*/
Node* Bst::Search(Node* Root, int key) {
  if (root == nullptr)
    return root;
  else if ((Root->value > key && Root->left == nullptr) ||
           (Root->value < key && Root->right == nullptr))
    return Root;  // IF ABOUT TO FALL OFF TREE
  else if (key >= Root->value)
    Search(Root->right, key);
  else if (key < Root->value)
    Search(Root->left, key);
}

/* insert num as a new value to the Bst */
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
