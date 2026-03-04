//
// Quick Sum

#include <bits/stdc++.h>
using namespace std;

int noRows, noCols, noPairs;
int r1, c1, r2, c2;
vector<vector<int>> arry, memo;

int main() {
    cin >> noRows >> noCols >> noPairs;

    arry.resize(noRows);
    for (int i=0; i<noRows; i++) {
        arry[i].resize(noCols);
        for (int j=0; j<noCols; j++) cin >> arry[i][j];
    }

    //Prefix sum
    memo.resize(noRows);
    for (int i=0; i<noRows; i++) memo[i].resize(noCols);

    memo[0][0] = arry[0][0];
    for (int col=1; col<noCols; col++) memo[0][col] = memo[0][col-1] + arry[0][col];

    for (int row=1; row<noRows; row++) {
        memo[row][0] = memo[row-1][0] + arry[row][0];
        for (int col=1; col<noCols; col++) memo[row][col] = memo[row-1][col] + memo[row][col-1] - memo[row-1][col-1] + arry[row][col];
    }

    //Calculating block summation
    for (int i=0; i<noPairs; i++) {
        cin >> r1 >> c1 >> r2 >> c2;

        int result = memo[r2][c2];
        if (r1 > 0) result -= memo[r1-1][c2];
        if (c1 > 0) result -= memo[r2][c1-1];
        if (r1 > 0 && c1 > 0) result += memo[r1-1][c1-1];
        
        cout << result << "\n";
    }


}