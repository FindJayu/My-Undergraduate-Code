/*
 * Name: Jack Carson
 * Date Submitted: 4/22/22
 * Lab Section: Section 002
 * Assignment Name: wolfGoatCabbage 
 */

#include <map>
#include <queue>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Reflects what each node represents...
// int with each bit == 0 left of river, bit == 1 right of river
typedef int state; 

// Bit position representation for wolf / goat / cabbage / me
bool bit(int x, int i) { 
  return (x >> i) & 1; // returns 1 if bit i is 1, 0 otherwise
}

const int wolf = 0, goat = 1, cabbage = 2, me = 3;

// GENERIC -- these shouldn't need to be changed...
map<state, bool> visited;         // have we queued up this state for visitation?
map<state, state> pred;           // predecessor state we came from
map<state, int> dist;             // distance (# of hops) from source node
map<state, vector<state>> nbrs;   // vector of neighboring states 

map<pair<state,state>, string> edge_label; // edge labels for each edge between two states

// GENERIC (breadth-first search, outward from curnode)
void search(state source_node) { 
  queue<state> to_visit; // queue of states (int) to visit
  to_visit.push(source_node); // push source node onto queue
  visited[source_node] = true; // mark source node as visited
  dist[source_node] = 0; // set distance to source node to 0
  
  while (!to_visit.empty()) { // while queue is not empty
    state curnode = to_visit.front(); // get next node to visit
    to_visit.pop(); // remove node from queue
    for (state n : nbrs[curnode]) // for each neighbor of curnode
      if (!visited[n]) {  // if neighbor has not been visited
        pred[n] = curnode; // set predecessor of neighbor to curnode
        dist[n] = 1 + dist[curnode]; // set distance to neighbor to 1 + distance to curnode
        visited[n] = true; // mark neighbor as visited
        to_visit.push(n); // push neighbor onto queue
      }
  }
}

string state_string(state s) {
  string items[4] = {"wolf", "goat", "cabbage", "you"}, result = "";
  for (int i = 0; i < 4; i++)
    if (!bit(s, i)) result += items[i] + " "; // if bit i is 0, add item to result
  result += " |river| ";
  for (int i = 0; i < 4; i++)
    if (bit(s, i)) result += items[i] + " "; // if bit i is 1, add item to result
  return result; 
}

// GENERIC
void print_path(state s, state t) {
  if (s != t) { // if source node is not target node
    print_path(s, pred[t]); // print path from source node to predecessor of target node
    cout << edge_label[make_pair(pred[t], t)] << ": " << state_string(t) << "\n"; // print edge label and target node
  } else {
    cout << "Initial state: " << state_string(s) << "\n"; // print source node if target node is source node
  }
}

string neighbor_label(int s, int t) {
  string items[3] = { "wolf", "goat", "cabbage" }, which_cross; 
  if (bit(s,me) == bit(t,me)) return "";  // if me is on same side of river as t, no label
  int cross_with = 0; 
  for (int i = 0; i < 3; i++) {
    if (bit(s,i) != bit(t,i) && bit(s,i) == bit(s,me)) { cross_with++; which_cross = items[i]; } 
    if (bit(s,i) != bit(t,i) && bit(s,i)!= bit(s,me)) return ""; 
  }
  if (cross_with > 1) return ""; // if more than one item crosses, no label
  if (cross_with == 0) return "Cross alone"; // if no items cross, label is "Cross alone"
  else return "Cross with " + which_cross; 
}

// Correct Output                                     Wolf, Goat, Cabbage, You

// Initial state: wolf goat cabbage you  |river|     (0000)
// Cross with goat: wolf cabbage  |river| goat you   (0101)
// Cross alone: wolf cabbage you  |river| goat       (0100)
// Cross with wolf: cabbage |river| wolf goat you    (1101) 
// Cross with goat: goat cabbage you  |river| wolf   (1000)
// Cross with cabbage: goat |river| wolf cabbage you (1011)
// Cross alone: goat you  |river| wolf cabbage       (1010)
// Cross with goat:  |river| wolf goat cabbage you   (1111)

bool validPos(bitset<4> pos) { // Checks if wolf/goat and goat/cabbage positions are valid
  if (pos[wolf] == pos[goat]) { 
    if (pos[me] == pos[wolf] && pos[me] == pos[goat]) {
      return true; // if me is on same side of river as wolf and goat, valid
    }
  }
    
  else if (pos[goat] == pos[cabbage]) {
    if (pos[me] == pos[goat] && pos[me] == pos[cabbage]) {
      return true; // if me is on same side of river as goat and cabbage, valid
    }
  }
  else 
    return true; // if no items cross, valid
  return false; // if wolf/goat and goat/cabbage positions are invalid (you are not on the same side)
}

void build_graph() {
  
  const int items = 4; 

  bitset<items> current_state; // create an empty bitset to represent current state (wolf, goat, cabbage, me) (bitset is an array of bools/bits)
  bitset<items> end("1111"); // create an empty bitset to represent end state (wolf, goat, cabbage, me all set to 1)

  while(current_state != end) { // while current state is not end state
    for (int i = 0; i < items; i++) { // for each item (0 1 2 3)
      if (current_state[me] == current_state[i]) { // if me(3) is on same side of river as item (0 1 2 3)

        bitset<items> next_state = current_state; // create a copy of current state

        next_state[me].flip(); // flip the bit in the last position (me)
        i != me ? next_state[i].flip() : false; // if item is not me, flip the bit in the position of item

        if (validPos(next_state)) { // if next state is valid
          
          int curr = (int)current_state.to_ulong(); // convert current state to int (convert bitset to unsigned long)
          int next = (int)next_state.to_ulong(); // convert next state to int (convert bitset to unsigned long)
          nbrs[curr].push_back(next); // add next state to neighbors of current state
          edge_label[make_pair(curr, next)] = neighbor_label(curr, next); // add edge label to edge label map
        }
      }
    }
    current_state = (int)current_state.to_ulong() + 1; // increment current state
  }
}

int main() {
  build_graph();   

  state start = 0, end = 15;
  
  search(start); // search for shortest path from start node to end node
  if (visited[end]) // if end node has been visited
    print_path (start, end); // print path from start node to end node
  else
    cout << "No path!\n";
  
  return 0;
}
