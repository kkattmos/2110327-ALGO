// [[PP][PP][PP][PP][PP][PP][PP][PT][PP][TP][TT][TT][TT][TT][TT][TT][TT][TT][TT][TT]]
// Strange House 2 - state space

#include <bits/stdc++.h>
using namespace std;

int n;
const int MAX_ITER = 400000;

int getScore(const vector<char> &rooms) {
    // Check whether people are in correct pos
    int correct = 0;
    for (int i=1; i<=n; i++) {
        if (rooms[i] == '1') correct++;
    } 
    for (int i=n+1; i<=2*n-1; i++) {
        if (rooms[i] == '2') correct++;
    }
    return correct;

}

bool isGoalState(vector<char> &rooms) {
    for (int i=1; i<=n; i++) {
        if (rooms[i] != '1') return false;
    } 
    for (int i=n+1; i<=2*n-1; i++) {
        if (rooms[i] != '2') return false;
    }
    return true;
}

struct State {
    vector<char> rooms, operation;
    // true = Operation 1;
    // false = Operation 2;

    bool operator<(const State &other) const {
        return getScore(rooms) < getScore(other.rooms);
    }
};

void op1(vector<char> &rooms) {
    char tmp = rooms[n];
    for (int i = n; i > 1; i--) rooms[i] = rooms[i-1];
    rooms[1] = tmp;
}

void op2(vector<char> &rooms) {
    char tmp = rooms[2*n - 1];
    for (int i = 2*n - 1; i > n; i--) rooms[i] = rooms[i-1];
    rooms[n] = tmp;
}

vector<char> getOperation(const State &initialState) {
    priority_queue<State> toSearch;
    set<vector<char>> visitedStates;

    toSearch.push(initialState);
    visitedStates.insert(initialState.rooms);

    while (!toSearch.empty()) {
        State currState = toSearch.top();
        toSearch.pop();

        if (isGoalState(currState.rooms)) return currState.operation;
        if (currState.operation.size() >= MAX_ITER) continue;
        for (int i=1; i<=2; i++) {
            State newstate = currState;
            //newstate.rooms = (i == 1 ? op1(newstate.rooms):op2(newstate.rooms));
            if (i == 1) op1(newstate.rooms);
            else op2(newstate.rooms);

            newstate.operation.push_back((i == 1?'1':'2')); 
            if (visitedStates.find(newstate.rooms) != visitedStates.end()) continue;
            visitedStates.insert(newstate.rooms);
            toSearch.push(newstate);
        }
    }
    return {};
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;

    State init;
    init.rooms.resize(2*n);
    for (int i=1; i<=2*n-1; i++) cin >> init.rooms[i];

    vector<char> result = getOperation(init);

    if (result.size() == 0) cout << "-1";
    else{
        cout << result.size() << "\n";
        for (const auto &x: result) cout << x << " ";
    }
}