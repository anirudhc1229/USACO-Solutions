/*
ID: anirudh71
TASK: multimoo
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
#include <unordered_set>

int n;
int ids[251][251];
bool vis[251][251];
unordered_set<int> cows;

int dfs1(int i, int j, int id) {
    if (i < 0 || i >= n || j < 0 || j >= n || vis[i][j] || ids[i][j] != id) return 0;
    vis[i][j] = true;
    return 1 + dfs1(i + 1, j, id) + dfs1(i, j + 1, id) + dfs1(i - 1, j, id) + dfs1(i, j - 1, id);
}

int dfs2(int i, int j, int id1, int id2) {
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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin >> ids[i][j];
            cows.insert(ids[i][j]);
        }
    }

    memset(vis, false, sizeof vis);
    int best1 = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!vis[i][j]) best1 = max(best1, dfs1(i, j, ids[i][j]));
    fout << best1 << endl;

    int best2 = 0;
    for (auto id2 : cows) {
        memset(vis, false, sizeof vis);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (!vis[i][j] && ids[i][j] != id2) best2 = max(best2, dfs2(i, j, ids[i][j], id2));
    }
    fout << best2 << endl;

    return 0;

}