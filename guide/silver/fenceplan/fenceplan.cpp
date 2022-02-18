/*
ID: anirudh71
TASK: fenceplan
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

struct Cow {
    int x;
    int y;
    vector<int> adj;
    bool visited;
};

int N, M;
vector<Cow> cows;
vector<int> net;

void dfs(int cur) {
    cows[cur].visited = true;
    net.push_back(cur);
    for (int i : cows[cur].adj) {
        if (cows[i].visited) continue;
        dfs(i);
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("fenceplan.in");
    ofstream fout("fenceplan.out");

    fin >> N >> M;
    cows.resize(N);
    for (Cow& c : cows) {
        fin >> c.x >> c.y;
        c.visited = false;
    }
    for (int i = 0; i < M; i++) {
        int a, b; fin >> a >> b;
        cows[a-1].adj.push_back(b-1);
        cows[b-1].adj.push_back(a-1);
    }

    vector<vector<int>> networks;
    for (int i = 0; i < N; i++) {
        if (cows[i].visited) continue;
        net.clear();
        dfs(i);
        networks.push_back(net);
    }

    for (vector<int> net : networks) {
        for (int i : net) cout << i << " ";
        cout << endl;
    }

    int ans = INT32_MAX;
    for (vector<int> net : networks) {
        int minX = 1e8, maxX = 0, minY = 1e8, maxY = 0;
        for (int i : net) {
            minX = min(minX, cows[i].x);
            maxX = max(maxX, cows[i].x);
            minY = min(minY, cows[i].y);
            maxY = max(maxY, cows[i].y);
        }
        ans = min(ans, 2 * (maxX - minX) + 2 * (maxY - minY));
    }

    fout << ans << endl;

    return 0;

}
