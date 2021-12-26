/*
ID: anirudh71
TASK: mootube
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
    vector<pair<int, int>> adj;
    bool visited;
};

int N, Q;
vector<Node> videos(5001);
int ans;

void dfs(int k, int v, int rel) {
    if (rel >= k) ans++;
    videos[v].visited = true;
    for (auto x : videos[v].adj) {
        if (videos[x.first].visited) continue;
        dfs(k, x.first, min(rel, x.second));
    }
}

int main() {

    ifstream fin("mootube.in");
    ofstream fout("mootube.out");

    fin >> N >> Q;
    for (int i = 0; i < N; i++) videos[i] = Node();
    for (int i = 0; i < N - 1; i++) {
        int a, b, r;
        fin >> a >> b >> r;
        a--, b--;
        videos[a].adj.push_back({b, r});
        videos[b].adj.push_back({a, r});
    }

    for (int q = 0; q < Q; q++) {
        for (int i = 0; i < N; i++) videos[i].visited = false;
        ans = -1;
        int k, v;
        fin >> k >> v;
        v--;
        dfs(k, v, 1e9);
        fout << ans << endl;
    }

    return 0;

}
