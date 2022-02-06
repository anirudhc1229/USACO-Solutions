/*
ID: anirudh71
TASK: revegetate
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("revegetate.in");
    ofstream fout("revegetate.out");

    int N, M;
    fin >> N >> M;
    vector<int> adj[N];
    for (int i = 0; i < M; i++) {
        int f, s;
        fin >> f >> s;
        adj[f-1].push_back(s - 1);
        adj[s-1].push_back(f - 1);
    }

    

    return 0;

}
