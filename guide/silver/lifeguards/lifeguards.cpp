/*
ID: anirudh71
TASK: lifeguards
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

struct Event {
    int cow;
    int time;
    bool start;
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("lifeguards.in");
    ofstream fout("lifeguards.out");

    int N; fin >> N;
    vector<Event> events;
    for (int i = 0; i < N; i++) {
        int f, s;
        fin >> f >> s;
        events.push_back({i, f, true});
        events.push_back({i, s, false});
    }

    sort(events.begin(), events.end(), 
        [](Event& a, Event& b) -> bool {return a.time < b.time;});

    set<int> active;
    vector<int> alone(N);
    int prevTime = 0;
    int totalTime = 0;

    for (Event e : events) {

        if (active.size()) totalTime += e.time - prevTime; 

        if (active.size() == 1) alone[*active.begin()] += e.time - prevTime;

        if (e.start) active.insert(e.cow);
        else active.erase(e.cow);

        prevTime = e.time;

    }

    fout << totalTime - *min_element(alone.begin(), alone.end()) << endl;

    return 0;

}
