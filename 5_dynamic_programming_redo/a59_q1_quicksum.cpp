// Done
// Quick Sum

#include <bits/stdc++.h>
using namespace std;

int noRows, noCols, noQueries;
vector<vector<int>> A, P;

int main() {
    cin >> noRows >> noCols >> noQueries;

    A.resize(noRows);
    for (int i=0; i<noRows; i++) {
        A[i].resize(noCols);
        for (int j=0; j<noCols; j++) cin >> A[i][j];
    }

    // Defining prefix sum of A
    P.resize(noRows);
    for (int i=0; i<noRows; i++) P[i].resize(noCols);

    P[0][0] = A[0][0];
    for (int c=1; c<noCols; c++) P[0][c] = A[0][c] + P[0][c-1];

    for (int r=1; r<noRows; r++) {
        P[r][0] = A[r][0] + P[r-1][0];
        for (int c=1; c<noCols; c++) P[r][c] = P[r-1][c] + P[r][c-1] - P[r-1][c-1] + A[r][c];
    }

    for (int _=0; _<noQueries; _++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        //  P(r2,c2) – P(r1-1,c2) – P(r2,c1-1) + P(r1-1,c1-1)
        int ans = P[r2][c2];
        if (r1 > 0) ans -= P[r1-1][c2];
        if (c1 > 0) ans -= P[r2][c1-1];
        if (r1 > 0 && c1 > 0) ans += P[r1-1][c1-1];

        cout << ans << "\n";
    }

}
