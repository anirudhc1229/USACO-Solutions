/*
ID: anirudh71
TASK: rental
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("rental.in");
    ofstream fout("rental.out");

    int N, M, R;
    fin >> N >> M >> R;
    vector<int> cows(N);
    for (int i = 0; i < N; i++) fin >> cows[i];
    vector<pair<int, int>> orders(M);
    for (int i = 0; i < M; i++) fin >> orders[i].first >> orders[i].second;
    vector<int> rentals(R);
    for (int i = 0; i < R; i++) fin >> rentals[i];

    sort(cows.begin(), cows.end(), greater<int>());
    sort(orders.begin(), orders.end(), 
        [](auto& a, auto&b) -> bool {return a.second > b.second;});
    sort(rentals.begin(), rentals.end(), greater<int>());

    for (int c : cows) cout << c << " "; cout << endl;
    for (auto o : orders) cout << o.first << " " << o.second << endl;
    for (int r : rentals) cout << r << " "; cout << endl;

    int ans = 0;
    for (int i = 0; i < N; i++) { // breakpoint of using orders vs using rentals
        int money = 0;
        // use cows [0, i) for orders
        int orderi = 0;
        for (int j = 0; j < i; j++) {
            orders[orderi].first -= min(orders[orderi].first, cows[i]);
            money += orders[orderi].second * min(orders[orderi].first, cows[i]);
            if (!orders[orderi].first) orderi++;
        }
        // use cows [i, N) for rentals
        // USE PREFIX FOR THIS IF NEEDED
        int renti = 0;
        for (int j = i; j < N; j++) {
            money += rentals[renti];
            renti++;
        }
        ans = max(ans, money);
    }

    fout << ans << endl;

    return 0;

}
