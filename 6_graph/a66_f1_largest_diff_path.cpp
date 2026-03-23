// [PP-PPPPPPPPTTTTTTTTT]
// Largest Diff Path

#include <bits/stdc++.h>
using namespace std;

int noNodes, noEdges;
vector<int> values;
vector<vector<int>> destination;
int maxDifference = 0;

                    //  c[a]           
void dfs(int node, int currentMin) {
    //cout << "Transversing: " << node << " currentMin: " << currentMin << "\n";

    for (const auto &x: destination[node]) {
        maxDifference = max(maxDifference, values[x] - currentMin);
        if (maxDifference > values[x] - currentMin) dfs(x, min(currentMin, values[x]));
    }

}

int main() {
    cin >> noNodes >> noEdges;

    values.resize(noNodes);
    destination.resize(noNodes);

    for (int i=0; i<noNodes; i++) cin >> values[i];
    for (int i=0; i<noEdges; i++) {
        int start, end;
        cin >> start >> end;
        destination[start].push_back(end);
    }


    //TODO: เข้าใจว่า DAG คืออะไรกันแน่ แล้วก็เอาหัวกราฟมา iterate ทั้งหมด
    dfs(0, values[0]);
    cout << maxDifference;
}