//
// Grid Loop

#include <bits/stdc++.h>
using namespace std;

int noRows, noCols;
int componentCount = 0;
int maxLength = 0;



int main() {
    cin >> noRows >> noCols;

    int matrix[noRows][noCols], visited[noRows][noCols];
    for (int i=0; i<noRows; i++) {
        for (int j=0; i<noCols; j++) {
            cin >> matrix[i][j];
            visited[i][j] =  -1;
        }
    }

    stack<pair<int, int>> toCheck;

    for (int i=0; i<noRows; i++) {
        for (int j=0; j<noCols; j++) {
            
            
            
            
        }
    }




}