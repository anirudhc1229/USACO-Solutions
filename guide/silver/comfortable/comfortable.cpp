/*
ID: anirudh71
TASK: comfortable
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

bool cow[1001][1001];
int adj[1001][1001];
bool visited[1001][1001];

bool valid(int i, int j) {
    return i >= 0 && i <= 1000 && j >= 0 && j <= 1000;
}

void dfs(int i, int j) {
    if (!valid(i, j) || !cow[i][j] || visited[i][j]) return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("comfortable.in");
    ofstream fout("comfortable.out");

    int N; fin >> N;
    for (int n = 0; n < N; n++) {

        int x, y;
        fin >> x >> y;
        cow[x][y] = true;
        for (int i = 0; i <= 1000; i++)
            for (int j = 0; j <= 1000; j++)
                visited[i][j] = false;
        dfs(x, y);

    }

    return 0;

}
