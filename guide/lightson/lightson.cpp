/*
ID: anirudh71
TASK: lightson
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<pair<int, int>> switches[101][101];
vector<pair<int, int>> adj = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool visited[101][101];
int N, M;
int ans;

bool valid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

void dfs(int x, int y, bool lit[101][101]) {

    cout << x << " " << y << endl;
    
    for (pair<int, int> s : switches[x][y]) {
        lit[s.first][s.second] = true;
        for (pair<int, int> a : adj) {
            if (!valid(s.first + a.first, s.second + a.second) || !visited[s.first + a.first][s.second + a.second] || !lit[s.first + a.first][s.second + a.second]) continue;
            visited[s.first][s.second] = true;
            dfs(s.first, s.second, lit);
            visited[s.first][s.second] = false;
        }
    }

    bool found = false;
    for (pair<int, int> a : adj) {
        if (!valid(x + a.first, y + a.second) || visited[x + a.first][y + a.second] || !lit[x + a.first][y + a.second]) continue;
        found = true;
        visited[x + a.first][y + a.second] = true;
        dfs(x + a.first, y + a.second, lit);
        visited[x + a.first][y + a.second] = false;
    }

    if (!found) {
        int count = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (lit[x][y]) count++;
        ans = max(ans, count);
    }

}

int main() {

    ifstream fin("lightson.in");
    ofstream fout("lightson.out");

    fin >> N >> M;
    bool lit[101][101];
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            lit[i][j] = visited[i][j] = false;
    lit[0][0] = true;
    visited[0][0] = true;
    for (int i = 0; i < M; i++) {
        int x, y, a, b;
        fin >> x >> y >> a >> b;
        switches[--x][--y].push_back({--a, --b});
    }

    ans = 0;
    dfs(0, 0, lit);
    fout << ans << endl;

    return 0;

}
