/*
ID: anirudh71
TASK: planting
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[100001];
bool visited[100001];

void dfs(int cur, int dist) {
    if (!dist) return;
    visited[cur] = true;
    for (int i : adj[cur]) {
        if (visited[i]) continue;
        dfs(i, dist - 1);
    }
}

int main() {

    ifstream fin("planting.in");
    ofstream fout("planting.out");

    int N;
    fin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        fin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) visited[j] = false;
        dfs(i, 2);
        int reached = 0;
        for (int i = 0; i < N; i++) reached += visited[i];
        ans = max(ans, reached);
    }

    fout << ans << endl;

    return 0;

}
