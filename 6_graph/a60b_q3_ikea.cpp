// DONE
// IKEA

#include <bits/stdc++.h>
using namespace std;

int noSteps, noRelations;
vector<vector<bool>> relations;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> noSteps >> noRelations;

    relations.resize(noSteps+1);
    for (int i=1; i<=noSteps; i++) relations[i].assign(noSteps+1, false);

    for (int i=0; i<noRelations; i++) {
        int start, end; cin >> start >> end;
        relations[end][start] = true;
    }

    for (int _=0; _<5; _++) {
        bool isPossible = true;
        vector<vector<bool>> copyRelations = relations;
        /*
    for (int i=1; i<=noSteps; i++) {
        for (int j=1; j<=noSteps; j++) cout << (copyRelations[i][j]? "T":"-") << " ";
        cout << "\n";
    }
        */

        queue<int> steps;
        for (int i=0; i<noSteps; i++) {
            int tmp; cin >> tmp;
            steps.push(tmp);
        }

        while (isPossible && !steps.empty()) {
            int currStep = steps.front();
            steps.pop();

            for (int i=1; i<=noSteps; i++) {
                if (copyRelations[currStep][i]) {
                    isPossible = false;
                    break;
                }
                copyRelations[i][currStep] = false;
            }
        }

        if (isPossible) cout << "SUCCESS\n";
        else cout << "FAIL\n";

        while (!steps.empty()) steps.pop();
    }
}