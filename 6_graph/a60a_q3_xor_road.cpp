//
// XOR Road

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int noRoads;
vector<ull> roadID;
vector<vector<ull>> beautyLevel;

ull total_beauty = 0;

int main() {
    cin >> noRoads;

    roadID.resize(noRoads);
    for (int i=0; i<noRoads; i++) cin >> roadID[i];

    beautyLevel.assign(noRoads, vector<ull>(noRoads, 0));
    for (int i=0; i<noRoads; i++) {
        for (int j=i+1; j<noRoads; j++) beautyLevel[i][j] = beautyLevel[j][i] = roadID[i] ^ roadID[j];
    }

    //Prim
    vector<ull> cost(noRoads, 0), prev(noRoads, -1);
    vector<bool> taken(noRoads, false);
    cost[0] = 0;

    priority_queue<pair<ull, int>> toSearch;
    toSearch.push({0, 0});

    while (!toSearch.empty()) {
        auto [maxVal, maxNode] = toSearch.top();
        toSearch.pop();

        if (taken[maxNode]) continue;
        taken[maxNode] = true;
        total_beauty += maxVal;

        for (int i=0; i<noRoads; i++) {
            if (taken[i]) continue;

            ull weight = roadID[maxNode] ^ roadID[i];
            if (cost[i] < weight) {
                cost[i] = weight;
                toSearch.push({cost[i], i});
            }
        }
    }

    //for (const auto &x: cost) cout << x << " ";
    cout << total_beauty;
}