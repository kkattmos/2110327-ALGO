//
// Columbia

#include <bits/stdc++.h>
using namespace std;

int noRows, noCols;

const vector<pair<int, int>> DIRS = {
    {0, 1},
    {1, 0}
};

int main() {
    cin >> noRows >> noCols;

    int matrix[noRows][noCols];
    for (int i=0; i<noRows; i++) {
        for (int j=0; j<noCols; j++) cin >> matrix[i][j];
    }

    int output[noRows][noCols];
    for (int i=0; i<noRows; i++) {
        for (int j=0; j<noCols; j++) output[i][j] = -1;
    }

    for (int i=0; i<noRows; i++) {
        for (int j=0; j<noCols; j++) {
            if (i == 0 && j == 0) output[i][j] = 0;
            else if (i == 0) output[i][j] = output[i][j-1] + matrix[i][j];
            else if (j == 0) output[i][j] = output[i-1][j] + matrix[i][j];
            else output[i][j] = min(output[i-1][j], output[i][j-1]) + matrix[i][j];
        }
    }    

    for (int i=0; i<noRows; i++) {
        for (int j=0; j<noCols; j++) cout << output[i][j] << " ";
        cout << "\n";
    }
}