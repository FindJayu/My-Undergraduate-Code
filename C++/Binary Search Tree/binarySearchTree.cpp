/*
 * Name: Jack Carson
 * Date Submitted: 4/1/2022
 * Lab Section: Section 002
 * Assignment Name: Binary Search Tree
 */

#include <vector>
#include <cstdlib>
#include <iostream>
#include <assert.h>
#include <algorithm>
using namespace std;

struct Node {
  int key;
  int size;
  Node *left;
  Node *right;
  Node (int k) { 
    key = k; 
    size = 1; 
    left = right = nullptr; 
  }
};

void fix_size(Node *T) { // Change the size of the tree to reflect the number of nodes in the subtree rooted at T
  T->size = 1;
  if (T->left) T->size += T->left->size; // Add the size of the left subtree
  if (T->right) T->size += T->right->size; // Add the size of the right subtree
}

// insert key k into tree T, returning a pointer to the resulting tree
Node *insert(Node *T, int k) {
  if (T == nullptr) return new Node(k); // Insert key k into empty tree
  if (k < T->key) T->left = insert(T->left, k); // Insert key into left subtree if less than root
  else T->right = insert(T->right, k); // Insert key into right subtree if greater than root
  fix_size(T); // Update the size of the tree

  return T; // Return the new tree
}

// returns a vector of key values corresponding to the inorder traversal of T (i.e., the contents of T in sorted order)
vector<int> inorder_traversal(Node *T) {
  vector<int> inorder;
  vector<int> rhs;
  if (T == nullptr) return inorder; // Return empty vector if T is empty

  inorder=inorder_traversal(T->left); // Add the contents of the left subtree to the vector
  inorder.push_back(T->key); // Add the root to the vector
  rhs=inorder_traversal(T->right); // Add the contents of the right subtree to the vector
  inorder.insert(inorder.end(), rhs.begin(), rhs.end()); // Add the contents of the right subtree to the vector
  return inorder; // Return the vector
}

// return a pointer to the node with key k in tree T, or nullptr if it doesn't exist
Node *find(Node *T, int k) {
  if (T == nullptr) return nullptr; // Return nullptr if T is empty
  if (T->key == k) return T; // Return T if the root is the key
  if (k < T->key) return find(T->left, k); // Search the left subtree if the key is less than the root
  if (k > T->key) return find(T->right, k); // Search the right subtree if the key is greater than the root

  return nullptr; // Return nullptr if the key is not in the tree  
}

// return pointer to node of rank r (with r'th largest key; e.g. r=0 is the minimum)
Node *select(Node *T, int r) {
  vector<int> inorder = inorder_traversal(T);
  return find(T, inorder[r]); // Sort with inorder_traversal and return the node with the r'th largest key
}

// Join trees L and R (with L containing keys all <= the keys in R)
// Return a pointer to the joined tree.  
Node *join(Node *L, Node *R) {
  if (L == nullptr) return R; // Return R if L is empty
  if (R == nullptr) return L; // Return L if R is empty

  if (rand() % (L->size + R->size) < L->size) { // If the size of L is greater than the size of R
    L->right = join(L->right, R); // Join the right subtree of L with R
    fix_size(L); 
    return L; 
  } 

  else { // If the size of L is less than the size of R
    R->left = join(L, R->left); // Join L with the left subtree of R
    fix_size(R); 
    return R; 
  }
  return nullptr;
}

// remove key k from T, returning a pointer to the resulting tree.
// it is required that k be present in T
Node *remove(Node *T, int k) {
  assert(T != nullptr);
  
  if (k < T->key) T->left = remove(T->left, k); // Remove key from left subtree if less than root
  else if (k > T->key) T->right = remove(T->right, k); // Remove key from right subtree if greater than root

  else { // If the key is the root
    if (T->left == nullptr) return T->right; // Return the right subtree if the left subtree is empty
    if (T->right == nullptr) return T->left; // Return the left subtree if the right subtree is empty

    Node *L = T->left; // Get the left subtree
    Node *R = T->right; // Get the right subtree

    while (R->left != nullptr) R = R->left; // Find the smallest key in the right subtree

    T->key = R->key; // Replace the root with the smallest key in the right subtree
    T->right = remove(T->right, R->key); // Remove the smallest key in the right subtree from the right subtree
  }  
  fix_size(T); // Update the size of the tree
  return T; // Return the new tree
}


