// DONE
// Day Cover

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int noDays, noStudents;
int minUsedStudent;

void calc(vector<vector<int>> &info, vector<bool> &used) {
    
    for (int i=0; i<noDays; i++) {
        bool alreadyCovered = false;
        for (int j=0; j<noStudents && !alreadyCovered; j++) {
            if (!used[j]) continue;
            if (info[j][i]) alreadyCovered = true;
        }
        if (!alreadyCovered) return; // Found a day with no helpers
    }

    minUsedStudent = count(used.begin(), used.end(), true);
    //cout << "TestCount: " << minUsedStudent << "\n";

}

void loop(vector<vector<int>> &info,
            vector<bool> &used,
            int current,
            int usedCount) {
    
    if (usedCount >= minUsedStudent) return;
    if (current == noStudents) {
        calc(info, used);
        return;
    }

    used[current] = false;
    loop(info, used, current+1, usedCount);
    used[current] = true;
    loop(info, used, current+1, usedCount+1);
    
}

int main() {
    cin >> noDays >> noStudents;
    minUsedStudent = noStudents;

    vector<vector<int>> info;
    for (int i=0; i<noStudents; i++) {
        vector<int> tmp(noDays);

        int noVacantDays, vacantDay;
        cin >> noVacantDays;
        for (int j=0; j<noVacantDays; j++) {
            cin >> vacantDay;
            tmp[vacantDay-1] = 1;
        }
        info.push_back(tmp);


    }

    /*
    cout << "===============\n";

    for (int i=0; i<info.size(); i++) {
        for (int j=0; j<noDays; j++) {
            cout << info[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "===============\n";
    */

    vector<bool> used(noStudents, false);
    loop(info, used, 0, 0);
    cout << minUsedStudent;

}


