// DONE
// Recur Matrix

#include <iostream>
#include <vector>

using namespace std;

int a, b;
int matrixSize;
vector<vector<int>> matrix;

void set_matrix(int size, int top, int right, int value) {
        
    if (size == 1) {
        matrix[top][right] = value;
        return;
    }

    int half = size / 2;
    set_matrix(half, top, right, value);
    set_matrix(half, top+half, right, value+1);
    set_matrix(half, top, right+half, value-1);
    set_matrix(half, top+half, right+half, value);
}

int main() {
    cin >> a >> b;
    matrixSize = 1 << a;

    vector<int> tmp(matrixSize, -999);
    matrix.assign(matrixSize, tmp);

    set_matrix(matrixSize, 0, 0, b);
    for (int i=0; i<matrixSize; i++) {
        for (int j=0; j<matrixSize; j++) cout << matrix[i][j] << " ";
        cout << "\n";
    }


}
