// DONE
// Team Work

#include <bits/stdc++.h>
using namespace std;

int noMembers, noSubtasks;
vector<int> timeComplete;
vector<int> currentTaskTime;
vector<int> subTimeLog;

void print() {
    cout << "Test\n";
    for (const auto &x: subTimeLog) cout << x << " ";
    cout << "\n";
    cout << "total: " << accumulate(subTimeLog.begin(), subTimeLog.end(), 0) << "\n";
}

int main() {
    cin >> noMembers >> noSubtasks;

    timeComplete.resize(noSubtasks);
    subTimeLog.resize(noSubtasks);
    currentTaskTime.resize(noMembers);
    for (int i=0; i<noSubtasks; i++) cin >> timeComplete[i];

    sort(timeComplete.begin(), timeComplete.end());

    int i=0;
    for (i; i<noSubtasks; i++) {
        if (i-noMembers < 0) subTimeLog[i] = timeComplete[i];
        else subTimeLog[i] = subTimeLog[i-noMembers] + timeComplete[i];
        //cout << "Test: " << subTimeLog[i] << "\n";
    }

    //for (int j=0; j<noMembers; j++) subTimeLog[i+j] = timeComplete[i+j];

    //print();

    long double result = 0;
    for (int i=0; i<noSubtasks; i++) result += (long double)subTimeLog[i]; 
    
    std::cout << std::fixed << std::setprecision(3);
    cout << (result / noSubtasks);
}