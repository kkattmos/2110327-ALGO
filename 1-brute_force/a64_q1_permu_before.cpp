// PPPPPTTTTT
// Permutation with Constraint

#include <iostream>
#include <vector>

using namespace std;

// การเก็บ forbidden data แบบข้างล่างนี้ อาจ work กับข้อนี้ -- ทดไว้ก่อน workมั้ยยังไม่เคยลอง
//     vector<pair<bool, pair<int, int>>> forbiddenList;

int length, noConstraints;
int t1, t2; // Temporary value for storing start and end constraints

vector<pair<int ,int>> constraintList;
vector<int> constraintStatus;

bool check(vector<int> &result, int curr) {
    
    for (int i=0; i<noConstraints; i++) {
        if (constraintStatus[i] == -1) { //Currently not found
            if (constraintList[i].second == result[curr]) constraintStatus[i] = curr;
        }
        else {
            if (constraintList[i].first == result[curr]) return false;
        }
    }
    return true;
}

void reset(int curr) {
    for (int i=0; i<noConstraints; i++) {
        if (constraintStatus[i] == curr) constraintStatus[i] = -1;
    }
}

void loop(vector<int> &result,
            vector<bool> &used,
            int curr) {
    
    if (curr == length) {
        for (int i=0; i<length; i++) cout << result[i] << " ";
        cout << "\n";
    }

    for (int i=1; i<=length; i++) {
        if (!used[i]) {
            used[i] = true;
            result[curr] = i-1;
            if (check(result, curr)) loop(result, used, curr+1);
            reset(curr);
            used[i] = false;
        }

    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> length >> noConstraints;

    for (int i=0; i<noConstraints; i++) {
        cin >> t1 >> t2;
        constraintList.push_back({t1, t2});
        constraintStatus.push_back(-1);
    }

    vector<bool> used(length+1, false);
    vector<int> result(length);
    loop(result, used, 0);
}