/*
ID: anirudh71
TASK: stuckinarut
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
    int id;
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("stuckinarut.in");
    ofstream fout("stuckinarut.out");

    int N; cin >> N;
    vector<Cow> north, east;
    for (int i = 0; i < N; i++) {
        char dir; cin >> dir;
        int x, y; cin >> x >> y;
        if (dir == 'N') north.push_back({x, y, i});
        else east.push_back({x, y, i});
    }

    sort(north.begin(), north.end(), 
        [](Cow& a, Cow& b) -> bool {return a.x < b.x;});
    sort(east.begin(), east.end(), 
        [](Cow& a, Cow& b) -> bool {return a.y < b.y;});
    vector<int> dist(N);
    for (int i = 0; i < N; i++) dist[i] = INT32_MAX;

    for (Cow& n : north) {
        for (Cow& e : east) {
            if (dist[n.id] != INT32_MAX || dist[e.id] != INT32_MAX) continue;
            if (!(e.x < n.x && n.y < e.y)) continue; // n and e don't intersect
            pii inter = {n.x, e.y};
            if (inter.second - n.y < inter.first - e.x) 
                dist[e.id] = inter.first - e.x; // n reaches before e
            else if (inter.first - e.x < inter.second - n.y) 
                dist[n.id] = inter.second - n.y; // e reaches before n
        }
    }

    for (int d : dist) cout << (d == INT32_MAX ? "Infinity" : to_string(d)) << endl;

    return 0;

}
