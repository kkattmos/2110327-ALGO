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
                double score = (distToTarget * 1.0) + (distToBlank * 0.0);
                
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
        moveHistory += m;  // ALWAYS record, remove IS_DEBUG guard
        moveCount++;
    }
}

// NEW: State is (tilePos, blankPos)
struct TileSearchState {
    Pos tile, blank;
    bool operator==(const TileSearchState& o) const {
        return tile == o.tile && blank == o.blank;
    }
    // ADD THIS:
    bool operator<(const TileSearchState& o) const {
        if (tile != o.tile) return tile < o.tile;
        return blank < o.blank;
    }
};

struct TileSearchStateHash {
    size_t operator()(const TileSearchState& s) const {
        size_t h1 = s.tile.r * 200 + s.tile.c;
        size_t h2 = s.blank.r * 200 + s.blank.c;
        return h1 ^ (h2 * 2654435761ULL); // Knuth multiplicative hash
    }
};

// Returns sequence of moves to apply directly (replaces findPathForTile + moveBlankTo loop)
string findPathForTileWithBlank(Pos tileStart, Pos blankStart, Pos dest) {
    if (tileStart == dest) return "";

    using Node = pair<int, pair<TileSearchState, string>>;
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    unordered_map<TileSearchState, int, TileSearchStateHash> dists;

    TileSearchState initState = {tileStart, blankStart};
    dists[initState] = 0;
    pq.push({0, {initState, ""}});

    // Direction: moving the blank, which pushes the tile
    // If blank moves INTO tile position, tile moves opposite direction
    const int dr[] = {-1, 1, 0, 0};
    const int dc[] = {0, 0, -1, 1};
    const char mv[] = {'D', 'U', 'R', 'L'}; // what the blank move command is
    // tile moves opposite: blank goes up → tile pushed down, command is 'D'

    while (!pq.empty()) {
        auto [f, data] = pq.top(); pq.pop();
        auto [state, path] = data;

        if (state.tile == dest) return path;

        int g = path.size();
        if (dists.count(state) && dists[state] <= g) continue;

        // Option A: Move blank (not into tile)
        for (int i = 0; i < 4; i++) {
    Pos nb = {state.blank.r + dr[i], state.blank.c + dc[i]};
    if (nb.r < 0 || nb.r >= N || nb.c < 0 || nb.c >= N) continue;
    if (locked[nb.r][nb.c] && nb != dest) continue;  // CHANGED
    if (nb == state.tile) {
        Pos newTile = state.blank;
        if (newTile.r < 0 || newTile.r >= N || newTile.c < 0 || newTile.c >= N) continue;
        if (locked[newTile.r][newTile.c] && newTile != dest) continue;  // CHANGED

        TileSearchState ns = {newTile, state.tile};
        int ng = g + 1;
        int h = abs(newTile.r - dest.r) + abs(newTile.c - dest.c);
        if (!dists.count(ns) || ng < dists[ns]) {
            dists[ns] = ng;
            pq.push({ng + h, {ns, path + mv[i]}});
        }
    } else {
        TileSearchState ns = {state.tile, nb};
        int ng = g + 1;
        int h = abs(state.tile.r - dest.r) + abs(state.tile.c - dest.c);
        if (!dists.count(ns) || ng < dists[ns]) {
            dists[ns] = ng;
            pq.push({ng + h, {ns, path + mv[i]}});
        }
    }

        }
    }
    return ""; // unreachable
}

void solveTile(int val, Pos dest) {
    if (board[dest.r][dest.c] == val) {
        locked[dest.r][dest.c] = true;
        return;
    }

    Pos curr = findTile(val, dest);
    if (curr.r == -1) {
        cerr << "Error: Tile " << val << " not found!\n";
        locked[dest.r][dest.c] = true;  // ADD: lock anyway to prevent future access
        return;
    }
    
    Pos blank = findBlank();
    string path = findPathForTileWithBlank(curr, blank, dest);

    // ADD: if no path found, the tile is trapped — skip
    if (path.empty() && curr != dest) {
        cerr << "Warning: No path for tile " << val << " to dest (" 
             << dest.r << "," << dest.c << ")\n";
        locked[dest.r][dest.c] = true;
        return;
    }

    for (char m : path) applyMove(m);

    // ADD: verify the tile actually arrived
    if (board[dest.r][dest.c] != val) {
        cerr << "Warning: Tile " << val << " did not reach dest ("
             << dest.r << "," << dest.c << "), got " 
             << board[dest.r][dest.c] << "\n";
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

    for (int r = 0; r < M; r++)
        for (int c = 0; c < M; c++) solveTile(goal[r][c], {r+1, c+1});

    if (!IS_DEBUG) cout << optimizePath(moveHistory) + "S" << endl; 
    else cout << moveCount;
    return 0;
}