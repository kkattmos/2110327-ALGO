// OK
// Checker for Rubik Race Optimization

/*
HOW TO RUN
- Input pattern is the same for actual homework, but include the moves output at the last line of input
- If the final board pattern is correct, it will return "P"
- Otherwise, it will return the final board state
*/

#include <bits/stdc++.h>
using namespace std;

int boardSize, currRow, currCol;
vector<vector<int>> board, target;
string moves;

void printboard() {
    for (int i=0; i<boardSize; i++) {
        for (int j=0; j<boardSize; j++) cout << board[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    cin >> boardSize;
    
    board.assign(boardSize, vector<int>(boardSize, 0));
    target.assign(boardSize-2, vector<int>(boardSize-2, 0));

    for (int i=0; i<boardSize; i++) {
        for (int j=0; j<boardSize; j++) {
            cin >> board[i][j];
            if (board[i][j] == -1) {
                currRow = i;
                currCol = j;
            }
        }
    }

    for (int i=0; i<boardSize-2; i++) {
        for (int j=0; j<boardSize-2; j++) cin >> target[i][j];
    }

    cin >> moves;

    int currMoveIndex = 0;
    while (moves[currMoveIndex] != 'S') {
        //cout << "Pass\n";
        if (moves[currMoveIndex] == 'D') {
            swap(board[currRow][currCol], board[currRow-1][currCol]);
            currRow--;
        }
        else if (moves[currMoveIndex] == 'U') {
            swap(board[currRow][currCol], board[currRow+1][currCol]);
            currRow++;
        }
        else if (moves[currMoveIndex] == 'R') {
            swap(board[currRow][currCol], board[currRow][currCol-1]);
            currCol--;
        }
        else if (moves[currMoveIndex] == 'L') {
            swap(board[currRow][currCol], board[currRow][currCol+1]);
            currCol++;
        }
        currMoveIndex++;
        //printboard();
    }

    for (int i=0; i<boardSize-2; i++) {
        for (int j=0; j<boardSize-2; j++) {
            if (board[i+1][j+1] != target[i][j]) {
                printboard();
                return 0;
            }
        }
    }
    cout << "P";
}