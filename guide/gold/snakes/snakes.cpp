/*
ID: anirudh71
TASK: snakes
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int n, k;
int snakes[401];
int dp[401][401]; // dp[group][switches] = net_total

int net_total(int group, int switches, int net) {
    if (group >= n) return 0;
    if (switches > k) return INT_MAX;
    if (dp[group][switches] != -1) return dp[group][switches];
    
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("snakes.in");
    ofstream fout("snakes.out");

    fin >> n >> k;
    for (int i = 0; i < n; i++)
        fin >> snakes[i];

    int sum = 0; 
    for (int i = 0; i < n; i++)
        sum += snakes[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;

    fout << net_total(0, 0, 0) - sum << endl;

    return 0;

}