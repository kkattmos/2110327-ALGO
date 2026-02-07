// DONE
// Matrix Modulo

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> matrix(4);

vector<int> multiply(vector<int> A, vector<int> B) {
    vector<int> res(4);

    res[0] = A[0]*B[0] + A[1]*B[2];
    res[1] = A[0]*B[1] + A[1]*B[3];
    res[2] = A[2]*B[0] + A[3]*B[2];
    res[3] = A[2]*B[1] + A[3]*B[3];

    return res;
}

vector<int> modulo(vector<int> input, int k) {
    for (int i=0; i<4; i++) {
        input[i] %= k;
    }
    return input;
}

vector<int> mod_expo(vector<int> input, int n, int k) {
    if (n == 1) {
        vector<int> res(4);
        for (int i=0; i<4; i++) res[i] = input[i] % k;
        return res;
    }

    auto half = mod_expo(input, n/2, k);
    auto tmp = multiply(half, half);

    if (n % 2 == 0) return modulo(tmp, k);
    else return modulo(multiply(tmp, modulo(input, k)), k);
}

int main() {
    cin >> n >> k;
    for (int i=0; i<4; i++) cin >> matrix[i];
    
    vector<int> res = mod_expo(matrix, n, k);
    for (int i=0; i<4; i++) cout << res[i] << " ";

}