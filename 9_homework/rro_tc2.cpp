// 
// Rubik's Race Optimization (For Testcase 2+)

#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> board;
vector<vector<int>> goal;
vector<vector<bool>> locked;

int iterCount = 0;

bool IS_DEBUG = false;
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

// Returns the position of the empty cell
Pos findBlank() {
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            if (board[r][c] == -1) return {r, c};
    return {-1, -1};
}

// Find the "best candidate" of the color to move toward targetDest
// Scores are described in the function, notice the weighting of the score!
Pos findTile(int val, Pos targetDest) {
    Pos best = {-1, -1};
    double minScore = 1e18;
    Pos blank = findBlank();

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (board[r][c] != val || locked[r][c]) continue;

            // distToTarget : Manhattan distance from tile to goal cell
            int distToTarget = abs(r - targetDest.r) + abs(c - targetDest.c);
            
            // distToBlank : how far the blank is from the tile
            int distToBlank = abs(r - blank.r) + abs(c - blank.c);

            // frontierPenalty : Penaltizes tiles that are behind the current solve row/col
            double frontierPenalty = 0.0;
            if (r < targetDest.r) frontierPenalty = 150.0; 
            else if (r == targetDest.r && c < targetDest.c) frontierPenalty = 45.0;

            // warehouseBonus : Rewards tiles that are on the corner; easier to move
            double warehouseBonus = 0.0;
            if (r == N - 1 || c == N - 1 || r == 0 || c == 0) warehouseBonus = -2.0;

            // Total Score calculation, with applied weights
            double score = (distToTarget * 4.8) 
                         + (distToBlank * 1.1) 
                         + frontierPenalty 
                         + warehouseBonus;

            if (score < minScore) {
                minScore = score;
                best = {r, c};
            }
        }
    }
    // Another best weighing combination? 150 80 -2 4.9 1.1
    return best;
}

// Used by moveBlankTo(); Execute a move by swapping blank tile with adjacent tile
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

// Find abstract path from start to dest while avoiding locked cells (using A*)
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

// Main Solving strategy (for each cell)
void solveTile(int val, Pos dest) {
    
    // 1) Call findTile() to pick the best candidate tile
    Pos curr = findTile(val, dest);
    if (curr.r == -1 || curr == dest) { 
        if (curr != dest && curr.r == -1) cout << "Error: Tile " << val << " not found!" << endl;
        locked[dest.r][dest.c] = true; 
        return; 
    }

    // 2) Call findPathForTile() to get waypoints of the path to 1)
    vector<Pos> r = findPathForTile(curr, dest);

    // 3) For each waypoints in 2), call moveBlankTo() to position the blank tiles
    for (Pos nxt : r) {
        if (!moveBlankTo(nxt, curr)) {
            
            // In some cases, unlocking the solved cell is necessary to free up the space
            bool unlocked = false;
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
        
        // FinalStroke : one move that pushes the tile to next waypoint
        char finalStroke;
        if (curr.r > nxt.r)      finalStroke = 'U';
        else if (curr.r < nxt.r) finalStroke = 'D';
        else if (curr.c > nxt.c) finalStroke = 'L';
        else                     finalStroke = 'R';

        applyMove(finalStroke);
        curr = nxt; 
    }

    // 4) After the cell is solve, lock it so that we don't accidentially move the corrected cells
    locked[dest.r][dest.c] = true;
}

// Moves Optimization
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

// I/O, solving each tile
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);

    cin >> N;

    // Inputting initial state
    board.assign(N, vector<int>(N));
    locked.assign(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    
    // Inputting target state
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

    // Optimize moves, and output the results as .py file to submit to grader
    if (!IS_DEBUG) {
        string toExport = "import sys\n\nsys.stdout.write('" + optimizePath(moveHistory) + "S" + "')\n";
        ofstream outFile("tosubmit.py");

        if (outFile.is_open()) {
            outFile << toExport;
            outFile.close();
            cout << "Successfully written to file." << "\n";
            cout << "Moves: " << moveCount;
        } else {
            cerr << "Unable to open file" << "\n";
        }
        
    }
    else cout << moveCount << " " << iterCount;
    return 0;
}