/*
ID: anirudh71
TASK: moocast
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Cow {
    int x;
    int y;
    int power;
    vector<pair<int, int>> reachable;
    bool visited;
};

int N;
vector<Cow> cows(201);
int transmitted;

void dfs(int cur) {
    transmitted++;
    cows[cur].visited = true;
    for (auto x : cows[cur].reachable) {
        if (cows[x.first].visited) continue;
        dfs(x.first);
    }
}

int main() {

    ifstream fin("moocast.in");
    ofstream fout("moocast.out");

    fin >> N;
    for (int i = 0; i < N; i++) {
        int x, y, power;
        fin >> x >> y >> power;
        Cow c;
        c.x = x, c.y = y, c.power = power;
        cows[i] = c;
    }

    for (int c1 = 0; c1 < N; c1++) {
        for (int c2 = 0; c2 < N; c2++) {
            double dist = sqrt(pow(cows[c2].x - cows[c1].x, 2) + pow(cows[c2].y - cows[c1].y, 2));
            if (cows[c1].power >= dist) cows[c1].reachable.push_back({c2, dist});
            if (cows[c2].power >= dist) cows[c2].reachable.push_back({c1, dist});
        }
    }

    int ans = 0;

    for (int start = 0; start < N; start++) {
        transmitted = 0;
        for (int i = 0; i < N; i++) cows[i].visited = false;
        dfs(start);
        ans = max(ans, transmitted);
    }

    fout << ans << endl;

    return 0;

}
