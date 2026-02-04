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
                int curr,
                int usedCount) {
    
    if (curr > 3) return;
    if (usedCount == 3) {
        // TODO: calc the sum, put in results
        long long total = 0;
        for (int i=0; i<noElements; i++) {
            if (used[i]) total += elements[i];
        }

        if (results.empty()) results.push_back(total);
        else {
            auto index = lower_bound(results.begin(), results.end(), total);
            if (total != *(index) || index == results.end()) results.push_back(total);
        }

        return;
    }

    used[curr] = false;
    generate(elements, used, curr+1, usedCount);
    used[curr] = true;
    generate(elements, used, curr+1, usedCount+1);

}

//Idea: รับ elements แล้วบวกกันให้ครบทุก combination แล้วรับ queries ใ้ช้ lower bound หาว่่ามันอยู่ใน array มั้ย
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> noElements >> noQueries;

    vector<long long> elements(noElements); // The array used for combination
    for (int i=0; i<noElements; i++) cin >> elements[i];

    vector<bool> used(noElements);
    generate(elements, used, 0, 0);

    //Test
    for (const auto &x: results) cout << x << " ";
    cout << "\n===========\n";
    
    //Search value
    for (int i=0; i<noQueries; i++) {
        cin >> valueToSearch;
        auto index = lower_bound(results.begin(), results.end(), valueToSearch);
        
        if (*index == valueToSearch && index != results.end()) cout << "YES\n";
        else cout << "NO\n";
    }

}