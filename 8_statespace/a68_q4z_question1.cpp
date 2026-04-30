// DONE
// The Goat Duel

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
int noGoats;
vector<pair<ull, int>> toSort;

ull currDamage = 0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> noGoats;

    toSort.resize(noGoats);
    for (int i=0; i<noGoats; i++) {
        cin >> toSort[i].first;
        toSort[i].second = i;
    }
    sort(toSort.begin(), toSort.end());

    for (int i=1; i<noGoats; i++) currDamage += toSort[i-1].first * toSort[i].first;

    cout << currDamage;
}