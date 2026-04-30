// DONE
// Travelling Tourist

#include <bits/stdc++.h>
using namespace std;

int noStations, noTrains, noDests;
vector<vector<pair<int, int>>> to;
vector<int> dest;

vector<vector<int>> lowCostFromStart;
vector<bool> visited;

int minCost = INT_MAX/2;

void brute_force(int stationCount, int currStationID, int currCost) {
    if (stationCount == noDests) {
        minCost = min(minCost, currCost);
        return;
    }
    
    for (int i=0; i<noDests; i++) {
        if (!visited[i]) {
            visited[i] = true;

            int currStation = dest[currStationID];
            int nextStation = dest[i];
            int cost = lowCostFromStart[currStation][nextStation];
            if (cost < INT_MAX/2) 
                brute_force(stationCount+1, i, currCost + cost);
            visited[i] = false;
        }
    }
}

void solve() {
    // Run Dijkstra's noStations times

    for (int start=1; start<=noStations; start++) {
        vector<int> cost(noStations+1, INT_MAX/2), prev(noStations+1, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> toSearch;
        cost[start] = 0;
        toSearch.push({0, start});

        while (!toSearch.empty()) {
            auto [currCost, currStation] = toSearch.top();
            toSearch.pop();

            for (const auto &x: to[currStation]) {
                if (cost[x.first] > currCost + x.second) {
                    cost[x.first] = currCost + x.second;
                    prev[x.first] = currStation;
                    toSearch.push({cost[x.first], x.first});
                }
            }
        }
        lowCostFromStart[start] = cost;
    }

    // Brute Force
    for (int i=0; i<noDests; i++) {
        visited.assign(noDests, false);
        visited[i] = true;
        brute_force(1, i, 0);
        
    }
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> noStations >> noTrains >> noDests;

    dest.assign(noDests, -1);
    for (int i=0; i<noDests; i++) cin >> dest[i];
    sort(dest.begin(), dest.end());

    to.resize(noStations+1);
    for (int i=1; i<=noTrains; i++) {
        int a, b, w; cin >> a >> b >> w;
        to[a].push_back({b, w});
        to[b].push_back({a, w});
    }

    lowCostFromStart.resize(noStations+1);
    visited.assign(noStations+1, false);

    solve();

    cout << minCost;
}