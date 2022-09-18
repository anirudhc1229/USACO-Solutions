/*
ID: anirudh71
TASK: cowntagion
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<int> adj[100001];

int dfs(int cur, int parent) {
    int days = 0;
    int children = 0;
    for (int a : adj[cur]) {
        if (a == parent) continue;
        children++;
        days += 1 + dfs(a, cur);
    }
    days += ceil(log2(children + 1)); // bit length
    return days;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("cowntagion.in");
    ofstream fout("cowntagion.out");

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << dfs(0, -1) << endl;

    return 0;

}