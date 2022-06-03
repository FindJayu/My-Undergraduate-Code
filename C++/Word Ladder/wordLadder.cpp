#include <bits/stdc++.h>
using namespace std;

vector<string> V; // words from wordlist05.txt
// Global variables for bfs distance, bfs predecessor, and neighboring nodes
// Should be unordered_map type
unordered_map<string, bool> visited; // visited nodes
unordered_map<string, string> pred; // predecessor of each node
unordered_map<string, int> dist; // distance of each node from source
unordered_map<string, vector<string>> nbrs; // neighboring nodes

int path_finder(string, string, vector<string> &); // bfs
void build_graph(); // build graph (similar to lab 10)

void wordLadder(string s, string t, int &steps, vector<string> &p) { 
  build_graph(); // Build graph (add all words and their neighbors)

  queue<string> to_visit; // queue of nodes to visit
  to_visit.push(s); // add source node to queue 
  visited[s] = true; // mark source node as visited
  dist[s] = 0; // set distance to source node to 0

  while (!to_visit.empty()) { // While there are still nodes to visit
    string curnode = to_visit.front(); // get current node & pop
    to_visit.pop();
    for (string n : nbrs[curnode]) { // iterate through neighbors of current node
      if (!visited[n]) { // if neighbor is not visited
        pred[n] = curnode; // set predecessor of neighbor to current node
        dist[n] = dist[curnode] + 1; // set distance of neighbor to current node + 1
        visited[n] = true; // mark neighbor as visited
        to_visit.push(n); // add neighbor to queue
      }
    }
  }

  steps = path_finder(s, t, p); // find path from source to target

}

int path_finder(string start, string end, vector<string> &p) { // bfs
  if (pred.find(end) == pred.end()) return 0; // no path if end not found

  if (start.compare(end) != 0 ) { 
    int step = 1 + path_finder(start, pred[end], p); // recursive call to find path from node to predecessor
    p.push_back(end); // add end to path
    return step; 
  }

  else {
    p.push_back(end); // add end to path
    return 0;
  }
}

void build_graph() { // Adds all words in V to nbrs and add neighbors to each word (differ by 1 letter)
  ifstream file("wordlist05.txt");
  string current_word; 

  while (file >> current_word) { // While there are still words in the file, add words to V
    V.push_back(current_word);
  }

  for (auto word : V) { // For each word in V, add all words that differ by one letter to nbrs
    for (int place = 0; place < word.length(); place++) { 
      for (char letter = 'a'; letter <= 'z'; letter++) {
        if (letter == word.at(place)) continue; // Continue if the letter is the same as the current letter (already in the word)
        string current = word;  
        current.at(place) = letter; // Change the current letter to the letter in the for loop
        nbrs[word].push_back(current); // Add the current word to the neighboring nodes of the word in the for loop
      }
    }
  }
}


int main() {
  int steps = 0;
  string s, t;
  vector<string> path;
  
  cout << "Source: ";
  cin >> s;

  cout << "Target: ";
  cin >> t;

  wordLadder(s, t, steps, path);

  if (steps == 0) {
      cout << "No path!\n";
  }
  else {
      cout << "Steps: " << steps << "\n\n";
      for (int i=0; i<path.size(); i++) {
        cout << path[i] << endl;
      }
  }
}
