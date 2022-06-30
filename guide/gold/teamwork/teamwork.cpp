/*
ID: anirudh71
TASK: teamwork
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int n, k;
int cows[10001];
int dp[10001]; // dp[c] = max skill of first c cows

int solve(int c) { // compute max skill of first c cows
    if (c == 0) return 0;
    if (dp[c] != -1) return dp[c];
    int suf_max[c];
    suf_max[c - 1] = cows[c - 1];
    for (int i = c - 2; i >= 0; i--)
        suf_max[i] = max(suf_max[i + 1], cows[i]);
    int mx = 0;
    for (int i = 1; i <= (int)min(c, k); i++)
        mx = max(mx, i * suf_max[c - i] + solve(c - i));
    return dp[c] = mx;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("teamwork.in");
    ofstream fout("teamwork.out");

    fin >> n >> k;
    for (int i = 0; i < n; i++) fin >> cows[i];
    memset(dp, -1, sizeof dp);

    fout << solve(n) << endl;

    return 0;

}