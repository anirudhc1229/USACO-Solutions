/*
ID: anirudh71
TASK: checklist
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int dp[1001][1001]; // dp[i][j] = min energy to visit first i hs and first j gs

int solve(int i, int j, int cur) {
    
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("checklist.in");
    ofstream fout("checklist.out");

    int H, G; fin >> H >> G;
    vector<pii> hs(H);
    for (pii& h : hs) fin >> h.first >> h.second;
    vector<pii> gs(G);
    for (pii& g : gs) fin >> g.first >> g.second;

    // at each step, choose to either go to next h or next g
    // for (int i = 0; i <= H; i++) {
    //     for (int j = 0; j <= G; j++) {
    //         if (!i || !j) { dp[i][j] = 0; continue; }
    //         int mn = min(dp[i - 1][j], dp[i][j - 1]);
    //         int energy;
    //         if (mn == dp[i - 1][j]) energy = pow() + pow();
    //         else energy = pow() + pow();
    //         dp[i][j] = mn + energy;
    //     }
    // }

    fout << dp[H][G] << endl;

    return 0;

}