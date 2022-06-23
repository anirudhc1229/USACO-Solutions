/*
ID: anirudh71
TASK: 1
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

ll N;
ll prefs[501][501];
bool possible[501][501];
bool visited[501][501];
bool used[501];

void dfs(ll row) {
    
    if (row == N) {
        for (ll i = 0; i < N; i++)
            for (ll j = 0; j < N; j++)
                if (visited[i][j]) possible[i][j] = true;
        return;
    }

    for (ll j = 0; j < N && prefs[row][j] != -1; j++) {
        if (used[prefs[row][j]]) continue;
        visited[row][j] = true;
        used[prefs[row][j]] = true;
        dfs(row + 1);
        visited[row][j] = false;
        used[prefs[row][j]] = false;
    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("1.in");
    ofstream fout("1.out");

    fin >> N;
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            ll p; fin >> p;
            prefs[i][j] = --p;
        }
    }

    for (ll i = 0; i < N; i++) {
        bool bad = false;
        for (ll j = 0; j < N; j++) {
            if (bad) prefs[i][j] = -1;
            if (prefs[i][j] == i) bad = true;
        }
    }

    dfs(0);

    for (ll i = 0; i < N; i++) {
        ll j = 0;
        while (j < N && !possible[i][j]) j++;
        fout << ++prefs[i][j] << endl;
    }

    return 0;

}
