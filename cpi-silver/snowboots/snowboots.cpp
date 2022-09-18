/*
ID: anirudh71
TASK: snowboots
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<ll, ll> pii;

ll n, b;
ll depth[251];
pii boots[251];
ll dp[251][251]; // dp[tile][boot] = minimum waste

ll solve(ll tile, ll boot) {

    // cout << tile << " " << boot << " " << dp[tile][boot] << endl;

    if (tile >= n) return 0;
    if (boot >= b) return INT_MAX;
    if (depth[tile] > boots[boot].first) return INT_MAX;
    if (dp[tile][boot] != -1) return dp[tile][boot];
    // cout << tile << " " << boot << endl;
    dp[tile][boot] = INT_MAX;
    
    // can keep same boots and try each tile to skip forward to
    for (ll i = 1; i <= boots[boot].second; i++)
        dp[tile][boot] = min(dp[tile][boot], solve(tile + i, boot));

    // can switch boots now and try each boot
    for (ll i = 1; i <= b; i++)
        dp[tile][boot] = min(dp[tile][boot], i + solve(tile, boot + i));

    return dp[tile][boot];

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("snowboots.in");
    ofstream fout("snowboots.out");

    cin >> n >> b;
    for (ll i = 0; i < n; i++) 
        cin >> depth[i];
    for (ll i = 0; i < b; i++) 
        cin >> boots[i].first >> boots[i].second;

    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < b; j++)
            dp[i][j] = -1;
    cout << solve(0, 0) << endl;

    return 0;

}