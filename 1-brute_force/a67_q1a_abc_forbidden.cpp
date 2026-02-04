// DONE
// ABC Permutation with Forbidden Pattern

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int length, noA, noB, noC, noForbidden;
string tmp; // For inputting forbidden pattern string
vector<vector<int>> ans;
vector<pair<int, int>> forbiddenList;

bool is_forbidden(vector<int> &result,
                    int curr) {
    
    if (curr < 2) return false;

    for (auto &x: forbiddenList) {
        if (x.first == result[curr-2] && x.second == result[curr-1]) return true;
    }
    return false;
}

void loop(vector<int> &result,
            vector<int> &noLeft,
            int curr) {

    if (is_forbidden(result, curr)) return;
    
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

int letterToInt(char x) {
    if (x == 'A') return 0;
    else if (x == 'B') return 1;
    else if (x == 'C') return 2;
    return -999;
}

int main() {
    cin >> length >> noA >> noB >> noC;
    cin >> noForbidden;
    
    vector<int> result(length); // 0 = a, 1 = b, 2 = c
    vector<int> noLeft = {noA, noB, noC};

    for (int i=0; i<noForbidden; i++) {
        cin >> tmp;
        forbiddenList.push_back({letterToInt(tmp[0]), letterToInt(tmp[1])});
    }

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