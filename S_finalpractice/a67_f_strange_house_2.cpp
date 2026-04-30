// 40.00
// Strange House 2 - state space

#include <bits/stdc++.h>
using namespace std;

int n;
const int MAX_ITER = 400001;

int getScore(vector<bool> gender) {
    int correctCount = 0;
    for (int i=1; i<=n; i++) {
        if (gender[i] == true) correctCount++;
    }
    for (int i=n+1; i<=2*n-1; i++) {
        if (gender[i] == false) correctCount++;
    }

    return correctCount;
}

struct State {
    vector<bool> gender, op;
    // true = men       op1
    // false = women    op2

    bool operator<(const State &other) const {
        return getScore(gender) < getScore(other.gender);
    }
};

bool isGoal(vector<bool> &rooms) {
    for (int i=1; i<=n; i++) {
        if (rooms[i] != true) return false;
    } 
    for (int i=n+1; i<=2*n-1; i++) {
        if (rooms[i] != false) return false;
    }
    return true;
}

void op1(State &s) {
    bool tmp = s.gender[n];
    for (int i = n; i > 1; i--) s.gender[i] = s.gender[i-1];
    s.gender[1] = tmp;
}

void op2(State &s) {
    char tmp = s.gender[2*n - 1];
    for (int i = 2*n - 1; i > n; i--) s.gender[i] = s.gender[i-1];
    s.gender[n] = tmp;
}

vector<bool> getMoves(State &init) {
    priority_queue<State> toSearch;
    set<vector<bool>> visited;

    toSearch.push(init);
    visited.insert(init.gender);

    while (!toSearch.empty()) {
        State currState = toSearch.top();
        toSearch.pop();

        if (isGoal(currState.gender)) return currState.op;
        if (currState.op.size() > MAX_ITER) continue;

        for (int op=1; op<=2; op++) {
            State newState = currState;
            if (op == 1) op1(newState);
            else op2(newState);

            if (visited.find(newState.gender) == visited.end()) {
                visited.insert(newState.gender);
                newState.op.push_back((op == 1));
                toSearch.push(newState);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;

    State init;
    init.gender.resize(2*n);
    for (int i=1; i<=2*n-1; i++) {
        int tmp; cin >> tmp;
        init.gender[i] = (tmp == 1 ? true:false);
    }

    if (count(init.gender.begin()+1, init.gender.end(), true) != n) {
        cout << "-1";
        return 0;
    }

    if (count(init.gender.begin()+1, init.gender.end(), false) != n-1) {
        cout << "-1";
        return 0;
    }

    vector<bool> result = getMoves(init);
    cout << result.size() << "\n";
    for (const auto &x: result) cout << (x ? 1:2) << " ";
}