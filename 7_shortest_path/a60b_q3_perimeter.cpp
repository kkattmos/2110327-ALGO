// DONE
// Perimeter

#include <bits/stdc++.h>
using namespace std;

int noLocations, noRoads, targetDist;
int possibleLocations = 0;

int main() {
    cin >> noLocations >> noRoads >> targetDist;

    bool relations[noLocations+1][noLocations+1] = {false};
    bool visited[noLocations+1] = {false};

    for (int i=0; i<noRoads; i++) {
        int start, end; cin >> start >> end;
        relations[start][end] = true;
        relations[end][start] = true;
    }

    // <index, currDist>
    queue<pair<int, int>> toSearch;
    toSearch.push(make_pair(0, 0));

    while (!toSearch.empty()) {
        int currIndex = toSearch.front().first;
        int currDist = toSearch.front().second;
        toSearch.pop();

        if (visited[currIndex]) continue;
        visited[currIndex] = true;

        if (currDist == targetDist) {
            possibleLocations++;
            continue;
        }
        else if (currDist > targetDist) continue;

        for (int i=1; i<=noLocations; i++) {
            if (relations[i][currIndex]) toSearch.push(make_pair(i, currDist+1));
        }
    }

    cout << possibleLocations;
}