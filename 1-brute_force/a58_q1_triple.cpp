//
// Triple Sum

// Combination - choose 3 items

#include <iostream>
#include <vector>

using namespace std;

long long noElements, noQueries;
long long valueToSearch;
vector<long long> results;
vector<long long> toAdd(3);

void generate(vector<long long> &elements, 
                vector<bool> &used,
                int curr) {
    
    if (curr == 3) {
        // TODO: calc the sum, put in results
        long long total = 0;
        for (const auto &x: toAdd) total += x;

        if (results.empty()) results.push_back(total);
        else {
            auto index = lower_bound(results.begin(), results.end(), total);
            if (total != *(index) || index == results.end()) results.push_back(total);
        }

        return;
    }

    for (int i=0; i<noElements; i++) {
        if (!used[i]) {
            used[i] = true;
            toAdd[curr] = elements[i];
            generate(elements, used, curr+1);
            used[i] = false;
        }
    }

}

//Idea: รับ elements แล้วบวกกันให้ครบทุก combination แล้วรับ queries ใ้ช้ lower bound หาว่่ามันอยู่ใน array มั้ย
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> noElements >> noQueries;

    vector<long long> elements(noElements); // The array used for combination
    for (int i=0; i<noElements; i++) cin >> elements[i];

    vector<bool> used(noElements);
    generate(elements, used, 0);
    
    //Search value
    for (int i=0; i<noQueries; i++) {
        cin >> valueToSearch;
        auto index = lower_bound(results.begin(), results.end(), valueToSearch);
        
        if (*index == valueToSearch && index != results.end()) cout << "YES\n";
        else cout << "NO\n";
    }

}