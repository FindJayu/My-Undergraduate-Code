/*
 * Name: Jack Carson
 * Date Submitted: 4/2/2022
 * Lab Section: Section 002
 * Assignment Name: Storing a Sequence in a Binary Tree
 */

#include <math.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <assert.h>

using namespace std;

struct Node {
  int key;
  int size;
  Node *left;
  Node *right;
  Node (int k) { key = k; size = 1; left = right = nullptr; }
};

void fix_size(Node *T) {
  T->size = 1;
  if (T->left) T->size += T->left->size; // size of left subtree
  if (T->right) T->size += T->right->size; // size of right subtree
}

// insert value v at rank r
Node *insert(Node *T, int v, int r) {

  if (T == nullptr) return new Node(v); // empty tree
  int currentRank = T->left ? T->left->size : 0; // rank of current node

  if (currentRank >= r) T->left = insert(T->left, v, r); // insert in left subtree if r is less than currentRank
  else T->right = insert(T->right, v, r - currentRank - 1); // insert in right subtree if r is greater than currentRank

  fix_size(T);
  return T;
}


// returns a vector of key values corresponding to the inorder traversal of T (i.e., the contents of T in sorted order)
vector<int> inorder_traversal(Node *T) {
  vector<int> inorder;
  vector<int> rhs;
  if (T == nullptr) return inorder; // empty tree
  inorder = inorder_traversal(T->left); // inorder traversal of left subtree
  inorder.push_back(T->key); // add current node to inorder traversal
  rhs=inorder_traversal(T->right); // inorder traversal of right subtree
  inorder.insert(inorder.end(), rhs.begin(), rhs.end()); // add right subtree to inorder traversal
  return inorder;
}

// return pointer to node of rank r (with r'th largest key; e.g. r=0 is the minimum)
Node *select(Node *T, int r) {
  assert(T!=nullptr && r>=0 && r<T->size);

  int rank_of_root = T->left ? T->left->size : 0; // get the rank of the root
  if (r == rank_of_root) return T; // if r is the rank of the root, return the root
  if (r < rank_of_root) return select(T->left, r); // if r is less than the rank of the root, search the left subtree
  else return select(T->right, r - rank_of_root - 1); // if r is greater than the rank of the root, search the right subtree
}

// Split tree T on rank r into tree L (containing ranks < r) and 
// a tree R (containing ranks >= r)
void split(Node *T, int r, Node **L, Node **R) {
 
  // Base case
  if (T == nullptr) {
    *L = *R = nullptr;
    return;
  }
  int currentRank = T->left ? T->left->size : 0; // rank of current node

  if (currentRank < r) {
    split(T->right, r - currentRank - 1, &T->right, R);
    *L = T;
  } // if current rank is less than r, split the right subtree
  else {
    split(T->left, r, L, &T->left);
    *R = T;
  } // if current rank is greater than r, split the left subtree
  fix_size(T);
}

// insert value v at rank r
Node *insert_random(Node *T, int v, int r) {
  // If (v,r) is the Nth node inserted into T, then:
  // with probability 1/N, insert (v,r) at the root of T
  // otherwise, insert_random (v,r) recursively left or right of the root of T
  
  if (T == nullptr) return new Node(v);

  bool prob = rand() % T->size == 0; // probability of inserting at root

  int currentRank = T->left ? T->left->size : 0; // rank of current node *T*

  if (prob) {
    Node *L, *R;
    Node * newRoot = new Node(v);
    L = R = nullptr;

    split(T, r, &L, &R); // split T into L and R
    newRoot->left = L; // set left subtree of new root to L
    newRoot->right = R; // set right subtree of new root to R
    fix_size(newRoot); 
    return newRoot;
  }

  if (r > currentRank) T->right = insert_random(T->right, v, r - currentRank - 1); // insert_random recursively right of root
  else T->left = insert_random(T->left, v, r); // insert_random recursively left of root

  fix_size(T);
  return T;

}

// Returns true if team x defeated team y
// Leave this function unmodified
bool did_x_beat_y(int x, int y) {
  assert (x != y);
  if (x > y) return !did_x_beat_y(y,x);
  unsigned long long lx = x;
  unsigned long long ly = y;
  return ((17 + 8321813 * lx + 1861 * ly) % 1299827) % 2 == 0;
}

int binarySearch(Node *T, int v) { // helper function to return rank of v in T
  bool placed = false; // whether or not v has been placed in T
  int low = 0, high = T->size - 1; // low and high indices of T
  int mid = 0; // midpoint of T

  while (!placed) {
    mid = floor((low + high) / 2);
    if (high - low == 1) {
      placed = true; 
      return high; 
    } // if there is only one element in T, return the index of that element
    else if (did_x_beat_y(v, select(T, mid)->key)) {
      high = mid; 
    } // if v beats the midpoint, set high to mid
    else low = mid; // if v is less than the midpoint, set low to mid
  }
  return mid;
}

// Return a BST containing a valid ordering of n teams
Node *order_n_teams(int n) {
  Node *T = nullptr;

  // start by inserting the first team
  T = insert_random(T, 0, 0);

  // now insert the other teams...
  for (int i=1; i<n; i++) {
    // insert team i so the sequence encoded by the BST remains valid
    if (did_x_beat_y(i, select(T,0)->key)) // can we insert at beginning?
      T = insert_random(T, i, 0);
    else if (did_x_beat_y(select(T,T->size-1)->key, i)) // can we insert at end?
	    T = insert_random(T, i, T->size);
    else {
      T = insert_random(T, i, binarySearch(T, i)); // can we insert anywhere else?
      // if not, insert at the end
	    // 7 5 4 2 0 3 1 6    (when inserting team i=8)
	    // W W W L L L W L
    }
  }
  return T;
}

void printVector(vector<int> v) {
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << endl;
    }
}

int main(void) {
  vector<int> inorder;
  Node *T = nullptr;

  // test insert at beginning
  for (int i=0; i<5; i++)
    T = insert(T, i+1, 0);
  cout << "Tree should contain 5 4 3 2 1:\n";
  inorder=inorder_traversal(T);
  printVector(inorder);

  // test insert at end
  for (int i=5; i<10; i++)
    T = insert(T, i+1, T->size);
  cout << "Tree should contain 5 4 3 2 1 6 7 8 9 10:\n";
  inorder=inorder_traversal(T);
  printVector(inorder);
  
  // test insert at middle
  for (int i=10; i<15; i++)
    T = insert(T, i+1, T->size/2);
  cout << "Tree should contain 5 4 3 2 1 12 14 15 13 11 6 7 8 9 10:\n";
  inorder=inorder_traversal(T);
  printVector(inorder);
    
  // once insert is working, the next step is to build the
  // insert_random function -- to test this, just change
  // calls to insert above to insert_random.

  int N = 100000; // this should run quickly even for very large N!
  Node *S = order_n_teams(N);
  if (S == nullptr || S->size != N)
    cout << "Size of tree returned by order_n_teams is wrong\n";
  else {
    cout << "Team ordering:\n";
    //    inorder=inorder_traversal(S);
    //    printVector(inorder);
    for (int i=0; i<N-1; i++) {
      Node *x = select(S, i);
      Node *y = select(S, i+1);
      if (!did_x_beat_y(x->key, y->key)) {
        cout << "Invalid sequence: team " << x->key << " (position " << i <<
	              ") lost to team " << y->key << " (position " << i+1 << ")\n";
      }
    }
  }  
  return 0;
}
