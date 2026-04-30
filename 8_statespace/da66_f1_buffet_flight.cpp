// DONE
// Buffet Flight

#include <bits/stdc++.h>
using namespace std;

int noAirports, noRoutes;
vector<int> ci, co;
vector<vector<int>> to;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> noAirports >> noRoutes;

    ci.resize(noAirports);
    co.resize(noAirports);
    
    for (int i=0; i<noAirports; i++) cin >> ci[i];
    for (int i=0; i<noAirports; i++) cin >> co[i];

    to.resize(noAirports);
    for (int _=0; _<noRoutes; _++) {
        int start, end; cin >> start >> end;
        to[start].push_back(end);
    }

    //Dijkstra
    vector<int> cost(noAirports, INT_MAX / 2), prevAirport(noAirports, -1);
    cost[0] = 0;

    priority_queue<pair<int, int>> toSearch;
    toSearch.push({0, 0});

    while (!toSearch.empty()) {
        auto [currCost, currAirport] = toSearch.top();
        toSearch.pop();
        for (const auto &nextAirport: to[currAirport]) {
            if (cost[nextAirport] > currCost + co[currAirport] + ci[nextAirport]) {
                cost[nextAirport] = currCost + co[currAirport] + ci[nextAirport];
                prevAirport[nextAirport] = currAirport;
                toSearch.push({currCost + co[currAirport] + ci[nextAirport], nextAirport});
            }
        }
    }

    for (const auto &a : cost) cout << (a == INT_MAX/2? -1:a) << " ";
    

}