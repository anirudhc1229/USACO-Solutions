#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Cow {
    int x;
    int y;
    vector<int> adj;
    bool visited;
};

vector<Cow> cows;
vector<int> net;

void dfs(int cur) {
    cows[cur].visited = true;
    net.push_back(cur);
    for (int i : cows[cur].adj) {
        if (!cows[i].visited) { 
            dfs(i);
        }
    }
}

int main() {
    ifstream fin("fenceplan.in");
    int N, M;
    fin >> N >> M;
    cows.resize(N);
    for (Cow& c : cows) {
        fin >> c.x >> c.y;
        c.visited = false;
    }
    for (int i = 0; i < M; i++) {
        int a, b; 
        fin >> a >> b;
        cows[a - 1].adj.push_back(b - 1);
        cows[b - 1].adj.push_back(a - 1);
    }

    // group cows into networks using dfs
    vector<vector<int>> networks;
    for (int i = 0; i < N; i++) {
        if (cows[i].visited) continue;
        net.clear();
        dfs(i);
        networks.push_back(net);
    }

    // find the minimum perimeter among all networks
    int ans = INT32_MAX;
    for (vector<int> net : networks) {
        int min_x = 1e8, max_x = 0, min_y = 1e8, max_y = 0;
        for (int i : net) {
            min_x = min(min_x, cows[i].x);
            max_x = max(max_x, cows[i].x);
            min_y = min(min_y, cows[i].y);
            max_y = max(max_y, cows[i].y);
        }
        ans = min(ans, 2 * (max_x - min_x) + 2 * (max_y - min_y));
    }

    ofstream fout("fenceplan.out");
    fout << ans << endl;
}
