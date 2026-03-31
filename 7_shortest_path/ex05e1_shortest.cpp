// DONE
// Shortest Path in Grid

#include <bits/stdc++.h>
using namespace std;

int noRows, noCols;
const vector<pair<int, int>> dir = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

int minDist = 1e7;
bool triggered = false;

int main() {
    cin >> noRows >> noCols;
    
    char maze[noRows][noCols];
    bool visited[noRows][noCols];
    for (int i=0; i<noRows; i++) {
        for (int j=0; j<noCols; j++) {
            cin >> maze[i][j];
            visited[i][j] = false;
        }
    }

    //<<row, col>, dist>
    queue<pair<pair<int, int>, int>> toCheck;
    toCheck.push(make_pair(make_pair(0, 0), 0));
    
    while (!toCheck.empty()) {
        pair<int, int> curr = toCheck.front().first;
        int dist = toCheck.front().second;
        toCheck.pop();

        if (visited[curr.first][curr.second]) continue;
        visited[curr.first][curr.second] = true;

        if (curr == make_pair(noRows-1, noCols-1)) {
            minDist = min(minDist, dist);
            triggered = true;
        }

        for (const auto &d: dir) {
            if (curr.first + d.first < 0 || curr.first + d.first >= noRows) continue;
            if (curr.second + d.second < 0 || curr.second + d.second >= noCols) continue;
            if (maze[curr.first + d.first][curr.second + d.second] == '#') continue;

            toCheck.push(make_pair(make_pair(curr.first + d.first, curr.second + d.second), dist+1));
        }
    }

    if (triggered) cout << minDist;
    else cout << "-1";
}