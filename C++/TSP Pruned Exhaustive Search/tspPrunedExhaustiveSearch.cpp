/*
 * Name: Jack Carson
 * Date Submitted: 4/27/22
 * Lab Section: Section 002
 * Assignment Name: Pruned Exhaustive Search
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 14;
typedef pair<double,double> Point;
double best_len = 999999999, mindist = 999999;

vector<Point> P(N); 
vector<int> tour(N), best_tour(N); 
vector<bool> used(N);

map<Point, int> cities;

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
                      "Kansas City"};

double dist(int i, int j) {
  double dx = P[(i+N)%N].first - P[(j+N)%N].first;
  double dy = P[(i+N)%N].second - P[(j+N)%N].second;
  return sqrt(dx*dx + dy*dy);
}

double tourlen(vector<int> &T) { // Calculates the length of a tour 
  double total = 0.0;
  for (int i = 0; i < N; i++)
    total += dist(T[i], T[(i+1)%N]); // Add the distance between each city
  return total; // Return the total length of the tour
}

void solve(int index, double so_far) { 
  // base case
  if (index == N) {
    // Bug was here -- had 0 instead of tour[0], etc.
    if (so_far + dist(tour[0],tour[N-1]) < best_len) { // If the tour is shorter than the best length
      best_tour = tour; // Set best tour to current tour
      best_len = so_far + dist(tour[0],tour[N-1]); // Set best length to current length
    }
    return;
  }

  // Can I prune my search?
  if (so_far + mindist * (N-index+1) > best_len) return; // If the length of the tour is too long, prune
  
  // try all possible next cities
  for (int city = 0; city < N; city++) // For each city
    if (!used[city]) { // If the city has not been used
      tour[index] = city; // Add the city to the tour
      used[city] = true; // Mark the city as used
      solve(index+1, so_far + dist(city, tour[index-1])); // Recursively solve the problem
      used[city] = false; // Mark the city as unused
    }
}

int main() {
  ifstream fin("cities.txt");
  for (int i = 0; i < N; i++) { // Read in cities (latitude,longitude)
    fin >> P[i].first >> P[i].second;
    cities[P[i]] = i; // For each city, store its index in the cities.txt file
  }
  tour[0] = 0;  // start at city zero
  used[0] = true; // mark city zero as used
  for (int i = 0; i < N; i++)
    for (int j = i+1; j < N; j++)
      mindist = min(mindist, dist(i,j));
  solve(1, 0.0);
  for (int i = 0; i < N; i++) cout << cityNames[best_tour[i]] << endl;
  cout << "\nTotal length: " << best_len << "\n";
  return 0;
}
