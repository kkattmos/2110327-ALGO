// DONE
// Longest Common Subsequence

#include <bits/stdc++.h>
using namespace std;

int lengthA, lengthB;
string A, B;

int main() {
    cin >> lengthA >> lengthB >> A >> B;

    int memo[lengthA+1][lengthB+1];
    for (int r=0; r<=lengthA; r++) {
        for (int c=0; c<=lengthB; c++) cin >> memo[r][c];
    }

    vector<int> ans;
    int currRow = lengthA;
    for (int currCol=lengthB; currCol>0; currCol--) {
        if (memo[currRow-1][currCol-1] + 1 == memo[currRow][currCol]) {
            ans.push_back(currCol);
            currRow--;
        }
    }

    for (int i=ans.size()-1; i>=0; i--) cout << B[ans[i]-1];

    
}