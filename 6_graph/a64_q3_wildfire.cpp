//
// Wildfire

#include <bits/stdc++.h>
using namespace std;

int noLands, noWinds, noDays;
vector<int> beauty;         // 0 = land is burnt
vector<int> landOnFire;
vector<vector<int>> relation;

void print() {
    cout << "TEst: ";
    for (const auto &x: beauty) cout << x << " ";
    cout << "\n";
}

int getBeautyScore() {
    int sum = 0;
    for (const auto &x: beauty) sum += x;
    return sum;
}

void burn(int node) {
    beauty[node] = 0;
    //print();
    for (const auto &x: relation[node]) {
        if (beauty[x]) burn(x);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> noLands >> noWinds >> noDays;

    beauty.resize(noLands);
    landOnFire.resize(noDays);
    relation.resize(noLands);


    for (int i=0; i<noLands; i++) cin >> beauty[i];
    for (int i=0; i<noDays; i++) cin >> landOnFire[i];

    for (int i=0; i<noWinds; i++) {
        int from, to;
        cin >> from >> to;
        relation[from].push_back(to);
        //relation[to].push_back(from);
    }

    for (const auto &x: landOnFire) {
        burn(x);
        cout << getBeautyScore() << " "; 
    }
}