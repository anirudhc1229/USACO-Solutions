/*
ID: anirudh71
TASK: helpcross
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("helpcross.in");
    ofstream fout("helpcross.out");

    int C, N;
    fin >> C >> N;
    vector<int> chickens(C);
    for (int& ch : chickens) fin >> ch;
    vector<pii> cows(N);
    for (pii& cow : cows) fin >> cow.first >> cow.second;
    sort(chickens.begin(), chickens.end());
    sort(cows.begin(), cows.end(), [](pii& a, pii& b) -> bool {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });

    int ans = 0;
    vector<bool> used(C);
    for (pii cow : cows) {
        for (int i = 0; i < C; i++) {
            if (used[i]) continue;
            if (cow.first <= chickens[i] && chickens[i] <= cow.second) {
                ans++;
                used[i] = true;
                break;
            }
        }
    }

    fout << ans << endl;

    return 0;

}
