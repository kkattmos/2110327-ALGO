//
// Pressure Station

#include <bits/stdc++.h>
using namespace std;

int length, dist;

int main() {
    cin >> length >> dist;

    int cost[length];
    for (int i=0; i<length; i++) {
        cin >> cost[i];
        
        if (i > dist) {
            int minCost = 1e7;
            for (int j=1; j<=dist; j++) minCost = min(minCost, cost[i-j] + cost[i]);
            cost[i] = minCost;
        }

    }
    cout << cost[length-1];
}