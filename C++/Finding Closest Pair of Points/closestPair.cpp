/*
 * Name: Jack Carson
 * Date Submitted: 3/8/2022
 * Lab Section: Section 002
 * Assignment Name: Finding the Closest Pair of Points
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

struct point {
  double x;
  double y;
};


double closestPair(string filename); // Function to find the closest pair of points
bool distFound(point,point, set< vector< point >>); // Function to check if the distance between two points is less than the current closest distance
double checkGroups(point, vector< point >&, set< vector< point >>); // Function to check the groups of points

int main() {
    double min;
    string filename;
    cout << "File with list of points within unit square: ";
    cin >> filename;
    min = closestPair(filename);
    cout << setprecision(16);
    cout << "Distance between closest pair of points: " << min << endl;
    return 0;
}

double closestPair(string filename) {

  ifstream input (filename);

  int numPoints = 0;
  input >> numPoints;
  int b = sqrt(numPoints); // Number of points in each group
  // This b is chosen to be the square root because the number of points in each group is the square root of the total number of points (log(n))


  vector< vector< vector< point>>> grid(b, vector<vector< point>>(b)); // Create a grid of points
        
  for(int i = 0; i < numPoints; i++) {
    point current;
    current.x = 0;
    current.y = 0;
    input >> current.x;
    input >> current.y; // input the x and y coordinates of the current point

    int xHash = (int)(current.x * b);
    int yHash = (int)(current.y * b); // Hash the x and y coordinates of the current point

    grid[xHash][yHash].push_back(current); // Add the current point to the grid
    }

                
    double min = 1; // Initialize the minimum distance to 1
    set< vector< point>> checkedPoints; // Create a set of points that have been checked

    for(int i = 0; i < b; i++) { // Loop through the rows of the grid
      for(int j = 0; j < b; j++) { // Loop through the columns of the grid
        for(auto currentPoint : grid[i][j]) { // Loop through the points in the current row and column
          double temp = checkGroups( currentPoint, grid[i][j], checkedPoints); // Check the groups of points around the current point
          double compare = 2; // Initialize the compare value to 2
                                
          if(j != 0) { // Check the left column
            compare = checkGroups( currentPoint, grid[i][j-1], checkedPoints); // Check the groups of points around the current point
            temp = (compare<temp)? compare:temp; // Compare the current minimum distance to the new minimum distance
                                        
            if( i != (b-1)) { // Check the bottom row
              compare = checkGroups( currentPoint, grid[i+1][j-1], checkedPoints);
              temp = (compare<temp)? compare:temp; 
            }
          } 
                                
          if(j != (b - 1)) { // Check the right column
            compare = checkGroups( currentPoint, grid[i][j+1], checkedPoints);
            temp = (compare<temp)? compare:temp;
                                        
            if( i != (b-1)) { // Check the bottom row
              compare = checkGroups( currentPoint, grid[i+1][j+1], checkedPoints);
              temp = (compare<temp)? compare:temp;
            }
          }
                                 
          if(i != 0) { // Check the top row
            compare = checkGroups( currentPoint, grid[i-1][j], checkedPoints);
            temp = (compare<temp)? compare:temp;
                                        
            if(j != 0) { // Check the left column
              compare = checkGroups( currentPoint, grid[i-1][j-1], checkedPoints);
              temp = (compare<temp)? compare:temp;
            }
                                        
            if(j != (b-1)) { // Check the right column
              compare = checkGroups( currentPoint, grid[i-1][j+1], checkedPoints);
              temp = (compare<temp)? compare:temp;
            }
          }       
                                
            if(i != (b - 1)) { // Check the bottom row
              compare = checkGroups( currentPoint, grid[i+1][j], checkedPoints);
              temp = (compare<temp)? compare:temp;
            }
            
            if(temp < min) 
              min = temp; // Update the minimum distance if the new distance is less than the current minimum distance
          }
        }
      }
  return min; 
}

// distFound function to check if the distance between two points is less than the current closest distance
bool distFound(point l, point r, set< vector< point >> group) {
        
  vector<point> sideOne = {l,r}; 
  vector<point> sideTwo = {r,l}; // Create two sides of the line
  auto one = group.find(sideOne); 
  auto two = group.find(sideTwo); // Check if the two points are in the same group

  if(one != group.end() || two != group.end()) { // If the two points are in the same group
    return true;
  } 
  return false;
}

// checkGroups function to check the groups of points around the current point
double checkGroups(point current, vector< point > &group, set< vector< point >> checked) {
  double min = 2; // Initialize the minimum distance to 2

  for(auto points : group) {
                
    if(points.x == current.x && points.y == current.y) { // If the current point is the same as the point being checked, skip
      continue; 
    }
                
    if(!distFound(current, points, checked)) { // If the distance between the current point and the point being checked is less than the current minimum distance

      vector< point > newVec(2, current); // Create a vector of the current point and the point being checked
      newVec[1] = points; 
      checked.insert( newVec ); 
      double xDiff = current.x - points.x;
      double yDiff = current.y - points.y;
      double dist = sqrt( pow(xDiff,2) + pow(yDiff,2)); // Calculate the distance between the current point and the point being checked
                        
      if(dist < min) { // If the distance is less than the current minimum distance, set the minimum distance to the new distance
        min = dist;
      }                        
    }
  }
  return min;
}

// Overloaded operator for comparing the distance between two points
inline bool operator<(const point& lhs, const point& rhs) {
  if( lhs.x < rhs.x) {
    if( lhs.y < rhs.y)
      return true;
  }
  return false;
}