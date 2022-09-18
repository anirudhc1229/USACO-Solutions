/*
ID: anirudh71
TASK: lightson
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<ll, ll> pii;

ll n, m;
bool vis[101][101];
bool lit[101][101];
vector<pii> switches[101][101];

void ff(ll i, ll j) {
    if (i < 0 || i >= n || j < 0 || j >= n) return;
    if (!lit[i][j]) return;
    if (vis[i][j]) return;
    vis[i][j] = true;
    for (pii s : switches[i][j]) {
        ll a = s.first;
        ll b = s.second;
        lit[a][b] = true;
        if ((a > 0 && vis[a - 1][b]) || (a < n - 1 && vis[a + 1][b]) || (b > 0 && vis[a][b - 1]) || (b < n - 1 && vis[a][b + 1]))
            ff(a, b);
    }
    ff(i - 1, j);
    ff(i, j - 1);
    ff(i + 1, j);
    ff(i, j + 1);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("lightson.in");
    ofstream fout("lightson.out");

    cin >> n >> m;
    for (ll i = 0; i < m; i++) {
        ll x, y, a, b;
        cin >> x >> y >> a >> b;
        x--; y--; a--; b--;
        switches[x][y].push_back({a, b});
    }

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            vis[i][j] = false;
            lit[i][j] = false;
        }
    }

    lit[0][0] = true;
    ff(0, 0);

    ll ans = 0;
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
            ans += lit[i][j];
    cout << ans << endl;

    return 0;

}