/*
ID: anirudh71
TASK: rectpast
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

vector<pii> cows;
int dp[2501][2501];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // ifstream fin("rectpast.in");
    // ofstream fout("rectpast.out");

    int n; cin >> n;
    cows.resize(n);
    for (int i = 0; i < n; i++)
        cin >> cows[i].first >> cows[i].second;

    // compress coordinates
    sort(cows.begin(), cows.end(), 
        [](pii a, pii b) -> bool {return a.second < b.second;});
    for (int i = 0; i < n; i++)
        cows[i].second = i + 1;
    sort(cows.begin(), cows.end());
    for (int i = 0; i < n; i++)
        cows[i].first = i + 1;

    // for (pii c : cows) cout << c.first << ", " << c.second << endl;

    // make prefix sum array
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = dp[i - 1][j] + (j >= cows[i - 1].second);

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    ll ans = 1;
    for (int i = 0; i < n; i++) { // rightmost cow
        for (int j = i; j >= 0; j--) { // leftmost cow
            int above = 0, below = 0;
            if (cows[j].second > cows[i].second) {
                above = dp[i + 1][n] - dp[i + 1][cows[j].second - 1] - dp[j][n] + dp[j][cows[j].second - 1];
                below = dp[i + 1][cows[i].second] - dp[i + 1][0] - dp[j][cows[i].second] + dp[j][0];
            } else {
                above = dp[i + 1][n] - dp[i + 1][cows[i].second - 1] - dp[j][n] + dp[j][cows[i].second - 1];
                below = dp[i + 1][cows[j].second] - dp[i + 1][0] - dp[j][cows[j].second] + dp[j][0];
            }
            ans += (ll)(above * below);
        }
    }

    cout << ans << endl;

    return 0;

}