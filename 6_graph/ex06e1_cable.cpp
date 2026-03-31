//
// Cable Company

#include <bits/stdc++.h>
using namespace std;

int noCenters;
vector<vector<int>> relations;

int main() {
    cin >> noCenters;
    
    relations.resize(noCenters);
    for (int i=0; i<noCenters; i++) relations[i].resize(noCenters);

    for (int i=0; i<noCenters-1; i++) {
        for (int j=i+1; j<noCenters; j++) {
            int tmp; cin >> tmp;
            relations[i][j] = tmp;
            relations[j][i] = tmp;  
        }
    }

    vector<bool> visited(noCenters, false);
    vector<int> minCost(noCenters, 1e7);
    int totalWeight = 0;
    minCost[0] = 0;

    for (int i=0; i<noCenters; i++) {
        int currMin = -1;

        for (int j=0; j<noCenters; j++) {
            if (!visited[j])
        }

        visited[i] = true;
        totalWeight += minCost[i];

        for (int j=0; j<noCenters; j++) {
            if (!visited[i])
        }

    }

    for (int i=0; i<noCenters; i++) {
        for (int j=0; j<noCenters; j++) cout << relations[i][j] << " ";
        cout << "\n";
    }

    
}