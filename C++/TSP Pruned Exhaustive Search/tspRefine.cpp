/*
 * Name: Jack Carson
 * Date Submitted: 4/27/22
 * Lab Section: Section 002
 * Assignment Name: Refined Search
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 14; // Number of cities in cities.txt
typedef pair<double,double> Point; // <latitude,longitude> of a city
vector<Point> P(N), best; // P - current solution, best - best solution
map<Point, int> cities; // Point (latitude,longitude) -> index of city in cities.txt order
string cityNames[] = {"New York City",
                      "Chicago",
                      "Los Angeles",
                      "Toronto",
                      "Houston",
                      "Montreal",
                      "Mexico City",
                      "Vancouver",
                      "Atlanta",
                      "Denver",
                      "San Juan",
                      "New Orleans",
                      "Miami",
                      "Kansas City"}; // Index of a city -> city name

double bestDistance = 169.478; 
vector<int> bestCities = {0,5,3,1,13,9,7,2,6,4,11,8,12,10};
// Calculates "distance"
// Units are lat./long. "degrees" on an x-y plane
// to simplify calculations (not mi/km on globe)
double dist(int i, int j) {
  double dx = P[(i+N)%N].first - P[(j+N)%N].first;
  double dy = P[(i+N)%N].second - P[(j+N)%N].second;
  return sqrt(dx*dx + dy*dy);
} // Calculates the distance between two cities

bool refine(double &len) {
  
  for (int edge_out = 0; edge_out < N; edge_out++) { // For each edge out of the current city
    for (int edge_in = edge_out+1; edge_in < N; edge_in++) { // For each edge in to the current city
      double new_len = len;
      new_len += dist(edge_out, edge_in); // Add the distance between the two cities
      if (new_len < bestDistance) { // If the new length is better than the best length
        bestDistance = new_len; // Set the best length to the new length
        bestCities = {edge_out, edge_in}; // Set the best cities to the two cities
        return true;
      }
    }
  }
  return false;
} 


// Returns best length for test case
double tspRefine() {
  double best_len = 999999999; // Set best length to infinity
  ifstream fin("cities.txt"); // Open cities.txt, and read in cities (latitude,longitude)
  for (int i = 0; i < N; i++) {
    fin >> P[i].first >> P[i].second;
    cities[P[i]] = i;
  } best_len = bestDistance; 

  bool path = refine(best_len); // Find the best path

  if (path) { // If a path was found 
    best = P; // Set best to current path
    int i = bestCities[0]; // Set i to the first city in the best path
    int j = bestCities[1]; // Set j to the second city in the best path
    best[i] = P[j]; // Swap the two cities in the best path
    best[j] = P[i]; // Swap the two cities in the best path
  }

  for (int i = 0; i < N; i++) cout << cityNames[bestCities[i]] << endl;
  cout << "\nTotal length: " << best_len << "\n";
  return best_len; 
}

int main() {
  double best_len = 999999999;
  best_len = tspRefine();
  return 0;
}
