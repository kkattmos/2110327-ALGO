// DONE
// Longest Common Subsequence

#include <bits/stdc++.h>
using namespace std;

string A, B;

int main() {
    cin >> A >> B;

    int lengthA = A.size();
    int lengthB = B.size();

    int memo[lengthA+1][lengthB+1];

    for (int ai=0; ai<=lengthA; ai++) {
        for (int bi=0; bi<=lengthB; bi++) {
            if (ai == 0 || bi == 0) memo[ai][bi] = 0;
            else if (A[ai-1] != B[bi-1]) memo[ai][bi] = max(memo[ai-1][bi], memo[ai][bi-1]);
            else memo[ai][bi] = memo[ai-1][bi-1] + 1;
        }
    }

    //Test Print
    //for (int i=0; i<=lengthA; i++) {
    //    for (int j=0; j<=lengthB; j++) {
    //        cout << memo[i][j] << " ";
    //    }
    //    cout << "\n";
    //}

    cout << memo[lengthA][lengthB];
}