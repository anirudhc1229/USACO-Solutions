/*
ID: anirudh71
TASK: wormhole
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Wormhole {
    int x;
    int y;
    int walk;
    int portal;
};

int N;
Wormhole wormholes[13];
int ans = 0;

bool check() {
    
    for (int start = 1; start <= N; start++) {
        int pos = start;
        for (int count = 0; count < N; count++) 
            pos = wormholes[wormholes[pos].portal].walk;
        if (pos != 0) return true;
    }

    return false;

}

void dfs() {
    
    int i;
    for (i = 1; i <= N; i++) 
        if (!wormholes[i].portal) break;

    if (i == N + 1) if (check()) ans++;

    for (int j = i + 1; j <= N; j++) {
        if (!wormholes[j].portal) {
            wormholes[i].portal = j;
            wormholes[j].portal = i;
            dfs();
            wormholes[i].portal = wormholes[j].portal = 0;
            cout << i << " " << j << endl;
        }
    }

}

int main() {

    ifstream fin("wormhole.in");
    ofstream fout("wormhole.out");

    fin >> N;
    wormholes[0] = {-1, -1, 0, 0};
    for (int i = 1; i <= N; i++) {
        int x, y;
        fin >> x >> y;
        wormholes[i] = {x, y, 0, 0};
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            if (wormholes[i].x < wormholes[j].x && wormholes[i].y == wormholes[j].y)
                if (!wormholes[i].walk || wormholes[j].x < wormholes[wormholes[i].walk].x)
                    wormholes[i].walk = j;
        }
    }
         
    dfs();

    fout << ans << endl;

    return 0;

}
