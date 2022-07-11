/*
ID: anirudh71
TASK: lifeguards
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
#include <unordered_set>

struct event {
    int cow;
    int time;
    bool start;
    bool operator<(event e) {
        return time < e.time;
    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("lifeguards.in");
    ofstream fout("lifeguards.out");

    int n; cin >> n;
    vector<event> events;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        events.push_back({i, a, true});
        events.push_back({i, b, false});
    }

    sort(events.begin(), events.end());
    // for (event e : events) cout << e.cow << " " << e.time << " " << e.start << endl;
    unordered_set<int> active;
    vector<int> alone(n);
    int total = 0;
    int prev = 0;
    for (event e : events) {
        if (active.size()) total += e.time - prev;
        if (active.size() == 1) alone[*active.begin()] += e.time - prev;
        prev = e.time;
        if (e.start) active.insert(e.cow);
        else active.erase(e.cow);
    }

    cout << total - *min_element(alone.begin(), alone.end()) << endl;

    return 0;

}