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

int N;
vector<pii> cows;
int dp[2501][2501];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("rectpast.in");
    ofstream fout("rectpast.out");

    fin >> N;
    cows.resize(N);
    for (pii& c : cows) fin >> c.first >> c.second;

    // compress coordinates
    sort(cows.begin(), cows.end());
    for (int i = 0; i < N; i++) cows[i].first = i;
    sort(cows.begin(), cows.end(), [](pii a, pii b) -> bool {
        return a.second < b.second;});
    for (int i = 0; i < N; i++) cows[i].second = i;

    // generate 2d prefix sum array
    for (pii c : cows) dp[c.first][c.second] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i) dp[i][j] += dp[i-1][j];
            if (j) dp[i][j] += dp[i][j-1];
            if (i && j) dp[i][j] -= dp[i-1][j-1];
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            int x1 = min(cows[i].first, cows[j].first);
            int x2 = max(cows[i].first, cows[j].first);
            int rect1 = dp[x1][j] - dp[x1][i] - dp[0][j] + dp[0][i];
            int rect2 = dp[x2][j] - dp[x2][i] - dp[N-1][j] + dp[N-1][i];
            ans += rect1 * rect2;
        }
    }

    fout << ans << endl;

    return 0;

}
