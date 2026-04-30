#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> board;
vector<vector<int>> goal;
vector<vector<bool>> locked;

int iterCount = 0;

bool IS_DEBUG = true;
int moveCount = 0;
string moveHistory;

const int dr[] = {1, 0, 0, -1};
const int dc[] = {0, -1, 1, 0};
const char moves[] = {'U', 'R', 'L', 'D'};

struct Pos { 
    int r, c; 
    bool operator==(const Pos& o) const { return r == o.r && c == o.c; }
    bool operator!=(const Pos& o) const { return !(*this == o); }
    
    // Add this for priority_queue tie-breaking
    bool operator<(const Pos& o) const {
        if (r != o.r) return r < o.r;
        return c < o.c;
    }
};

Pos findBlank() {
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            if (board[r][c] == -1) return {r, c};
    return {-1, -1};
}

Pos findTile(int value, Pos targetDest) {
    Pos best = {-1, -1};
    double minScore = 1e18;
    Pos blank = findBlank();

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (board[r][c] == value && !locked[r][c]) {
                int distToTarget = abs(r - targetDest.r) + abs(c - targetDest.c);
                int distToBlank = abs(r - blank.r) + abs(c - blank.c);
                
                // Heuristic calculation:
                // 1. Distance to target is most important (weight: 1.0)
                // 2. Distance to blank helps save 'moveBlankTo' steps (weight: 0.1)
                // 3. Small penalty if it's already in the target zone (0.5)
                bool inTarget = (r >= 1 && r <= N-2 && c >= 1 && c <= N-2);
                double score = (distToTarget * 3.0) + (distToBlank * 0.3) + (inTarget ? 0. : 0.0);

                if (score < minScore) {
                    minScore = score;
                    best = {r, c};
                }
            }
        }
    }
    return best;
}

void applyMove(char m) {
    Pos b = findBlank();
    Pos nxt = b;
    
    if (m == 'U') nxt.r++;      
    else if (m == 'D') nxt.r--; 
    else if (m == 'L') nxt.c++; 
    else if (m == 'R') nxt.c--; 
    
    if (nxt.r >= 0 && nxt.r < N && nxt.c >= 0 && nxt.c < N) {
        swap(board[b.r][b.c], board[nxt.r][nxt.c]);
        if (!IS_DEBUG) moveHistory += m; 
        moveCount++;
    }
}

// Moves blank to a specific destination while avoiding a specific tile
bool moveBlankTo(Pos dest, Pos avoidTile) {
    Pos start = findBlank();
    if (start == dest) return true;

    // Use a priority queue for A*
    using Node = pair<int, pair<Pos, string>>;
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    
    // Use a 2D vector for distances (much faster than a map)
    vector<vector<int>> dists(N, vector<int>(N, 1e9));
    dists[start.r][start.c] = 0;
    
    pq.push({0, {start, ""}});

    while (!pq.empty()) {
        auto [f, data] = pq.top(); pq.pop();
        Pos curr = data.first;
        string path = data.second;

        if (curr == dest) {
            for (char m : path) applyMove(m);
            return true;
        }

        for (int i = 0; i < 4; i++) {
            Pos nxt = {curr.r + dr[i], curr.c + dc[i]};
            
            // Check boundaries, locked tiles, and the tile we are currently moving
            if (nxt.r >= 0 && nxt.r < N && nxt.c >= 0 && nxt.c < N && 
                !locked[nxt.r][nxt.c] && nxt != avoidTile) {
                
                int g = path.length() + 1;
                if (g < dists[nxt.r][nxt.c]) {
                    dists[nxt.r][nxt.c] = g;
                    // H is Manhattan distance to the blank's destination
                    int h = abs(nxt.r - dest.r) + abs(nxt.c - dest.c);
                    pq.push({g + h, {nxt, path + moves[i]}});
                }
            }
        }
    }
    return false; 
}

