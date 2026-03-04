// DONE
// Jumping with Cost

#include <bits/stdc++.h>
using namespace std;

int length, dist;
vector<int> A, B, memo;

void print() {
    cout << "TEST: ";
    for (const auto &x: memo) cout << x << " ";
    cout << "\n";
}

int main() {
    cin >> length >> dist;

    A.resize(length+1);
    for (int i=1; i<=length; i++) cin >> A[i];

    B.resize(dist+1);
    for (int i=1; i<=dist; i++) cin >> B[i];

    memo.resize(length+1);
    memo[1] = A[1];
    for (int i=2; i<=length; i++) {
        int maxValue = -1e7;
        for (int j=1; j<=dist; j++) {
            if (i-j < 1) break;
            maxValue = max(maxValue, memo[i-j] - B[j]);
        }

        memo[i] = maxValue + A[i];
    }

    //print();
    cout << memo.back();
}