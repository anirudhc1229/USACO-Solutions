/*
ID: anirudh71
TASK: 2
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int N;
vector<pii> steps;
pii goal;
vector<int> ks;
vector<int> used;

vector<vector<pii>> getSubsets(vector<pii>& set) {
  
    vector<vector<pii>> sub;

    if (set.empty()) {
        sub.push_back(set);
        return sub;
    }

    if (set.size() == 1) {
        vector<pii> empty;
        sub.push_back(empty);
        sub.push_back(set);
        return sub;
    }

    vector<pii> splice;
    for (int i = 0;i < (set.size()-1); i++)
        splice.push_back(set[i]);
    vector<vector<pii>> subSplice = getSubsets(splice);
    for (int i = 0; i < subSplice.size(); i++) 
        sub.push_back(subSplice[i]);
    for (int i = 0; i < subSplice.size(); i++) 
        subSplice[i].push_back(set[set.size()-1]);
    for (int i = 0; i < subSplice.size(); i++) 
        sub.push_back(subSplice[i]);

    return sub;

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("2.in");
    ofstream fout("2.out");

    cin >> N;
    steps.resize(N);
    ks.resize(N);
    used.resize(N);
    cin >> goal.first >> goal.second;
    for (pii& s : steps) cin >> s.first >> s.second;

    vector<vector<pii>> subs = getSubsets(steps);
    for (vector<pii> s : subs) {
        int x = 0, y = 0;
        for (pii pt : s) {
            x += pt.first;
            y += pt.second;
        }
        if (x == goal.first && y == goal.second)
            ks[s.size()-1]++;
    }

    for (int ans : ks) cout << ans << endl;

    return 0;

}
