/*
ID: anirudh71
TASK: convention2
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

struct Cow {
    int id;
    int arrive;
    int len;
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("convention2.in");
    ofstream fout("convention2.out");

    int N; fin >> N;
    vector<Cow> cows(N);
    for (int i = 0; i < N; i++) {
        cows[i].id = i;
        fin >> cows[i].arrive >> cows[i].len;
    }
    
    sort(cows.begin(), cows.end(), 
        [](Cow& a, Cow& b) -> bool {return a.arrive < b.arrive;});

    // simulate times
    // if no cows in priority queue, simply take next cow from vector
    // else, pop cow from priority queue
    int time = 0;
    priority_queue<Cow> waiting;
    for (Cow c : cows) {
        if (waiting.empty())
    }

    return 0;

}
