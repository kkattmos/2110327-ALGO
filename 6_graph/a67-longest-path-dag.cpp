//
// Longest path in DAG

#include <bits/stdc++.h>
using namespace std;

int noNodes, noEdges;
vector<vector<pair<int, int>>> destination; // <Destination, weight>
vector<bool> isBegin, visited;

int maxWeight = 0;

int main() {
    cin >> noNodes >> noEdges;

    isBegin.assign(noNodes+1, true);
    visited.assign(noNodes+1, false);
    destination.resize(noNodes+1);

    for (int _=0; _<noEdges; _++) {
        int start, end, weight; cin >> start >> end >> weight;
        destination[start].push_back(make_pair(end, weight));
        isBegin[end] = false;
    }

    for (int i=1; i<=noEdges; i++) {
        if (isBegin[i]) {
            
            stack<pair<int, int>> toSearch;
            toSearch.push(make_pair(i, 0));

            while (!toSearch.empty()) {
                int currNode = toSearch.top().first;
                int currWeight = toSearch.top().second;
                toSearch.pop();
                
                if (destination[currNode].empty()) {
                    maxWeight = max(maxWeight, currWeight);
                    continue;
                }
                for (const auto &x: destination[currNode]) toSearch.push(make_pair(x.first, currWeight + x.second));
            }
        }
    }

    cout << maxWeight;


}