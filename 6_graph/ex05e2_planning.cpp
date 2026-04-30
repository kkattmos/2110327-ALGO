// DONE
// Task Planning (Redo)

#include <bits/stdc++.h>
using namespace std;

int noSteps;
vector<vector<bool>> preSteps;
vector<int> noStepsRequired;


int main() {
    cin >> noSteps;

    preSteps.resize(noSteps);
    noStepsRequired.assign(noSteps, 0);

    for (int i=0; i<noSteps; i++) {
        preSteps[i].assign(noSteps, false);
        
        int tmp; cin >> tmp;
        noStepsRequired[i] = tmp;

        for (int j=0; j<tmp; j++) {
            int p; cin >> p;
            preSteps[i][p] = true;
        }
    }

    queue<int> toSearch;
    for (int i=0; i<noSteps; i++) {
        if (!noStepsRequired[i]) toSearch.push(i);
    }

    while (!toSearch.empty())
    {
        int currStep = toSearch.front();
        toSearch.pop();

        cout << currStep << " ";

        for (int i=0; i<noSteps; i++) {
            if (preSteps[i][currStep]) {
                preSteps[i][currStep] = false;
                if (!--noStepsRequired[i]) toSearch.push(i);
            }
        }
    }
    

}