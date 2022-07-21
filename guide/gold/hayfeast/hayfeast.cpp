/*
ID: anirudh71
TASK: hayfeast
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

ll n, m;
ll flavor[100001];
ll spice[100001];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("hayfeast.in");
    ofstream fout("hayfeast.out");

    fin >> n >> m;
    for (ll i = 0; i < n; i++)
        fin >> flavor[i] >> spice[i];
    ll cur_flavor = flavor[0];
    multiset<ll> spice_set;
    spice_set.insert(spice[0]);
    ll l = 0, r = 0;
    ll ans = LONG_LONG_MAX;

    while (r < n) {
        if (cur_flavor >= m) {
            ans = min(ans, *spice_set.rbegin());
            if (l != r) {
                cur_flavor -= spice[l];
                spice_set.erase(spice_set.find(spice[l]));
                l++;
            }
        } else {
            r++;
            cur_flavor += spice[r];
            spice_set.insert(spice[r]);
        }
    }

    fout << ans << endl;

    return 0;

}