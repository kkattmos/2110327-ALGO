//
// Cutting Futomaki

// for loop ใหญ่ยังผิดนิดหน่อย
// ลองไปเช็คเคย 1 ใน Grader กับกรณี 10 1 1 100 ดู

#include <bits/stdc++.h>
using namespace std;

int length;
vector<int>tasteLevel;
vector<int> attempt;

int bestLevel = 0;

int main() {
    cin >> length;
    
    tasteLevel.resize(length+1);
    for (int i=1; i<=length; i++) cin >> tasteLevel[i];

    attempt.resize(length/2+1);
    attempt[0] = 0;

    int currStart = 1;
    int currEnd = length;

    for (int i=1; i<=(length/2); i++) {
        pair<int, int> m1 = {max(tasteLevel[currStart], tasteLevel[currStart+1]),1};
        pair<int, int> m2 = {max(tasteLevel[currEnd], tasteLevel[currEnd-1]), 2};
        pair<int, int> m3 = {max(tasteLevel[currStart], tasteLevel[currEnd]), 3};

        pair<int, int> bestMethod = max(m1, max(m2, m3));

        bestLevel += bestMethod.first;
        cout << "Test: " << bestMethod.first << " " << bestMethod.second << "\n";

        if (bestMethod.second == 1) currStart += 2;
        if (bestMethod.second == 2) currEnd -= 2;
        if (bestMethod.second == 3) {
            currStart += 1;
            currEnd -= 1;
        }

    }

    

    cout << bestLevel;
}