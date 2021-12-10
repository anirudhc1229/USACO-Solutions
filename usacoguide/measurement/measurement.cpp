/*
ID: anirudh71
TASK: measurement
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Entry {
    int day;
    string name;
    int change;
};

int main() {

    ifstream fin("measurement.in");
    ofstream fout("measurement.out");

    int N;
    fin >> N;
    vector<Entry> entries;
    for (int i = 0; i < N; i++) {
        Entry e;
        fin >> e.day >> e.name >> e.change;
        entries.push_back(e);
    }

    int ans = 0;
    
    map<string, int> rates;
    rates["Bessie"] = 7;
    rates["Elsie"] = 7;
    rates["Mildred"] = 7;

    vector<string> best{"Bessie", "Elsie", "Mildred"};

    for (int i = 1; i <= 100; i++) {
        for (Entry e : entries) {
            if (e.day == i) {
                rates[e.name] += e.change;
            }
        }
        vector<string> newBest;
        int bestRate = 0;
        for (auto const& r : rates) {
            if (r.second > bestRate) {
                bestRate = r.second;
                newBest.clear();
                newBest.push_back(r.first);
            } else if (r.second == bestRate) {
                newBest.push_back(r.first);
            }
        }
        if (newBest != best) {
            ans++;
        }
        best = newBest;
    }

    fout << ans << endl;

    return 0;

}
