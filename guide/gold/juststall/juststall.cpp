/*
ID: anirudh71
TASK: juststall
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

ll n;
ll cows[21];
ll stalls[21];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("juststall.in");
    ofstream fout("juststall.out");

    cin >> n;
    for (ll i = 0; i < n; i++) cin >> cows[i];
    for (ll i = 0; i < n; i++) cin >> stalls[i];

    sort(cows, cows + n);
    sort(stalls, stalls + n);

    ll ans = 1;
    for (ll i = n - 1; i >= 0; i--) {
        ll j = i;
        while (j >= 0 && cows[i] <= stalls[j]) j--;
        ans *= i - j;
    }

    cout << ans << endl;

    return 0;

}