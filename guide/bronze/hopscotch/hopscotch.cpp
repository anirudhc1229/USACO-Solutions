/*
ID: anirudh71
TASK: hopscotch
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
char grid[16][16];
int ans;

void dfs(int x, int y) {
    
    if (x == N - 1 && y == M - 1) ans++;

    for (int i = x + 1; i < N; i++) {
        for (int j = y + 1; j < M; j++) {
            if (grid[x][y] == grid[i][j]) continue;
            dfs(i, j);
        }
    }

}

int main() {

    ifstream fin("hopscotch.in");
    ofstream fout("hopscotch.out");

    fin >> N >> M;
    for (int i = 0; i < N; i++) {
        string line; fin >> line;
        for (int j = 0; j < M; j++)
            grid[i][j] = line[j];
    }

    ans = 0;
    dfs(0, 0);
    fout << ans << endl;

    return 0;

}
