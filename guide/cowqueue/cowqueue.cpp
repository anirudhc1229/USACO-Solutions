/*
ID: anirudh71
TASK: cowqueue
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Cow {
    int start;
    int time;
};

int main() {

    ifstream fin("cowqueue.in");
    ofstream fout("cowqueue.out");

    int N;
    fin >> N;
    vector<Cow> cows;
    for (int i = 0; i < N; i++) {
        Cow c;
        fin >> c.start >> c.time;
        cows.push_back(c);
    }

    sort(cows.begin(), cows.end(), [](Cow a, Cow b) {
        return a.start < b.start;
	});

    for (int i = 1; i < N; i++) {
        cows[i].start = max(cows[i].start, cows[i-1].start + cows[i-1].time);
    }

    int ans = cows[N-1].start + cows[N-1].time;

    fout << ans << endl;

    return 0;

}
