//
// เมืองไกลสุด

#include <bits/stdc++.h>
using namespace std;

int noCities;
vector<vector<int>> roadDist;
vector<int> currDist, prevCity;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> noCities;
    
    roadDist.assign(noCities, vector<int>(noCities, -1));
    for (int i=0; i<noCities; i++) {
        for (int j=0; j<noCities; j++) cin >> roadDist[i][j];
    }

    //Bellman Ford
    currDist.assign(noCities, INT_MAX/2);
    prevCity.assign(noCities, -1);
    dist


    
}