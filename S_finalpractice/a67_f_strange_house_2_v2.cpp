// 50.0 -> consider using std::deque?
// Strange House 2 - Constructive Algorithm

#include <bits/stdc++.h>
using namespace std;

int n;
vector<bool> gender, ans;

void op1() {
    bool tmp = gender[n];
    for (int i = n; i > 1; i--) gender[i] = gender[i-1];
    gender[1] = tmp;
    ans.push_back(true);
}

void op2() {
    bool tmp = gender[2*n - 1];
    for (int i = 2*n - 1; i > n; i--) gender[i] = gender[i-1];
    gender[n] = tmp;
    ans.push_back(false);
}

void solve() {
    int totalWoman = n - 1;
    int womanInHouse2 = 0;

    for (int i=n+1; i<=2*n-1; i++) {
        if (!gender[i]) womanInHouse2++;
    }

    while (womanInHouse2 < totalWoman) {
        if (gender[n]) op1();
        else {
            bool isMan = gender[2*n-1];
            op2();
            womanInHouse2++;
            if (!isMan) womanInHouse2--;
        }

        if (ans.size() > 400000) return;
    }

    while (!gender[n]) op2();
}

int main() {
    cin >> n;

    gender.resize(2*n);
    for (int i=1; i<=2*n-1; i++) {
        int tmp; cin >> tmp;
        gender[i] = (tmp == 1);
    }

    solve();
    cout << ans.size() << "\n";
    for (const auto &x: ans) cout << (x?1:2) << " ";
}