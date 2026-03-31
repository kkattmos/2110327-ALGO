// DONE (but needs review)
// Rope

#include <bits/stdc++.h>
using namespace std;

int length;
vector<int> sizes, memo;


int main() {
    cin >> length;
    sizes.resize(3);
    for (int i=0; i<3; i++) cin >> sizes[i];

    memo.assign(length+1, -1);
    memo[0] = 0;

    for (int i=1; i<=length; i++) {
        for (const auto &x: sizes) {
            if (i >=x && memo[i-x] != -1) memo[i] = max(memo[i], memo[i-x] + 1);
        }
    }

    cout << memo[length];
}