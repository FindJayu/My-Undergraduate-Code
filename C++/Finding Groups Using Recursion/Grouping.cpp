/*
 * Name: Jack Carson
 * Date Submitted: 14 February 2022
 * Lab Section: Section 002
 * Assignment Name: Finding Groups Using Recursion
 */

#include <vector>
#include <fstream>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Represents an occupied square in the grid
// Do not modify the GridSquare class or its member functions
class GridSquare {
    private:
        int row, col;
    public:
        GridSquare() : row(0), col(0) {} // Default constructor, (0,0) square
        GridSquare(int r, int c) : row(r), col(c) {} // (r,c) square

        // Compare with == operator, used in test cases
        bool operator== (const GridSquare r) const {
            if ((row == r.row) && (col == r.col)) {
                return true;
            }
            return false;
        }

        int getRow() { return row; } // return row value
        int getCol() { return col; } // return column value

        // Output using << operator, used in Grouping::printGroups()
        friend ostream& operator<< (ostream& os, const GridSquare obj);
};

//Function definition for <ostream> << <GridSquare>
ostream& operator<< (ostream& os, const GridSquare obj) {
    os << "(" << obj.row << "," << obj.col << ")";
    return os;
}

/* Groups squares in 10x10 grid upon construction
Additional private helper functions may be added
Need to implement the constructor that takes a file name
as well as findGroup
The findGroup function's parameter list may be changed based
on how the function is implemented */
class Grouping {
    private:
        int grid[10][10];
        vector<vector<GridSquare>> groups;
    public:
        Grouping() : grid{},groups() {} 

        Grouping(string fileName); 
        void findGroup(int r, int c);  

        void printGroups() {
            for(int g = 0; g < groups.size(); g++) {
                cout << "Group " << g+1 << ": ";
                for(int s = 0; s < groups[g].size(); s++) {
                    cout << " " << groups[g][s];
                }
                cout << endl;
            }
        }
        vector<vector<GridSquare>> getGroups() {
            return groups;
        }
        int getGridIndex(int r, int c) {
            return grid[r][c];
        }  
};

Grouping::Grouping(string fileName) {  
    fstream file(fileName); // Open file using fstream

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (file.get() == 46) {
                grid[i][j] = 0; 
            } else {
                grid[i][j] = 1;
            }
            // ignore the newline character
            if (file.peek() == '\n') {
                file.ignore();
            } 
        } // Write 0 or 1 to the grid based on ascii value, and ignore the newline character
    }

    file.close();
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (grid[i][j] == 1) {
                findGroup(i, j);
            }
        }
    } // Iterate the grid and call findGroup for each square that is occupied
}

void Grouping::findGroup(int r, int c) {
    vector<GridSquare> group;
    GridSquare square(r, c);
    group.push_back(square); // Create a group vector and add the current square to it

    grid[r][c] = -1; // Mark the square as visited

    for (int i = 0; i < group.size(); i++) { // Iterate the group vector (Which grows as squares are added)
        int row = group[i].getRow(); // Get the row of the current square
        int col = group[i].getCol(); // Get the column of the current square

        if (row > 0 && grid[row-1][col] == 1) { // Check if the square above the current square is occupied
            grid[row-1][col] = -1;
            GridSquare newSquare(row-1, col);
            group.push_back(newSquare);            
        } // Add the square above the current square to the group if it is occupied

        if (row < 9 && grid[row+1][col] == 1) { // Check if the square below the current square is occupied
            grid[row+1][col] = -1;
            GridSquare newSquare(row+1, col);
            group.push_back(newSquare);
        } // Add the square below the current square to the group if it is occupied

        if (col > 0 && grid[row][col-1] == 1) { // Check if the square to the left of the current square is occupied
            grid[row][col-1] = -1;
            GridSquare newSquare(row, col-1);
            group.push_back(newSquare);
        } // Add the square to the left of the current square to the group if it is occupied

        if (col < 9 && grid[row][col+1] == 1) { // Check if the square to the right of the current square is occupied
            grid[row][col+1] = -1;
            GridSquare newSquare(row, col+1);
            group.push_back(newSquare);
        } // Add the square to the right of the current square to the group if it is occupied
    }

    groups.push_back(group); // Add the group vector to the groups vector
}

//Simple main function to test Grouping
int main() {
    Grouping input1("input1.txt");
    input1.printGroups();

    return 0;
}