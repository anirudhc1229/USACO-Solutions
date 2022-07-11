/*
ID: anirudh71
TASK: time
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int N, M, C;
int moonies[1001];
vector<int> adj[1001];
int dp[1001][1001];
int ans;

int solve(int city, int days, int mooney) {
    if (days > 1000) return 0;
    if (dp[city][days] != -1) return dp[city][days];
    int max_mooney = mooney - C * days * days;
    for (int a : adj[city])
        max_mooney = max(max_mooney, solve(a, days + 1, max_mooney + moonies[a]));
    if (!city) ans = max(ans, max_mooney);
    return dp[city][days] = max_mooney;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("time.in");
    ofstream fout("time.out");

    fin >> N >> M >> C;
    for (int i = 0; i < N; i++)
        fin >> moonies[i];
    for (int i = 0; i < M; i++) {
        int a, b; fin >> a >> b;
        adj[--a].push_back(--b);
    }

    for (int i = 0; i <= N; i++)
        for (int j = 0; j < 1001; j++)
            dp[i][j] = -1;

    ans = 0;
    int s = solve(0, 0, 0);
    fout << ans << endl;

    return 0;

}