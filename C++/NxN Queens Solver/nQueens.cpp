/*
 * Name: Jack Carson
 * Date Submitted: 4/16/22
 * Lab Section: Section 002
 * Assignment Name: n Queens Problem
 */

#include <bits/stdc++.h>
using namespace std;

int Solutions = 0;

bool isSafe(vector<vector<int>>board, int row, int col) {

int n = board.size();

// Checks column for queens (|)    
for (int i = 0; i < row; i++){
    if (board[i][col] == 1) {
        return false; // If there is a queen in the column, return false
    }
}

// Checks right diagonal for queens (\)
for (int i = row, x = col; i >= 0 && x >= 0; i--, x--){
    if (board[i][x] == 1) {
        return false; // Returns false if the queen is in the top right diagonal
    }
}

for (int i = row, x = col; i < n && x < n; i++, x++){
    if (board[i][x] == 1) {
        return false; // Returns false if the queen is in the bottom right diagonal
    }
}

// Checks left diagonal for queens (/)
for (int i = row, x = col; i < n && x >= 0; i++, x--){
    if (board[i][x] == 1) {
        return false; // Returns false if the queen is in the top left diagonal
    }
}

for(int i = row, x = col; i >= 0 && x < n; i--, x++){
    if (board[i][x] == 1) {
        return false; // Returns false if the queen is in the bottom left diagonal
    }
}

// Returns true once all conditions are met for queen to be safe
return true;
}

void nQueensSolution(vector<vector<int>>board, int row, int n) {
    // Base case, adds to number of solutions if queens are placed successfully
    if (row == n) {
        Solutions++; // Adds to number of solutions if queens are placed successfully
        return; 
    }
    
    // Places a queen in the square if it is safe
    for(int i = 0; i < n; i++) {
        if(isSafe(board, row, i) == true) {
            
            // Places queen in the square
            board[row][i] = 1;
            
            // Recursive call to place the next queen in the next row
            nQueensSolution(board, row + 1, n);
            
            // Backtrack to try the other squares in current row
            board[row][i] = 0;
        }
    }
}

int nQueens(int n) {
    int row = 0;
    Solutions = 0;

    vector<vector<int>>board(n, vector<int>(n)); // Creates a 2D array of size n x n (all zeros)
    nQueensSolution(board, row, n); 
    return Solutions;
}

int main() {
    cout << nQueens(12) << endl;
    return 0;
}