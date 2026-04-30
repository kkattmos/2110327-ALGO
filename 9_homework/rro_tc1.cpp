// 28 Moves
// Rubik's Race Optimization (For Testcase 1)

#include <bits/stdc++.h>
using namespace std;

typedef vector<int8_t> Board;
typedef tuple<int, int, int, int, Board, string> State;
// <f_score, negative_g_score, spaceRow, spaceCol, boardState, path>

const vector<pair<char, pair<int, int>>> DIRS = {
    {'U', {1, 0}},
    {'D', {-1, 0}},
    {'L', {0, 1}},
    {'R', {0, -1}}
};

//For debugging
const bool IS_DEBUG = true; 

int boardSize;
Board target;
int moveCount = -1;

struct VectorHasher {
    size_t operator()(const Board& V) const {
        size_t hash = V.size();
        for (auto& i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

priority_queue<State, vector<State>, greater<State>> toSearch;
unordered_map<Board, int, VectorHasher> visited;
map<int8_t, vector<pair<int, int>>> targetPositions;

int getBoardID(int row, int col, bool isTarget=false) {
    if (isTarget) return (row * (boardSize-2)) + col;
    return (row * boardSize) + col;
}

int getHeuristic(const Board& board) {
    int total_manhattan = 0;
    
    for (int i = 0; i < boardSize - 2; i++) {
        for (int j = 0; j < boardSize - 2; j++) {
            int boardID = getBoardID(i + 1, j + 1, false);
            int8_t value = board[boardID];
            
            if (targetPositions.count(value)) {
                int min_dist = 1e9;
                // Check every possible target slot for this color
                for (auto& pos : targetPositions[value]) {
                    int dist = abs((i + 1) - (pos.first + 1)) + abs((j + 1) - (pos.second + 1));
                    min_dist = min(min_dist, dist);
                }
                total_manhattan += min_dist;
            }
        }
    }
    return total_manhattan;
}

bool isGoal(const Board& board) {
    for (int i=0; i<boardSize-2; i++) {
        for (int j=0; j<boardSize-2; j++) {
            int boardID = getBoardID(i+1, j+1, false);
            int targetID = getBoardID(i, j, true);
            
            if (board[boardID] != target[targetID]) return false;
        }
    }
    return true;
}

void solve() {
    int iterations = 0;
    while (!toSearch.empty()) {
        auto [fScore, gScore, currRow, currCol, currBoard, path] = toSearch.top();
        toSearch.pop();

        iterations++;
        if (iterations % 1000 == 0 && IS_DEBUG) {  // Print every 1000 iterations
            cerr << "Iteration " << iterations << " | gScore=" << gScore 
                 << " | fScore=" << fScore << " | path=" << path << "\n";
        }

        if (moveCount < gScore && IS_DEBUG) {
            cout << "New move count = " << gScore << "\n";
            moveCount = gScore;
        }

        if (isGoal(currBoard)) {
            cout << path << "S";
            return;
        }

        for (const auto &x: DIRS) {
            int newRow = currRow + x.second.first;
            int newCol = currCol + x.second.second;

            if (newRow < 0 || newRow >= boardSize) continue;
            if (newCol < 0 || newCol >= boardSize) continue;

            Board nextBoard = currBoard;
            int currID = getBoardID(currRow, currCol);
            int nextID = getBoardID(newRow, newCol);

            swap(nextBoard[currID], nextBoard[nextID]);

            int new_gScore = gScore + 1;
            if (visited.find(nextBoard) == visited.end() || new_gScore < visited[nextBoard]) {
                visited[nextBoard] = new_gScore;
                int new_hScore = getHeuristic(nextBoard);
                int new_fScore = new_gScore + new_hScore;
                
                toSearch.push({
                    new_fScore,
                    new_gScore,
                    newRow,
                    newCol,
                    nextBoard,
                    path + x.first
                });
            }
        }
    }
    cout << "No solution";
}

void setup() {
    cin >> boardSize;

    int8_t startRow, startCol;

    Board initBoard(pow(boardSize, 2));
    for (int i=0; i<boardSize; i++) {
        for (int j=0; j<boardSize; j++) {
            int tmp; cin >> tmp;
            if (tmp == -1) {
                startRow = i;
                startCol = j;
            }
            initBoard[getBoardID(i, j)] = (int8_t)tmp;
        }
    }

    target.resize((boardSize-2) * (boardSize-2));
    for (int i=0; i<boardSize-2; i++) {
        for (int j=0; j<boardSize-2; j++) {
            int tmp; cin >> tmp;
            target[getBoardID(i, j, true)] = (int8_t)tmp;
            targetPositions[(int8_t)tmp].push_back({i, j});        
        }
    }

    toSearch.push({getHeuristic(initBoard), 0, startRow, startCol, initBoard, ""});
    visited[initBoard] = 0;
}

void printboard() {
    for (const auto &x: target) {
        cout << x;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    setup();
    solve();
    //printboard();
}

