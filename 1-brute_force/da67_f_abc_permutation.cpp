// DONE (via included testcase); ส่งลงข้อ a67_q1a_abc_forbidden ได้ 40
// ABC Permutation

#include <iostream>
#include <vector>

using namespace std;

int length, noA, noB, noC, noForbidden;
vector<vector<int>> ans;

void loop(vector<int> &result,
            vector<int> &noLeft,
            int curr) {
    
    if (curr >= length) {
        ans.push_back(result);
        return;
    }

    for (int i=0; i<3; i++) { // Loop through a, b, c respectively
        if (noLeft[i]) {
            result[curr] = i;
            noLeft[i]--;
            loop(result, noLeft, curr+1);
            noLeft[i]++;
        }
    }
}


int main() {
    cin >> length >> noA >> noB >> noC;
    cin >> noForbidden;
    
    vector<int> result(length); // 0 = a, 1 = b, 2 = c
    vector<int> noLeft = {noA, noB, noC};

    loop(result, noLeft, 0);

    cout << ans.size() << "\n";
    for (const auto &result: ans) {
        for (int i=0; i<length; i++) {
            if (result[i] == 0) cout << "A";
            else if (result[i] == 1) cout << "B";
            else if (result[i] == 2) cout << "C";
            else cout << "-"; // Error Handling
        }
        cout << "\n"; 
    }

}