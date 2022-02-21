/*
ID: anirudh71
TASK: ccski
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int M, N;
int elevations[501][501];
bool visited[501][501];
vector<pii> waypoints;

bool valid(int i, int j) {
    return i >= 0 && i < M && j >= 0 && j < N;
}

void dfs(int i, int j, int D, int prev) {
    if (!valid(i, j) || visited[i][j] || abs(elevations[i][j] - prev) > D) return;
    visited[i][j] = true;
    dfs(i+1, j, D, elevations[i][j]);
    dfs(i-1, j, D, elevations[i][j]);
    dfs(i, j+1, D, elevations[i][j]);
    dfs(i, j-1, D, elevations[i][j]);
}

bool check(int D) {
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            visited[i][j] = false;
    dfs(waypoints[0].first, waypoints[0].second, D, elevations[waypoints[0].first][waypoints[0].second]);
    for (pii wp : waypoints)
        if (!visited[wp.first][wp.second])
            return false;
    return true;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("ccski.in");
    ofstream fout("ccski.out");

    fin >> M >> N;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++) 
            fin >> elevations[i][j];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            bool b; fin >> b;
            if (b) waypoints.push_back({i, j});
        }
    }

    // binary search on D
    int lo = 0, hi = 1e9;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }

    fout << lo << endl;

    return 0;

}
