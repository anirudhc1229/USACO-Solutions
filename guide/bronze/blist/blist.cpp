/*
ID: anirudh71
TASK: blist
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("blist.in");
    ofstream fout("blist.out");

    int N;
    fin >> N;
    vector<pair<pair<int, int>, bool>> timeline;
    for (int i = 0; i < N; i++) {
        int s, e, b;
        fin >> s >> e >> b;
        timeline.push_back({{s, b}, true});
        timeline.push_back({{e, b}, false});
    }

    sort(timeline.begin(), timeline.end(),
        [](auto& a, auto& b) -> bool {return a.first.first < b.first.first;});
    vector<int> used;
    int cur = 0;
    for (int i = 0; i < timeline.size(); i++) {
        if (timeline[i].second) {
            cur += timeline[i].first.second;
            used.push_back(cur);
        } else {
            cur -= timeline[i].first.second;
            used.push_back(cur);
        }
    }

    fout << *max_element(used.begin(), used.end()) << endl;

    return 0;

}
