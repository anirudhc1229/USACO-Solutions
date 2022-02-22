/*
ID: anirudh71
TASK: countcross
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int N, K, R;
set<tuple<int, int, int, int>> roads;
vector<pii> cows;
bool visited[101][101];

bool valid(int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < N;
}

void dfs(int i, int j, int prev_i, int prev_j) {
    if (!valid(i, j) || visited[i][j] || roads.count({i, j, prev_i, prev_j})) return;
    visited[i][j] = true;
    dfs(i + 1, j, i, j);
    dfs(i - 1, j, i, j);
    dfs(i, j + 1, i, j);
    dfs(i, j - 1, i, j);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("countcross.in");
    ofstream fout("countcross.out");

    fin >> N >> K >> R;
    for (int i = 0; i < R; i++) {
        int x1, y1, x2, y2;
        fin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        roads.insert({x1, y1, x2, y2});
        roads.insert({x2, y2, x1, y1});
    }
    cows.resize(K);
    for (pii& c : cows) {
        fin >> c.first >> c.second;
        c.first--; c.second--;
    }

    int ans = 0;
    for (pii start : cows) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                visited[i][j] = false;
        dfs(start.first, start.second, -1, -1);
        for (pii c : cows)
            if (!visited[c.first][c.second]) ans++;
    }

    fout << ans / 2 << endl;

    return 0;

}
