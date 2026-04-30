// DONE
// Connection (Redo)

#include <bits/stdc++.h>
using namespace std;

int noStudents, noRelations, target;

vector<vector<bool>> related;
vector<bool> visited;

int maxCount = 0;

int main() {
    cin >> noStudents >> noRelations >> target;

    related.resize(noStudents);
    for (int i=0; i<noStudents; i++) related[i].assign(noStudents, false);
    
    for (int i=0; i<noRelations; i++) {
        int start, end; cin >> start >> end;
        related[start][end] = true;
        related[end][start] = true;
    }

    for (int start=0; start<noStudents; start++) {
        visited.assign(noStudents, false);
        visited[start] = true;
        int totalCount = 0;

        //BFS
        queue<pair<int, int>> toSearch;
        toSearch.push({start, 0});

        while (!toSearch.empty()) {
            int currStudent = toSearch.front().first;
            int currDist = toSearch.front().second;
            toSearch.pop();

            if (currDist <= target) totalCount++;

            for (int i=0; i<noStudents; i++) {
                if (related[currStudent][i] && !visited[i]) {
                    toSearch.push({i, currDist+1});
                    visited[i] = true;
                }
            }
        }

        maxCount = max(maxCount, totalCount);
    }

    cout << maxCount;
}