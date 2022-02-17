/*
ID: anirudh71
TASK: convention
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int N, M, C;
vector<int> cows;

bool check(int t) {
    int buses = 1;
    int cur = 0;
    for (int i = 0; i < N; i++) {
        if (cows[i] - cows[cur] > t || i + 1 - cur > C) {
            buses++;
            cur = i;
        }
    }
    return buses <= M;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("convention.in");
    ofstream fout("convention.out");

    fin >> N >> M >> C;
    cows.resize(N);
    for (int& c : cows) fin >> c;
    sort(cows.begin(), cows.end());

    int lo = 0, hi = 1e9;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }

    fout << lo << endl;

    return 0;

}
