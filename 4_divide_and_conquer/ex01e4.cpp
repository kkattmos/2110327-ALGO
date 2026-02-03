//DONE

#include <iostream>

using namespace std;

size_t modulo_exponent(size_t x, size_t n, size_t k) {
    // x^n mod k

    if (n == 1) return x % k;

    if (n % 2 == 0)
        return (modulo_exponent(x, n/2, k) * modulo_exponent(x, n/2, k)) % k; 
    else 
        return (modulo_exponent(x, n/2, k) * modulo_exponent(x, n/2, k) * (x % k)) % k; 
}


size_t x, n, k;
int main() {
    cin >> x >> n >> k;
    cout << modulo_exponent(x, n, k);
    
}