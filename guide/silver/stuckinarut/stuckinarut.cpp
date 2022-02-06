/*
ID: anirudh71
TASK: stuckinarut
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

struct Cow {
    int x;
    int y;
    bool stopped;
    int id;
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("stuckinarut.in");
    ofstream fout("stuckinarut.out");

    int N; cin >> N;
    vector<Cow> north, east;
    for (int i = 0; i < N; i++) {
        char dir; cin >> dir;
        int x, y; cin >> x >> y;
        if (dir == 'N') north.push_back({x, y, false, i});
        else east.push_back({x, y, false, i});
    }

    sort(north.begin(), north.end(), 
        [](Cow& a, Cow& b) -> bool {return a.x < b.x;});
    sort(east.begin(), east.end(), 
        [](Cow& a, Cow& b) -> bool {return a.y < b.y;});
    vector<int> blames(N);

    for (Cow& n : north) {
        for (Cow& e : east) {
            if (n.stopped || e.stopped) continue;
            if (!(e.x < n.x && n.y < e.y)) continue; // n and e don't intersect
            pii inter = {n.x, e.y};
            if (inter.second - n.y < inter.first - e.x) { // n reaches before e
                e.stopped = true;
                blames[n.id] += blames[e.id] + 1;
            }
            else if (inter.first - e.x < inter.second - n.y) { // e reaches before n
                n.stopped = true;
                blames[e.id] += blames[n.id] + 1;
            }
        }
    }

    for (int b : blames) cout << b << endl;

    return 0;

}
