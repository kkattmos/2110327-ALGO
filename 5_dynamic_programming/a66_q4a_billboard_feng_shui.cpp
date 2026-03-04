//
// Billboard Feng Shui

#include <bits/stdc++.h>
using namespace std;

int roadLength, noPatterns;
vector<int> views;
vector<int> patterns;

int main() {
    cin >> roadLength >> noPatterns;
    
    views.resize(roadLength);
    for (int i=0; i<roadLength; i++) cin >> views[i];

    patterns.resize(noPatterns);
    for (int i=0; i<noPatterns; i++) cin >> patterns[i];
}