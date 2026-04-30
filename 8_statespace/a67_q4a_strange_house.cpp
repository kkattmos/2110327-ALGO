//
// Strange House

#include <bits/stdc++.h>
using namespace std;

int n, noPaths;
vector<vector<int>> adj;

int currIter = 0;
const int MAX_ITER = 1e9;

int getCorrectPositions(const vector<char> &rooms) {
    int correct = 0;
    for (int i=1; i<=n; i++) {
        if (rooms[i] == 'B') correct++;
    }
    for (int i=n+1; i<=2*n; i++) {
        if (rooms[i] == 'R') correct++;
    }
    return correct;

};

bool isTargetState(const vector<char> &rooms) {
    return getCorrectPositions(rooms) == 2*n;
}

struct State {
    vector<char> rooms;
    vector<int> moves;
    int emptyRoom;
    
    bool operator<(const State& other) const {
        return getCorrectPositions(rooms) < getCorrectPositions(other.rooms);
    }
};

vector<int> solve() {
    State start;
    start.rooms.assign(2 * n + 2, '-');
    for (int i=1; i<=n; i++) start.rooms[i] = 'R';
    for (int i=n+1; i<=2*n; i++) start.rooms[i] = 'B';
    start.emptyRoom =2*n+1;

    priority_queue<State> toSearch;
    toSearch.push(start);

    set<vector<char>> visited; // Track visited states
    visited.insert(start.rooms);

    while (!toSearch.empty() && currIter < MAX_ITER) {
        State currState = toSearch.top();
        toSearch.pop();

        currIter++;
        if (isTargetState(currState.rooms)) return currState.moves;

        for (const auto &n: adj[currState.emptyRoom]) {
            
            State next = currState;
            swap(next.rooms[currState.emptyRoom], next.rooms[n]);
            next.emptyRoom = n;
            next.moves.push_back(n);

            if (visited.find(next.rooms) != visited.end()) continue;
            visited.insert(currState.rooms);
            toSearch.push(next);
        }
    }
    return {};
    
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> noPaths;

    adj.resize(2 * n + 2);
    for (int i=0; i<noPaths; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> result = solve();
    if (result.size() == 0) cout << "-1";
    else {
        cout << result.size() << "\n";
        for (const auto &x: result) cout << x << " ";
    }
}