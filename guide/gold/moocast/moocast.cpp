/*
ID: anirudh71
TASK: moocast
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
    bool visited;
};

int N;
vector<Cow> cows;

ll dist(int a, int b) {
    return pow(cows[a].x - cows[b].x, 2) + pow(cows[a].y - cows[b].y, 2);
}

void dfs(int cur, ll X) {
    cows[cur].visited = true;
    for (int i = 0; i < N; i++) {
        if (cows[i].visited) continue;
        if (dist(cur, i) > X) continue;
        dfs(i, X);
    }
}

bool check(ll X) {
    for (Cow& c : cows) c.visited = false;
    dfs(0, X);
    for (Cow& c : cows) if (!c.visited) return false;
    return true;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("moocast.in");
    ofstream fout("moocast.out");

    fin >> N;
    cows.resize(N);
    for (Cow& c : cows) fin >> c.x >> c.y;

    int lo = 1, hi = INT32_MAX;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }

    fout << lo << endl;

    return 0;

}
