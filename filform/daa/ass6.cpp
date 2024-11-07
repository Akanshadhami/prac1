//Design 8-Queens matrix having first Queen placed. Use backtracking to place remaining 
//Queens to generate the final 8-queen’s matrix

#include <bits/stdc++.h>
using namespace std;

// N will be set by user input
int N; 
vector<vector<int>> board;

// Function to check if placing a queen at (r, c) is safe
bool ispossible(int r, int c) {
    // Check row and column
    for (int j = 0; j < N; j++) {
        if (board[r][j] == 1 || board[j][c] == 1) {
            return false;
        }
    }

    // Check upper left diagonal
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check lower right diagonal
    for (int i = r, j = c; i < N && j < N; i++, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check lower left diagonal
    for (int i = r, j = c; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check upper right diagonal
    for (int i = r, j = c; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Function to print the chessboard
void print() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

// Recursive function to solve the N-Queens problem using backtracking
bool solveNQueens(int r) {
    if (r == N) { // All queens have been placed
        print();
        cout << "\n";
        return true;
    }

    bool hasSolution = false;

    for (int i = 0; i < N; i++) {
        if (board[r][i] == 1) {
            hasSolution |= solveNQueens(r + 1); // Move to next row
        }
        else if (ispossible(r, i)) {
            board[r][i] = 1;          // Place queen
            hasSolution |= solveNQueens(r + 1); // Recur for the next queen
            board[r][i] = 0;          // Backtrack
        }
    }
    
    return hasSolution;
}

int main() {
    cout << "Enter the value of N (Number of queens): ";
    cin >> N;

    // Initialize the NxN board with all 0s
    board = vector<vector<int>>(N, vector<int>(N, 0));

    int r, c;
    cout << "Give Row and Column for first queen (0-based index): ";
    cin >> r >> c;

    // Place the first queen
    board[r][c] = 1;

    // Solve the N-Queens problem starting from the next row
    if (!solveNQueens(0)) {
        cout << "Solution does not exist.\n";
    }

    return 0;
}
