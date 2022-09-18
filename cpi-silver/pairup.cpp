/*
ID: anirudh71
TASK: pairup
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<pii> cows;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("pairup.in");
    ofstream fout("pairup.out");

    cin >> n;
    cows.resize(n);
    for (pii& c : cows) cin >> c.second >> c.first;
    sort(cows.begin(), cows.end());

    int ans = 0;
    int l = 0, r = n - 1;
    while (l < r) {
        ans = max(ans, cows[l].first + cows[r].first);
        int used = min(cows[l].second, cows[r].second);
        cows[l].second -= used;
        cows[r].second -= used;
        if (!cows[l].second) l++;
        if (!cows[r].second) r--;
    }

    cout << ans << endl;

    return 0;

}