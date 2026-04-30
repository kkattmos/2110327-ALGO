//
// Near-Distance

#include <bits/stdc++.h>
using namespace std;

int noRows, noCols, allowed;

vector<vector<bool>> isWall;
vector<pair<int, int>> startIndexes;
vector<vector<int>> visitCount;
vector<vector<pair<int, int>>> todd;

const vector<pair<int, int>> DIRS = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

bool isFirst = true;
int ans = 0;

void print() {
    for (const auto &x: todd) {
        for (const auto &y: x) cout << "<" << y.first << ", " << y.second << "> ";
        cout << '\n';
    }
    cout << "=========\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> noRows >> noCols >> allowed;

    isWall.assign(noRows, vector<bool>(noCols, false));
    visitCount.assign(noRows, vector<int>(noCols, 0));
    todd.assign(noRows, vector<pair<int, int>>(noCols, {0, 0}));

    for (int i=0; i<noRows; i++) {
        for (int j=0; j<noCols; j++) {
            int tmp; cin >> tmp;
            if (tmp == 1) isWall[i][j] = true;
            if (tmp == 2) startIndexes.push_back({i, j});
        }
    }

    for (const auto &s: startIndexes) {
        vector<vector<bool>> visited(noRows, vector<bool>(noCols, false));
        visited[s.first][s.second] = true;

        queue<pair<pair<int, int>, int>> toSearch;
        toSearch.push({s, 0});

        while (!toSearch.empty()) {
            auto [currPos, currDist] = toSearch.front();
            toSearch.pop();

            visitCount[currPos.first][currPos.second]++;

            if (isFirst) todd[currPos.first][currPos.second] = {currDist, currDist};
            else todd[currPos.first][currPos.second] = {
                min(todd[currPos.first][currPos.second].first, currDist),
                max(todd[currPos.first][currPos.second].second, currDist)
            };

            for (const auto &d: DIRS) {
                int newRow = currPos.first + d.first;
                int newCol = currPos.second + d.second;

                if (newRow < 0 || newRow >= noRows) continue;
                if (newCol < 0 || newCol >= noCols) continue;
                if (visited[newRow][newCol]) continue;
                if (isWall[newRow][newCol]) continue;

                toSearch.push({{newRow, newCol}, currDist+1});
                visited[newRow][newCol] = true;
            }
        }
        isFirst = false;
    }

    //print();

    for (int i=0; i<noRows; i++) {
        for (int j=0; j<noCols; j++) {
            if (abs(todd[i][j].first - todd[i][j].second) <= allowed &&
                visitCount[i][j] == startIndexes.size()) ans++;
        }
    }

    cout << ans;
}