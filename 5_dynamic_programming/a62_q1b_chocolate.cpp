// DONE 
// Chocolate

#include <bits/stdc++.h>
using namespace std;

int length, noPatterns;
vector<int> pattern;
vector<int> memo;

const int MOD = 1000003;

int add(int a, int b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}

void print() {
    cout << "Test: ";
    for (const auto &y: memo) cout << y << " ";
    cout << "\n";
}

int main() {
    cin >> length >> noPatterns;

    pattern.resize(noPatterns);
    for (int i=0; i<noPatterns; i++) cin >> pattern[i];

    memo.resize(length+1);
    memo[0] = 1;

    for (int i=1; i<=length; i++) {
        int sum = 0;
        for (const auto &x: pattern) {
            if (i - x >= 0) sum = add(sum, memo[i-x]);
        }
        memo[i] = sum;
    }
    print();
    cout << memo.back();
}