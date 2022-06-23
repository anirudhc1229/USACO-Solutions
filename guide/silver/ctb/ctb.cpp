/*
ID: anirudh71
TASK: ctb
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int N, M;
// vector<vector<int>> adj;
vector<pii> adj[100001];

int shortestPath() {

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(N, INT32_MAX);

    pq.push({0, 0});
    dist[0] = 0;

    while (!pq.empty()) {

        int cur = pq.top().second;
        pq.pop();

        for (pii a : adj[cur]) {
            int v = a.first;
            int weight = a.second;
            if (dist[v] > dist[cur] + weight) {
                dist[v] = dist[cur] + weight;
                pq.push({dist[v], v});
            }
        }

    }

    return dist[N - 1];

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("ctb.in");
    ofstream fout("ctb.out");

    int T; cin >> T;
    for (int t = 0; t < T; t++) {

        cin >> N >> M;
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            adj[a].push_back({b, 0});
            adj[b].push_back({a, 0});
        }
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                adj[i].push_back({j, pow(i - j, 2)});

        cout << shortestPath() << endl;

    }

    return 0;

}
