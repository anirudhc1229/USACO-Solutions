/*
ID: anirudh71
TASK: socdist1
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

ll N, M;
vector<pii> patches;

bool check(ll D) {
    ll cows = 0;
    ll pos = patches[0].first;
    ll patch = 0;
    while (pos < patches[M-1].second) {
        cows++;
        if (patch == M - 1 || pos + D <= patches[patch+1].first) pos += D;
        else pos = patches[++patch].first;
    }
    return cows >= N;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("socdist1.in");
    ofstream fout("socdist1.out");

    fin >> N >> M;
    patches.resize(M);
    for (pii& p : patches) fin >> p.first >> p.second;
    sort(patches.begin(), patches.end());

    ll lo = 1, hi = 1e18;
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        cout << mid << " ";
        if (check(mid)) lo = mid;
        else hi = mid - 1;
    }

    fout << lo << endl;

    return 0;

}
