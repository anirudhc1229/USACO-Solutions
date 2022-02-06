/*
ID: anirudh71
TASK: lifeguard
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Lifeguard {
    int start;
    int end;
};

int main() {

    ifstream fin("lifeguard.in");
    ofstream fout("lifeguard.out");

    int N;
    fin >> N;
    vector<Lifeguard> lifeguards;
    for (int i = 0; i < N; i++) {
        Lifeguard lg;
        fin >> lg.start >> lg.end;
        lifeguards.push_back(lg);
    }

    vector<int> timeline(1000);
    for (Lifeguard lg : lifeguards) {
        for (int time = lg.start; time < lg.end; time++) {
            timeline[time]++;
        }
    }
    
    int ans = 0;
    
    for (Lifeguard lg : lifeguards) {
        vector<int> hypo(timeline);
        for (int time = lg.start; time < lg.end; time++) {
            hypo[time]--;
        }
        int covered = 0;
        for (int time : hypo) {
            if (time) covered++;
        }
        if (covered > ans) ans = covered;
    }

    fout << ans << endl;

    return 0;

}
