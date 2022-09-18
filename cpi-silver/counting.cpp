/*
ID: anirudh71
TASK: counting
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
bool wall[1001][1001];
bool vis[1001][1001];

void ff(int i, int j) {
    // cout << i << " " << j << endl;
    if (i < 0 || i >= n || j < 0 || j >= m) return;
    if (vis[i][j]) return;
    vis[i][j] = true;
    if (wall[i][j]) return;
    ff(i + 1, j);
    ff(i - 1, j);
    ff(i, j + 1);
    ff(i, j - 1);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("counting.in");
    ofstream fout("counting.out");

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            wall[i][j] = c == '#';
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            vis[i][j] = false;

    int rooms = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] || wall[i][j]) continue;
            ff(i, j);
            rooms++;
        }
    }

    cout << rooms << endl;

    return 0;

}