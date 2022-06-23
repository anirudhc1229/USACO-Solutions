/*
ID: anirudh71
TASK: hps
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int n, k;
int fj[100001];
int dp[100001][21][3];

int solve(int i, int s, int cur) {
    if (i == n) return 0;
    if (dp[i][s][cur] != -1) return dp[i][s][cur];
    bool win = cur == 0 && fj[i] == 2 || cur == 1 && fj[i] == 0 || cur == 2 && fj[i] == 1;
    int no_switch = solve(i + 1, s, cur);
    int switch1 = s < k ? solve(i + 1, s + 1, (cur + 1) % 3) : 0;
    int switch2 = s < k ? solve(i + 1, s + 1, (cur + 2) % 3) : 0;
    return dp[i][s][cur] = win + max(max(no_switch, switch1), switch2);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("hps.in");
    ofstream fout("hps.out");

    fin >> n >> k;
    for (int i = 0; i < n; i++) {
        char c; fin >> c;
        if (c == 'H') fj[i] = 0;
        else if (c == 'P') fj[i] = 1;
        else fj[i] = 2;
    }

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            for (int l = 0; l < 3; l++)
                dp[i][j][l] = -1;

    int max_wins = max(max(solve(0, 0, 0), solve(0, 0, 1)), solve(0, 0, 2));
    fout << max_wins << endl;

    return 0;

}