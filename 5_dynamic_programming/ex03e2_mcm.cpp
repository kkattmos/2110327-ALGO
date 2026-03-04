//
// Matrix Chain Multiplication



#include <bits/stdc++.h>
using namespace std;

int noMatrix;
vector<int> sequence;
vector<vector<int>> table;

void print() {
    cout << "TEST\n";
    for (const auto &x: table) {
        for (const auto &y: x) cout << y << " ";
        cout << "\n";
    }
}

int main() {
    cin >> noMatrix;   

    sequence.assign(noMatrix+2, 0);
    for (int i=1; i<=noMatrix+1; i++) cin >> sequence[i];

    table.resize(noMatrix);
    for (int i=0; i<noMatrix; i++) {
        table[i].resize(noMatrix);
        table[i][i] = 0;
    }

    for ()

    

    /*
    0 1
    1 2
    2 3
    3 4
    
    0 2
    1 3
    2 4
    
    0 3
    1 4
    
    0 4
    */



    print();
}