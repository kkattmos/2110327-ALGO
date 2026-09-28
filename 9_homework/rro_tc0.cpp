//
// Rubik's Race Optimization (for Testcase 2)

#include <bits/stdc++.h>
using namespace std;

typedef int8_t ssint; // [-128, 127]
typedef unsigned int uint;
typedef uint64_t llint;
// size_t [0, ]

const int MAX_ITER = 1e6; // Change this to get better results 
vector<bool> currResult;
int bestMove = 1e8;
bool found = false;

const vector<pair<char, pair<bool, bool>>> DIRS = {
    {'D', {false, false}},
    {'U', {false, true}},
    {'L', {true, false}},
    {'R', {true, true}}
};

ssint boardSize;
vector<ssint> target;

int getScore(const vector<ssint> &b) {
    int totalDist = 0;
    
    for (int i = 0; i < boardSize-2; i++) {
        for (int j = 0; j < boardSize-2; j++) {
            ssint targetVal = target[i*(boardSize-2) + j];
            
            // Find where targetVal currently is on the board
            for (int r = 0; r < boardSize; r++) {
                for (int c = 0; c < boardSize; c++) {
                    if (b[r*boardSize + c] == targetVal) {
                        // Manhattan distance from current pos to target pos in center
                        totalDist += abs(r - (i+1)) + abs(c - (j+1));
                    }
                }
            }
        }
    }
    // Negate so priority_queue (max-heap) favors smaller distance
    return -totalDist;
}

struct State {
    vector<ssint> board;
    vector<bool> moves;
    ssint currRow;
    ssint currCol;

    int getMoveCount() const {
        return moves.size()/2;
    }

    bool operator<(const State &other) const {
        return getScore(board) < getScore(other.board);
    }
};

bool isGoal(const State &s) {    
    //TODO: implement this
    //if (s.currCol > 0 && s.currCol < boardSize-1) return false;
    //if (s.currRow > 0 && s.currRow < boardSize-1) return false;

    for (ssint i=0; i<(boardSize-2); i++) {
        for (ssint j=0; j<(boardSize-2); j++) {
            if (s.board[((i+1)*boardSize) + j+1] != target[(i*(boardSize-2)) + j]) return false;
        }
    }
    return true;
}

bool opU(State &s) {
    if (s.currRow >= boardSize - 1) return false;
    swap(s.board[(s.currRow * boardSize) + s.currCol], s.board[((s.currRow+1) * boardSize) + (s.currCol)]);
    s.currRow++;
    return true;
}

bool opD(State &s) {
    if (s.currRow <= (ssint)0) return false;
    swap(s.board[(s.currRow * boardSize) + s.currCol], s.board[((s.currRow-1) * boardSize) + (s.currCol)]);
    s.currRow--;
    return true;
}

bool opL(State &s) {
    if (s.currCol >= boardSize - 1) return false;
    swap(s.board[(s.currRow * boardSize) + s.currCol], s.board[((s.currRow) * boardSize) + (s.currCol+1)]);
    s.currCol++;
    return true;
}

bool opR(State &s) {
    if (s.currCol <= (ssint)0) return false;
    swap(s.board[(s.currRow * boardSize) + s.currCol], s.board[((s.currRow) * boardSize) + (s.currCol-1)]);
    s.currCol--;
    return true;
}

void solve(State &init) {
    priority_queue<State> toSearch;
    set<vector<ssint>> visited;

    int iterCount = 1;
    toSearch.push(init);
    visited.insert(init.board);

    while (!toSearch.empty()) {
        State currState = toSearch.top();
        toSearch.pop();

        if (isGoal(currState)) {
            if (bestMove > currState.getMoveCount()) {
                currResult = currState.moves;
                bestMove = currState.getMoveCount();
            }
            continue;
        }

        iterCount++;
        if (iterCount % 100 == 0) cout << "Iter " << iterCount << "\n";
        if (iterCount > MAX_ITER) return;
        if (currState.getMoveCount() > bestMove) continue;
        
        for (const auto &d: DIRS) {
            State newState = currState;

            switch (d.first) {
                case 'D': 
                    if (!opD(newState)) continue; 
                    break;
                case 'U': 
                    if (!opU(newState)) continue; 
                    break;
                case 'L': 
                    if (!opL(newState)) continue; 
                    break;
                case 'R': 
                    if (!opR(newState)) continue; 
                    break;
            }

            if (visited.find(newState.board) != visited.end()) continue;
            visited.insert(newState.board);
            newState.moves.push_back(d.second.first);
            newState.moves.push_back(d.second.second);
            toSearch.push(newState);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    boardSize = (ssint)n;

    //Create initial state
    State init;
    init.board.resize(boardSize * boardSize);

    int tmp;
    for (int i=0; i<boardSize; i++) {
        for (int j=0; j<boardSize; j++) {
            cin >> tmp;
            if (tmp == -1) {
                init.currRow = i;
                init.currCol = j;
            }
            init.board[(i * boardSize) + j] = (ssint)tmp;
        }
    }

    //Defining target
    target.resize((boardSize-2) * (boardSize-2));
    for (int i=0; i<(boardSize-2); i++) {
        for (int j=0; j<(boardSize-2); j++) {
            cin >> tmp;
            target[i * (boardSize-2) + j] = (ssint)tmp;
        }
    }
    cout << "input passed\n";

    //cout << (int)init.currRow << " " << (int)init.currCol;
    //isGoal(init);
    //return 0;

    solve(init);

    cout << currResult.size();

    //TODO: Export output as python code for submission
    //for (int i=0; i<bestMove/2; i += 2) {
        
    //}


}