// Replace findPathForTile with this A* logic
vector<Pos> findPathForTile(Pos start, Pos dest) {
    if (start == dest) return {};
    
    using Node = pair<int, pair<Pos, vector<Pos>>>;
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    
    pq.push({0, {start, {}}});
    map<pair<int, int>, int> dists;
    dists[{start.r, start.c}] = 0;


    while (!pq.empty()) {
        auto [f, data] = pq.top(); pq.pop();
        Pos curr = data.first;
        vector<Pos> path = data.second;

        if (curr == dest) return path;
        
        iterCount++;
        for (int i = 0; i < 4; i++) {
            Pos nxt = {curr.r + dr[i], curr.c + dc[i]};
            if (nxt.r >= 0 && nxt.r < N && nxt.c >= 0 && nxt.c < N && !locked[nxt.r][nxt.c]) {
                int new_g = path.size() + 1;
                if (dists.find({nxt.r, nxt.c}) == dists.end() || new_g < dists[{nxt.r, nxt.c}]) {
                    dists[{nxt.r, nxt.c}] = new_g;
                    vector<Pos> nextPath = path;
                    nextPath.push_back(nxt);
                    int h = abs(nxt.r - dest.r) + abs(nxt.c - dest.c);
                    pq.push({new_g + h, {nxt, nextPath}});
                }
            }
        }
    }
    return {};
}

void solveTile(int val, Pos dest) {
    Pos curr = findTile(val, dest);
    // Safety check: if tile not found or already at dest
    if (curr.r == -1 || curr == dest) { 
        if (curr != dest && curr.r == -1) cerr << "Error: Tile " << val << " not found!" << endl;
        locked[dest.r][dest.c] = true; 
        return; 
    }

    vector<Pos> r = findPathForTile(curr, dest);

    for (Pos nxt : r) {
        if (!moveBlankTo(nxt, curr)) {
            // SAFER EMERGENCY UNLOCK
            bool unlocked = false;
            // Look for any locked tile to temporarily free up the path
            // We search backwards from the bottom right to find the most recent lock
            for (int r = N - 1; r >= 0 && !unlocked; r--) {
                for (int c = N - 1; c >= 0 && !unlocked; c--) {
                    if (locked[r][c] && Pos{r, c} != dest) {
                        locked[r][c] = false;
                        moveBlankTo(nxt, curr);
                        locked[r][c] = true;
                        unlocked = true;
                    }
                }
            }
        }
        
        // Inside solveTile, replacing the finalStroke logic:
        char finalStroke;
        if (curr.r > nxt.r)      finalStroke = 'U'; // Tile moves Up from current to nxt
        else if (curr.r < nxt.r) finalStroke = 'D'; // Tile moves Down from current to nxt
        else if (curr.c > nxt.c) finalStroke = 'L'; // Tile moves Left from current to nxt
        else                     finalStroke = 'R'; // Tile moves Right from current to nxt

        applyMove(finalStroke);
        curr = nxt; 
    }
    locked[dest.r][dest.c] = true;
}

// Add this helper function and call it before final output
string optimizePath(string s) {
    string res = "";
    for (char c : s) {
        if (!res.empty()) {
            if ((c == 'U' && res.back() == 'D') || (c == 'D' && res.back() == 'U') ||
                (c == 'L' && res.back() == 'R') || (c == 'R' && res.back() == 'L')) {
                res.pop_back();
                continue;
            }
        }
        res.push_back(c);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N)) return 0;

    board.assign(N, vector<int>(N));
    locked.assign(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    
    int M = N - 2; 
    goal.assign(M, vector<int>(M));
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            cin >> goal[i][j];

    // Solve row by row to minimize path blocking
    for (int r = 0; r < M; r++) {
        for (int c = 0; c < M; c++) {
            solveTile(goal[r][c], {r + 1, c + 1});
        }
    }

    if (!IS_DEBUG) cout << optimizePath(moveHistory) + "S" << endl; 
    else cout << moveCount << " " << iterCount;
    return 0;
}