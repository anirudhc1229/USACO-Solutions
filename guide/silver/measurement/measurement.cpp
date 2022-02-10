/*
ID: anirudh71
TASK: measurement
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

struct Entry {
    int day;
    int cow;
    int change;
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("measurement.in");
    ofstream fout("measurement.out");

    int N, G;
    fin >> N >> G;
    vector<Entry> entries(N);
    for (Entry& e : entries)
        fin >> e.day >> e.cow >> e.change;
    sort(entries.begin(), entries.end(), 
        [](Entry a, Entry b) -> bool {return a.day < b.day;});

    map<int, int> counts;
    for (Entry e : entries) counts[e.cow] = G;
    map<int, int, greater<int>> rankings;
    rankings[G] = N; // change if needed
    for (auto c : counts) cout << c.first << " " << c.second << endl; cout << endl;
    for (auto r : rankings) cout << r.first << " " << r.second << endl; cout << endl << endl;

    int ans = 0;
    for (Entry e : entries) {
        bool wasFirst = counts[e.cow] == rankings.begin()->first;
        int prevCount = rankings.begin()->second;
        rankings[counts[e.cow]]--;
        if (!rankings[counts[e.cow]]) rankings.erase(counts[e.cow]);
        counts[e.cow] += e.change;
        rankings[counts[e.cow]]++;
        bool isFirst = counts[e.cow] == rankings.begin()->first;
        int curCount = rankings.begin()->second;
        // Wall will need to be updated if:
            // - Cow was top but is no longer top
            // - Cow wasn't top but now is top
            // - Cow was top but is now even better
        if ((isFirst && !wasFirst) || (wasFirst && !isFirst) || (wasFirst && isFirst && (prevCount != curCount))) ans++;
    }

    fout << ans << endl; 

    return 0;

}
