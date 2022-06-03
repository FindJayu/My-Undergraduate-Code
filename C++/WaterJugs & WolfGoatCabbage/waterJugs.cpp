/*
 * Name: Jack Carson
 * Date Submitted: 4/22/22
 * Lab Section: Section 002
 * Assignment Name: waterJugs
 */

#include <map>
#include <queue>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Reflects what each node represents...
// First value units of water in A, second units of water in B
typedef pair<int,int> state;

// Each string in edge_label must be one of the following:
const string actions[] = {"Fill A",
                          "Fill B",
                          "Empty A",
                          "Empty B",
                          "Pour A->B",
                          "Pour B->A"};

// GENERIC -- these shouldn't need to be changed...
map<state, bool> visited;         // have we queued up this state for visitation?
map<state, state> pred;           // predecessor state we came from
map<state, int> dist;             // distance (# of hops) from source node
map<state, vector<state>> nbrs;   // vector of neighboring states

map<pair<state,state>, string> edge_label; // edge label

// GENERIC (breadth-first search, outward from source_node)
void search(state source_node) {
  queue<state> to_visit; // queue of states (int) to visit
  to_visit.push(source_node); // push source node onto queue
  visited[source_node] = true; // mark source node as visited
  dist[source_node] = 0; // set distance to source node to 0
  
  while (!to_visit.empty()) { // while queue is not empty
    state curnode = to_visit.front(); // get next node to visit
    to_visit.pop(); // remove node from queue
    for (state n : nbrs[curnode]) // for each neighbor of curnode
      if (!visited[n]) { 
	      pred[n] = curnode; // set predecessor of neighbor to curnode
	      dist[n] = 1 + dist[curnode]; // set distance to neighbor to 1 + distance to curnode
	      visited[n] = true; // mark neighbor as visited
	      to_visit.push(n); // push neighbor onto queue
      }
  }
}

// GENERIC
void print_path(state s, state t) {
  if (s != t) { // if s is not the target node
    print_path(s, pred[t]); // print path from s to predecessor of t
    cout << edge_label[make_pair(pred[t], t)] << ": " << "[" << t.first << "," << t.second << "]\n"; // print edge label from predecessor of t to t
  } else {
    cout << "Initial state: " << "[" << s.first << "," << s.second << "]\n";
  }
}

// Correct Output (Bucket A has a limit of 3 units) (Bucket B has a limit of 4 units) 

// Initial state: [0,0]
// Fill B: [0,4]
// Pour B->A: [3,1]
// Empty A: [0,1]
// Pour B->A: [1,0]
// Fill B: [1,4]

void build_graph() {

  state current_state = make_pair(0,0); // initial state
  int A = 3, B = 4; // limits of buckets
  state end = make_pair(A,B); // Pair with the limits of the buckets

  while(current_state != end) {
    state next; 

    next = make_pair(A, current_state.second); // fill bucket A

    if (next != current_state) { 
      pair<state,state> edge = make_pair(current_state, next);  // make pair of current state and next state
      nbrs[current_state].push_back(next); // add next to neighbors of current state
      edge_label[edge] = actions[0]; // set edge label to action
    }

    next = make_pair(current_state.first, B); // fill bucket B

    if (next != current_state) { 
      pair<state,state> edge = make_pair(current_state, next);
      nbrs[current_state].push_back(next); // add next to neighbors of current state
      edge_label[edge] = actions[1]; // set edge label to action
    }

    next = make_pair(0, current_state.second); // empty bucket A

    if (next != current_state) { 
      pair<state,state> edge = make_pair(current_state, next);
      nbrs[current_state].push_back(next); // add next to neighbors of current state
      edge_label[edge] = actions[2]; // set edge label to action
    }

    next = make_pair(current_state.first, 0); // empty bucket B

    if (next != current_state) {
      pair<state,state> edge = make_pair(current_state, next);
      nbrs[current_state].push_back(next); // add next to neighbors of current state
      edge_label[edge] = actions[3]; // set edge label to action
    }

    int newA = current_state.first; // pour bucket A into bucket B
    int newB = current_state.second; // pour bucket B into bucket A

    // Pour bucket A into bucket B
    if (current_state.second < B) {  // if bucket B is not full
      while (newA > 0 && newB < B) { // while bucket A is not empty and bucket B is not full
        newB++; // Add water to bucket B
        newA--; // Remove water from bucket A
      }
      next = make_pair(newA, newB); // set next state to new state

      if (next != current_state) { 
        pair<state,state> edge = make_pair(current_state, next); 
        nbrs[current_state].push_back(next); // add next to neighbors of current state
        edge_label[edge] = actions[4]; // set edge label to action
      }
    }

    newA = current_state.first; 
    newB = current_state.second; 

    // Pour bucket B into bucket A
    if (current_state.first < A) { // if bucket A is not full
      while (newA < A && newB > 0) { // while bucket A is not full and bucket B is not empty
        newA++; // Add water to bucket A
        newB--; // Remove water from bucket B
      }
      next = make_pair(newA, newB); // set next state to new state

      if (next != current_state) {
        pair<state,state> edge = make_pair(current_state, next);
        nbrs[current_state].push_back(next); // add next to neighbors of current state
        edge_label[edge] = actions[5]; // set edge label to action
      }
    }

    if (current_state.second == B) // if bucket B is full
      current_state = make_pair(current_state.first + 1, 0); // move to next state (bucket A)
    else 
      current_state = make_pair(current_state.first, current_state.second + 1); // move to next state (bucket B)
  }
}

int main() {
  build_graph(); 

  state start = make_pair(0,0); // start state
  
  for (int i=0; i<5; i++) 
    nbrs[make_pair(i,5-i)].push_back(make_pair(-1,-1)); // add sink state to nbrs of each state
  search (start); // search for shortest path from start state to sink state
  if (visited[make_pair(-1,-1)]) // if sink state is visited
    print_path (start, pred[make_pair(-1,-1)]); // print path from start state to sink state
  else
    cout << "No path!\n";
  
  return 0;
}
