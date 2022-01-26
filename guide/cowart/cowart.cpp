/*
ID: anirudh71
TASK: cowart
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
char painting[101][101];
bool visited[101][101];
vector<pair<int, int>> adj = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

pair<int, int> getStart() {
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (!visited[i][j])
                return make_pair(i, j);
    
    return make_pair(-1, -1);

}

void expand(pair<int, int> cur) {
    
    visited[cur.first][cur.second] = true;
    
    for (pair<int, int> x : adj) {
        pair<int, int> next = {cur.first + x.first, cur.second + x.second};
        if (next.first < 0 || next.first >= N || next.second < 0 || next.second >= N) continue;
        if (visited[next.first][next.second]) continue;
        if (painting[cur.first][cur.second] != painting[next.first][next.second]) continue;
        expand(next);
    }
}

int main() {

    ifstream fin("cowart.in");
    ofstream fout("cowart.out");

    fin >> N;
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            fin >> painting[i][j];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            visited[i][j] = false;

    int human = 0;
    pair<int, int> start = getStart();
    while (start != make_pair(-1, -1)) {
        human++;
        expand(start);
        start = getStart();
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (painting[i][j] == 'G')
                painting[i][j] = 'R';
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            visited[i][j] = false;

    int cow = 0;
    start = getStart();
    while (start != make_pair(-1, -1)) {
        cow++;
        expand(start);
        start = getStart();
    }

    fout << human << " " << cow << endl;

    return 0;

}
