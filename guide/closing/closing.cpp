/*
ID: anirudh71
TASK: closing
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Barn {
    vector<int> adj;
    bool visited;
    bool closed;
};

vector<Barn> barns;
int N, M;

void dfs(int cur) {
    barns[cur].visited = true;
    for (int b : barns[cur].adj) {
        if (barns[b].visited || barns[b].closed) continue;
        dfs(b);
    }
}

bool connected(int start) {
    for (int i = 0; i < N; i++) barns[i].visited = false;
    dfs(start);
    for (Barn b : barns) if (!b.visited && !b.closed) return false;
    return true;
}

int main() {

    ifstream fin("closing.in");
    ofstream fout("closing.out");

    fin >> N >> M;
    for (int i = 0; i < N; i++) barns.push_back(Barn());
    for (int i = 0; i < M; i++) {
        int a, b;
        fin >> a >> b;
        a--; b--;
        barns[a].adj.push_back(b);
        barns[b].adj.push_back(a);
    }

    for (int i = 0; i < N; i++) barns[i].closed = false;

    vector<int> toClose(N);
    for (int i = 0; i < N; i++) {
        fin >> toClose[i];
        toClose[i]--;
    }

    if (connected(0)) fout << "YES" << endl;
    else fout << "NO" << endl;

    for (int i = 0; i < N - 1; i++) {
        barns[toClose[i]].closed = true;
        if (connected(toClose[N-1])) fout << "YES" << endl; 
        else fout << "NO" << endl;
    }

    return 0;

}
