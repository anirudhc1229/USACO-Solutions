/*
ID: anirudh71
TASK: rental
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<ll, ll> pii;

ll N, M, R;
vector<ll> cows;
vector<pii> stores;
vector<ll> farms;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("rental.in");
    ofstream fout("rental.out");

    cin >> N >> M >> R;
    cows.resize(N); 
    for (ll& c : cows) cin >> c;
    stores.resize(M); 
    for (pii& s : stores) cin >> s.second >> s.first;
    farms.resize(R);
    for (ll& f : farms) cin >> f;

    sort(cows.begin(), cows.end(), greater<ll>());
    sort(stores.begin(), stores.end(), greater<pii>());
    sort(farms.begin(), farms.end(), greater<ll>());

    vector<ll> cowpfx(N);
    cowpfx[0] = cows[0];
    for (ll i = 1; i < N; i++)
        cowpfx[i] = cowpfx[i - 1] + cows[i];
    vector<ll> storepfx(M);
    storepfx[0] = stores[0].first * stores[0].second;
    for (ll i = 1; i < M; i++)
        storepfx[i] = storepfx[i - 1] + stores[i].first * stores[i].second;
    vector<ll> farmpfx(R);
    farmpfx[0] = farms[0];
    for (ll i = 1; i < R; i++)
        farmpfx[i] = farmpfx[i - 1] + farms[i];

    ll ans = farmpfx[min(N - 1, R - 1)];
    ll cur = -1;
    ll store_milk = 0;
    for (ll split = 0; split < N; split++) { // split point for cows to stores vs farms

        ll store_profit = 0;
        ll cow_milk = cowpfx[split];
        while (cur < M - 1 && store_milk < cow_milk)
            store_milk += stores[++cur].second;
        if (store_milk > cow_milk) {
            store_profit = cur == 0 ? 0 : storepfx[cur - 1];
            store_profit += (cow_milk - (store_milk - stores[cur].second)) * stores[cur].first;
        } else {
            store_profit = storepfx[cur];
        }

        ll farm_cows = N - split - 2;
        ll farm_profit = farm_cows == -1 ? 0 : farmpfx[min(R - 1, farm_cows)];

        ans = max(ans, store_profit + farm_profit);
    
    }

    cout << ans << endl;

    return 0;

}