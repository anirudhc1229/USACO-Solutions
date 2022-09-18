/*
ID: anirudh71
TASK: paintbarn
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int pre[1001][1001];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("paintbarn.in");
    ofstream fout("paintbarn.out");

    int n, k; cin >> n >> k;
    memset(pre, 0, sizeof pre);
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        pre[x2][y2]++;
        pre[x1][y2]--;
        pre[x2][y1]--;
        pre[x1][y1]++;
    }

    int ans = 0;
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
            if (pre[i][j] == k) ans++;
        }
    }

    cout << ans << endl;

    return 0;

}