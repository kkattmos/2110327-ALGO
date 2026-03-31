// DONE
// Task Planning

#include <bits/stdc++.h>
using namespace std;

int noTasks;
vector<pair<int, vector<bool>>> prereq;
vector<int> ans;

int main() {
    cin >> noTasks;

    prereq.resize(noTasks);
    for (int i=0; i<noTasks; i++) {
        prereq[i].first = 0;
        prereq[i].second.assign(noTasks, false);

        int n; cin >> n;
        for (int t=0; t<n; t++) {
            int tmp; cin >> tmp;
            prereq[i].second[tmp] = true;
        }
        prereq[i].first = n;
    }

    queue<int> toSearch;
    for (int i=0; i<noTasks; i++) {
        if (prereq[i].first == 0) toSearch.push(i);
    }

    while (!toSearch.empty()) {
        int currStep = toSearch.front();
        prereq[currStep].first = -1; // The task is finished
        toSearch.pop();
        ans.push_back(currStep);

        for (int i=0; i<noTasks; i++) {
            if (prereq[i].second[currStep]) {
                prereq[i].second[currStep] = false;
                prereq[i].first--;
                if (prereq[i].first == 0) toSearch.push(i);
            }
        }
    }

    for (const auto &x: ans) cout << x << " ";
}