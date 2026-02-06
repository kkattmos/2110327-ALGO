// DONE
// Triforce

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tableSize;
vector<vector<int>> table;

bool isZero(int start, int end) {
    for (int i=start; i<end; i++) {
        for (int j=start; j<end; j++) {
            if (table[i][j] != 0) return false;
        }
    }
    return true;
}

int triforce_type(int currTableSize, int top, int right) {
    
    if (currTableSize == 2) {
        if (table[top+1][right+1] != 0) return 0;

        vector<int> tmp = {table[top][right], table[top][right+1], table[top+1][right]};
        if (count(tmp.begin(), tmp.end(), 0) != 0) return 0;

        for (int v=1; v<=3; v++) {
            if (count(tmp.begin(), tmp.end(), v) >= 2) return v;
        }
        return 0;
        
    }

    int halfSize = currTableSize/2;

    if (!isZero(halfSize, currTableSize)) return 0; // Not a triforce on n > 2

    vector<int> quarterResult = {
        triforce_type(halfSize, top, right),
        triforce_type(halfSize, top, right+halfSize),
        triforce_type(halfSize, top+halfSize, right)
    };

    if (count(quarterResult.begin(), quarterResult.end(), 0) != 0) return 0;

    for (int v=1; v<=3; v++) {
        if (count(quarterResult.begin(), quarterResult.end(), v) >= 2) return v;
    }
    return 0;
}

int main() {
    for (int i=0; i<3; i++) {
        cin >> tableSize;
        vector<int> tmp(tableSize, 0);
        table.assign(tableSize, tmp);

        for (int x=0; x<tableSize; x++) {
            for (int y=0; y<tableSize; y++) cin >> table[x][y];
        }

        cout << triforce_type(tableSize, 0, 0) << "\n";
        
    }
    /* Test
    
    cout << "\n=========\n";
    for (int i=0; i<tableSize; i++) {
        for (int j=0; j<tableSize; j++) {
            cout << table[i][j] << " ";
        }
        cout << "\n";
    }
    */

    
}

