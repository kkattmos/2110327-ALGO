//
// Closest Pair

#include <bits/stdc++.h>
using namespace std;

int noItems;
vector<pair<int, int>> points;

int main() {
    cin >> noItems;

    points.assign(noItems, {0, 0});
    for (int i=0; i<noItems; i++) cin >> points[i].first >> points[i].second;

    sort(points.begin(), points.end());

}