// DONE (but needs review)
// Connection

#include <bits/stdc++.h>
using namespace std;

int noStudents, noRelations, targetDegree;
vector<vector<int>> relations;

int maxCount = 0;

int main() {
    cin >> noStudents >> noRelations >> targetDegree;

    relations.resize(noStudents);
    for (int i=0; i<noRelations; i++) {
        int start, end; cin >> start >> end;
        relations[start].push_back(end);
        relations[end].push_back(start);
    }

    for (int i=0; i<noStudents; i++) {
        vector<bool> visited(noStudents, false);
        visited[i] = true;
        int currCount = 0;

        // <student no, degree>
        queue<pair<int, int>> toSearch;
        toSearch.push(make_pair(i, 0));

        while (!toSearch.empty()) {
            int currStudent = toSearch.front().first;
            int currDegree = toSearch.front().second;
            toSearch.pop();

            if (currDegree <= targetDegree) currCount++;

            if (currDegree < targetDegree) {
                for (const auto &x: relations[currStudent]) {
                    if (!visited[x]) {
                        visited[x] = true;
                        toSearch.push(make_pair(x, currDegree+1));
                    }
                }
            }


        }

        maxCount = max(maxCount, currCount);
    }
    cout << maxCount;
}