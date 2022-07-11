/*
ID: anirudh71
TASK: split
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<ll, ll> pii;

ll n;
vector<pii> cows;

ll sweep() {

    sort(cows.begin(), cows.end());
    vector<ll> premin(n), sufmin(n), premax(n), sufmax(n);
    premin[0] = premax[0] = cows[0].second;
    for (ll i = 1; i < n; i++) {
        premin[i] = min(premin[i - 1], cows[i].second);
        premax[i] = max(premax[i - 1], cows[i].second);
    }
    sufmin[n - 1] = sufmax[n - 1] = cows[n - 1].second;
    for (ll i = n - 2; i >= 0; i--) {
        sufmin[i] = min(sufmin[i + 1], cows[i].second);
        sufmax[i] = max(sufmax[i + 1], cows[i].second);
    }

    // area = (xmax - xmin) * (ymax - ymin)
    ll total = (cows[n - 1].first - cows[0].first) * (premax[n - 1] - premin[n - 1]);
    ll minarea = total;
    for (ll split = 0; split < n - 1; split++) {
        ll larea = (cows[split].first - cows[0].first) * (premax[split] - premin[split]);
        ll rarea = (cows[n - 1].first - cows[split + 1].first) * (sufmax[split + 1] - sufmin[split + 1]);
        minarea = min(minarea, larea + rarea);
    }

    return total - minarea;

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("split.in");
    ofstream fout("split.out");

    cin >> n;
    cows.resize(n);
    for (pii& c : cows)
        cin >> c.first >> c.second;

    ll xmax = sweep();
    for (pii& c : cows) 
        swap(c.first, c.second);
    ll ymax = sweep();
    cout << max(xmax, ymax) << endl;

    return 0;

}