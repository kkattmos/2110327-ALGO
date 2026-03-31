// Done
// Binomial Coefficient

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> matrix;

void print() {
    cout << "\n";
    for (const auto &x: matrix) {
        for (const auto &y: x) cout << y << " ";
        cout << "\n";
    }
}

int main() {
    cin >> n >> k;
    
    matrix.resize(n+1);
    for (int i=0; i<=n; i++) {
        matrix[i].assign(k+1, 0);
        matrix[i][0] = 1;
        if (i <= k) matrix[i][i] = 1;
    }

    for (int ki=1; ki<=k; ki++) {
        for (int ni=2; ni<=n; ni++) {
            matrix[ni][ki] = matrix[ni-1][ki-1] + matrix[ni-1][ki];
            //cout << "Writing: " << ni << " " << ki << "\n";
            //print();
        }
    }

    //print();
    cout << matrix[n][k];
}