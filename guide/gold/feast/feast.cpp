/*
ID: anirudh71
TASK: feast
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int T, A, B;
vector<vector<vector<int>>> dp;

int solve(int o, int l, bool w, bool w_used) { // figure out how to incorporate water correctly
    int cur = o * A + l * B;
    if (w && !w_used) {
        cur /= 2;
        w_used = true;
    }
    if (cur > T) return 0;
    if (dp[o][l][w] != -1) return dp[o][l][w];
    int orange = solve(o + 1, l, w, w_used);
    int lemon = solve(o, l + 1, w, w_used);
    int water = !w_used ? solve(o, l, true, w_used) : 0;
    return dp[o][l][w] = cur + max(orange, max(lemon, water));
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("feast.in");
    ofstream fout("feast.out");

    fin >> T >> A >> B;
    dp.resize(T / A + 1, vector<vector<int>>(T / B + 1, vector<int>(2)));
    for (int i = 0; i <= T / A; i++)
        for (int j = 0; j <= T / B; j++)
            for (int k = 0; k < 2; k++)
                dp[i][j][k] = -1;

    int max_fullness = solve(0, 0, false, false);

    for (int i = 0; i <= T / A; i++) {
        for (int j = 0; j <= T / B; j++) {
            for (int k = 0; k < 1; k++) {
                cout << i << " " << j << " " << k << " : " << dp[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    fout << max_fullness << endl;

    return 0;

}