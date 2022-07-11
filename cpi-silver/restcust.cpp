/*
ID: anirudh71
TASK: restcust
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
    ifstream fin("restcust.in");
    ofstream fout("restcust.out");

    ll n; cin >> n;
    unordered_map<ll, ll> times;
    ll max_time = 0;
    for (ll i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        times[a]++;
        times[b]--;
        max_time = max(max_time, b);
    }

    ll mx = 0;
    ll cur = 0;
    for (ll i = 1; i <= max_time; i++) {
        cur += times[i];
        mx = max(mx, cur);
    }
    
    cout << mx << endl;

    return 0;

}