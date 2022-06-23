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

int N;
vector<int> adj[100001];
int infected[100001];
bool visited[100001];
int days;

void dfs(int cur, int d) {

    cout << days << endl;
    visited[cur] = true;
    if (d == days) return;
    
    infected[cur] *= 2;
    dfs(cur, d + 1);
    infected[cur] /= 2;

    for (int a : adj[cur]) {
        if (visited[a] || infected[cur] <= 1) continue;
        infected[a]++;
        infected[cur]--;
        dfs(a, d + 1);
        infected[a]--;
        infected[cur]++;
    }

}

bool check(int mid) {

    fill(infected, infected + N, false);
    fill(visited, visited + N, false);
    infected[0] = 1;
    days = mid;
    
    dfs(0, 1); // maybe use d = 0 instead?
    for (int i = 0; i < N; i++)
        if (!infected[i]) return false;
    return true;

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("cowntagion.in");
    ofstream fout("cowntagion.out");

    fin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        fin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    int lo = 0, hi = INT32_MAX;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }

    fout << lo << endl;

    return 0;

}
