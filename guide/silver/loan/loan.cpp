/*
ID: anirudh71
TASK: loan
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

ll N, K, M;

bool check(ll left, ll days, ll x) {
    return true;
    int y = left / x;
    if (y * days < left) return false;
    if (days <= 0) return left <= 0;
    int givey = (left - x) / y + 1;
    return check(left - y * givey, days - givey, x);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("loan.in");
    ofstream fout("loan.out");

    fin >> N >> K >> M;

    ll lo = 1, hi = N;
    cout << N;
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (check(N, K, mid)) lo = mid;
        else hi = mid - 1;
    }

    fout << lo << endl;

    return 0;

}