// Split tree T on key k into tree L (containing keys <= k) and a tree R (containing keys > k)
void split(Node *T, int k, Node **L, Node **R) {

  if (T == nullptr) { // If T is empty
    *L = nullptr; // Set L to nullptr
    *R = nullptr; // Set R to nullptr
    return; // Return
  }
  if (k < T->key) { // If the key is less than the root
    split(T->left, k, L, &T->left); // Split the left subtree
    *R = T; // Set R to T
  } else { // If the key is greater than or equal to the root
    split(T->right, k, &T->right, R); // Split the right subtree
    *L = T; // Set L to T
  }
  fix_size(T); // Update the size of the tree

  return;
}

Node *insert_random(Node *T, int k) {
  if (T == nullptr) { // If T is empty
    T = insert(T, k); // Create a new node with key k
    T->size = 1; // Set the size of T to 1
    return T; // Return T
  }

  if (rand() % (T->size + 1) == 0) { // If the size of T is greater than 0 and the random number is 0
    T = insert(T, k); // Create a new node with key k and T as the left subtree
    return T; // Return T
  }

  fix_size(T); // Update the size of T
  if (k < T->key) T->left = insert_random(T->left, k); // Insert k recursively left of the root of T
  else T->right = insert_random(T->right, k); // Insert k recursively right of the root of T
  return T; // Return T
}

void printVector(vector<int> v) {
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << endl;
    }
}


int main(void) {
 
  vector<int> inorder;
  vector<int> A(10,0);
  
  // put 0..9 into A[0..9] in random order
  for (int i=0; i<10; i++) A[i] = i;
  for (int i=9; i>0; i--) swap(A[i], A[rand()%i]);
  cout << "Contents of A (to be inserted into BST):\n";
  printVector(A);
  
  // insert contents of A into a BST
  Node *T = nullptr;
  for (int i=0; i<10; i++) T = insert(T, A[i]);
  
  // print contents of BST (should be 0..9 in sorted order)
  cout << "Contents of BST (should be 0..9 in sorted order):\n";
  inorder=inorder_traversal(T);
  printVector(inorder);

  // test select
  for (int i=0; i<10; i++) {
    Node *result = select(T, i);
    if (!result || result->key != i) cout << "Select test failed for select(" << i << ")!\n";
  }

  // test find: Elements 0..9 should be found; 10 should not be found
  cout << "Elements 0..9 should be found; 10 should not be found:\n";
  for (int i=0; i<11; i++) {
    if (find(T,i)) cout << i << " found\n";
    else cout << i << " not found\n";
  }

  // test split
  Node *L, *R;
  split(T, 4, &L, &R);


  cout << "Contents of left tree after split (should be 0..4):\n";
  inorder=inorder_traversal(L);
  printVector(inorder);
  cout << "Left tree size " << L->size << "\n";
  cout << "Contents of right tree after split (should be 5..9):\n";
  inorder=inorder_traversal(R);
  printVector(inorder);
  cout << "Right tree size " << R->size << "\n";
    
  // test join
  T = join(L, R);
  cout << "Contents of re-joined tree (should be 0..9)\n";
  inorder=inorder_traversal(T);
  printVector(inorder);
  cout << "Tree size " << T->size << "\n";
  
  // test remove
  for (int i=0; i<10; i++) A[i] = i;
  for (int i=9; i>0; i--) swap(A[i], A[rand()%i]);
  for (int i=0; i<10; i++) {
    T = remove(T, A[i]);
    cout << "Contents of tree after removing " << A[i] << ":\n";
    inorder=inorder_traversal(T);
    printVector(inorder);
    if (T != nullptr)
      cout << "Tree size " << T->size << "\n";
  }

  // test insert_random
  cout << "Inserting 1 thousand elements in order; this should be very fast...\n";
  for (int i=0; i<1000; i++) T = insert_random(T, i);
  cout << "Tree size " << T->size << "\n";
  cout << "Done\n";

  return 0;
}
