/*
ID: anirudh71
TASK: lasers
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<ll, ll> pii;

ll N, P;
vector<pii> posts;
unordered_map<ll, vector<ll>> xs, ys;

ll bfs(bool horiz) {

    vector<ll> dist(P, LLONG_MAX);
    dist[0] = 0;
    deque<ll> q;
    q.push_front(0);

    while (!q.empty()) {
        ll cur = q.front();
        q.pop_front();
        for (ll adj : xs[posts[cur].first]) {
            if (dist[cur] + horiz < dist[adj]) {
                dist[adj] = dist[cur] + horiz;
                if (horiz) q.push_back(adj);
                else q.push_front(adj);
            }
        }
        for (ll adj : ys[posts[cur].second]) {
            if (dist[cur] + !horiz < dist[adj]) {
                dist[adj] = dist[cur] + !horiz;
                if (!horiz) q.push_back(adj);
                else q.push_front(adj);
            }
        }
    }

    // for (int i = 0; i < P; i++) cout << dist[i] << " "; cout << endl;

    return dist[P - 1]; 

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("lasers.in");
    ofstream fout("lasers.out");

    fin >> N;
    P = N + 2;
    posts.resize(P);
    fin >> posts[0].first >> posts[0].second >> posts[P - 1].first >> posts[P - 1].second;
    for (ll i = 1; i <= N; i++)
        fin >> posts[i].first >> posts[i].second;

    for (ll i = 0; i < P; i++) {
        xs[posts[i].first].push_back(i);
        ys[posts[i].second].push_back(i);
    }

    ll ans = min(bfs(true), bfs(false));
    fout << (ans == LLONG_MAX ? -1 : ans) << endl;

    return 0;

}