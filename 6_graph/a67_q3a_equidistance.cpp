// DONE
// Equidistance

#include <bits/stdc++.h>
using namespace std;

int noRows, noCols;
vector<vector<bool>> isWall, visited, valid;
vector<pair<int, int>> startIndexes;
vector<vector<pair<int, int>>> todd;
vector<vector<int>> visitCount;

const vector<pair<int, int>> DIRS = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

int ans = 0;
bool isFirst = true;

void print() {
    for (const auto &x: valid) {
        for (const auto &y: x) cout << (y?"V":"-") << " ";
        cout << "\n";
    }
    //cout << remaining << "\n=======\n";
}

int main() {
    cin >> noRows >> noCols;
    
    isWall.assign(noRows, vector<bool>(noCols, false));
    valid.assign(noRows, vector<bool>(noCols, true));
    todd.assign(noRows, vector<pair<int, int>>(noCols, {0, 0}));
    visitCount.assign(noRows, vector<int>(noCols, 0));
    for (int i=0; i<noRows; i++) {
        for (int j=0; j<noCols; j++) {
            int tmp; cin >> tmp;
            if (tmp == 1) {
                isWall[i][j] = true;
                //remaining--;
                valid[i][j] = false;
            }
            if (tmp == 2) {
                startIndexes.push_back({i, j});
                //remaining--;
                valid[i][j] = false;
            }
        }
    }

    //BFS
    for (const auto &startCoor: startIndexes) {
        visited.assign(noRows, vector<bool>(noCols, false));
        visited[startCoor.first][startCoor.second] = true;

        queue<pair<pair<int, int>, int>> toSearch;
        toSearch.push({startCoor, 0});

        while (!toSearch.empty()) {
            auto [currPos, currDist] = toSearch.front();
            toSearch.pop();

            if (isFirst) todd[currPos.first][currPos.second] = {currDist, currDist};
            else {
                //Update min-max
                todd[currPos.first][currPos.second].first = min(todd[currPos.first][currPos.second].first, currDist);
                todd[currPos.first][currPos.second].second = max(todd[currPos.first][currPos.second].second, currDist);
                
                if (abs(todd[currPos.first][currPos.second].first - todd[currPos.first][currPos.second].second) > 1) {
                    if (valid[currPos.first][currPos.second]) {
                        valid[currPos.first][currPos.second] = false;
                        //remaining--;
                    }
                }
            }

            visitCount[currPos.first][currPos.second]++;

            for (const auto &x: DIRS) {
                int newRow = currPos.first + x.first;
                int newCol = currPos.second + x.second;

                if (newRow < 0 || newRow >= noRows) continue;
                if (newCol < 0 || newCol >= noCols) continue;
                if (visited[newRow][newCol]) continue;
                if (isWall[newRow][newCol]) continue;
                visited[newRow][newCol] = true;
                toSearch.push({{newRow, newCol}, currDist+1});
            }
        }

        isFirst = false;
        //print();
    }

    for (int i=0; i<noRows; i++) {
        for (int j=0; j<noCols; j++) {
            if (valid[i][j] && visitCount[i][j] == startIndexes.size()) ans++;
        }
    }
    cout << ans;
    //cout << remaining;
}