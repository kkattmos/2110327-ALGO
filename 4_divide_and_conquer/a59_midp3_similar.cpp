// DONE
// Similar String

#include <bits/stdc++.h>
using namespace std;

string s1, s2;

bool isSimilar(string a, string b) {
    //cout << "Comparing: " << a << " " << b << "\n";
    
    if (a == b) return true;
    if (a.size() == 1) return a == b;

    int mid = a.size() / 2;
    string a1(a.begin(), a.begin()+mid);
    string a2(a.begin()+mid, a.end());
    string b1(b.begin(), b.begin()+mid);
    string b2(b.begin()+mid, b.end());
    
    return (isSimilar(a1, b1) && isSimilar(a2, b2)) || (isSimilar(a1, b2) && isSimilar(a2, b1));
}

int main() {
    cin >> s1 >> s2;
    //cout << "Test:\n" << s1.size() << "\n" << *(s2.begin()+1) << "\n";

    if (isSimilar(s1, s2)) cout << "YES";
    else cout << "NO";
}