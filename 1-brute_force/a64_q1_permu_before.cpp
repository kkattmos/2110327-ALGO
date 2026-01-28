#include <iostream>
#include <vector>

using namespace std;

int called;

bool check(vector<int> &letters,
            vector<pair<pair<int, int>, int>> &constraints,
            bool &alreadyInvalid,
            int &currIndex) {
    
    if (constraints.size() == 0) return true;    

    for (auto &c: constraints) {
        std::cout << "Testing index " << currIndex << " : " << letters[currIndex] << " with " << c.first.first << " " << c.first.second << " status " << c.second << "\n";

        if (c.second == 0) { // Not found
            if (c.first.second == letters[currIndex]) {
                cout << "Passed\n";
                alreadyInvalid = true;
                return false;
            }
            else if (c.first.first == letters[currIndex]) {
                c.second = 1;
            }
        }
        else if (c.second == 1) { // Found the start letter
            if (c.first.second == letters[currIndex]) {
                c.second = 2;
            }
        }
        else if (c.second == 2) { // Already completed
            continue;
        }
    }
    return true;
}

void recur(int target,
            int curr,
            vector<int> &letters,
            bool &alreadyInvalid,
            vector<bool> &used,
            vector<pair<pair<int, int>, int>> &constraints,
            int &called) {

    called++;
    
    if (curr < target) {
        for (int i=1; i<=target; i++) {

            if (curr == 0) cout << "=======\n";
            if (!used[i]) {
                used[i] = true;
                letters[curr] = i-1;
                
                
                if (!check(letters, constraints, alreadyInvalid, curr)) {
                    cout << "Terminated\n";
                    for (auto &c: constraints) c.second = 0;
                    used[i] = false;
                    return;
                }

                recur(target, curr+1, letters, alreadyInvalid, used, constraints, called);
                used[i] = false;
            }
        }
    }

    else {
        for (int i=0; i<target; i++) cout << letters[i] << " ";
        cout << "\n--------------\n";
        for (auto &c: constraints) c.second = 0;

    }
    
};

int n, m, a, b;
// n = number range
// m = no. constraints
// a = constraint_start
// b = constraint_end
int status = 0;
bool alreadyInvalid = false;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;

    vector<pair<pair<int, int>, int>> constraints(m);
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        constraints[i] = {{a, b}, 0};
    }

    vector<int> letters(n);
    vector<bool> used(n);
    recur(n, 0, letters, alreadyInvalid, used, constraints, called);
    cout << "Called: " << called;


}