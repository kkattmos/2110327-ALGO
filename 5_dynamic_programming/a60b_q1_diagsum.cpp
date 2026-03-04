// DONE (Bottom-up)
// Diagonal Sum

#include <bits/stdc++.h>
using namespace std;

int matrixSize;
vector<vector<int>> matrix;
vector<vector<int>> memo;

int maxValue = -1e7;

int main() {
    cin >> matrixSize;
    vector<int> tmp(matrixSize, 0);

    matrix.assign(matrixSize, tmp);
    for (int i=0; i<matrixSize; i++) {
        for (int j=0; j<matrixSize; j++) cin >> matrix[i][j];
    }

    memo.assign(matrixSize, tmp);

    for (int j=matrixSize-1; j>=0; j--) {
        for (int i=0; i<matrixSize; i++) {


            if (j+1 == matrixSize || i+1 == matrixSize) memo[i][j] = matrix[i][j];
            else memo[i][j] = max(matrix[i][j], matrix[i][j] + memo[i+1][j+1]);
            maxValue = max(maxValue, memo[i][j]);
        }
    }

    cout << maxValue;
}   
