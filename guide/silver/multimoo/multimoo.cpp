/*
ID: anirudh71
TASK: multimoo
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<ll, ll> pii;
#include <unordered_set>

ll n;
ll ids[251][251];
bool vis[251][251];
unordered_set<ll> cows;

ll dfs1(ll i, ll j, ll id) {
    if (i < 0 || i >= n || j < 0 || j >= n || vis[i][j] || ids[i][j] != id) return 0;
    vis[i][j] = true;
    return 1 + dfs1(i + 1, j, id) + dfs1(i, j + 1, id) + dfs1(i - 1, j, id) + dfs1(i, j - 1, id);
}

ll dfs2(ll i, ll j, ll id1, ll id2) {
    if (i < 0 || i >= n || j < 0 || j >= n || vis[i][j] || (ids[i][j] != id1 && ids[i][j] != id2)) return 0;
    vis[i][j] = true;
    return 1 + dfs2(i + 1, j, id1, id2) + dfs2(i, j + 1, id1, id2) + dfs2(i - 1, j, id1, id2) + dfs2(i, j - 1, id1, id2);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("multimoo.in");
    ofstream fout("multimoo.out");

    fin >> n;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            fin >> ids[i][j];
            cows.insert(ids[i][j]);
        }
    }

    memset(vis, false, sizeof vis);
    ll best1 = 0;
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
            if (!vis[i][j]) best1 = max(best1, dfs1(i, j, ids[i][j]));
    fout << best1 << endl;

    ll best2 = 0;
    for (auto id2 : cows) {
        memset(vis, false, sizeof vis);
        for (ll i = 0; i < n; i++)
            for (ll j = 0; j < n; j++)
                if (!vis[i][j] && ids[i][j] != id2) best2 = max(best2, dfs2(i, j, ids[i][j], id2));
    }
    fout << best2 << endl;

    return 0;

}