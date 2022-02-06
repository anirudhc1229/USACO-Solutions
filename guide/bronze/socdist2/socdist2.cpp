/*
ID: anirudh71
TASK: socdist2
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Cow {
    int pos;
    bool sick;
};

int main() {

    ifstream fin("socdist2.in");
    ofstream fout("socdist2.out");

    int N;
    fin >> N;
    vector<Cow> cows(N);
    for (int i = 0; i < N; i++) {
        Cow c;
        fin >> c.pos >> c.sick;
        cows[i] = c;
    }

    sort(cows.begin(), cows.end(), 
        [](Cow& a, Cow&b) -> bool {return a.pos < b.pos;});

    // find the shortest distance between a healthy cow and a sick cow
        // R < this value
    int radius = 1000000;
    for (int i = 0; i < N; i++) {
        if (cows[i].sick) continue;
        if (i > 0) radius = min(radius, cows[i].pos - cows[i-1].pos - 1);
        if (i < N - 1) radius = min(radius, cows[i+1].pos - cows[i].pos - 1);
    }

    // count groups of cows with distance less than R between all of them
    int ans = 1;
    for (int i = 0; i < N - 1; i++) {
        if (!cows[i].sick || !cows[i+1].sick) continue;
        if (cows[i+1].pos - cows[i].pos > radius) ans++;
    }

    fout << ans << endl;

    return 0;

}
