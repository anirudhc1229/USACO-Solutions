/*
ID: anirudh71
TASK: haybales
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int N, Q;
vector<int> bales;

int bs(int x) {
    int lo = 0, hi = N;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (bales[mid] > x) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("haybales.in");
    ofstream fout("haybales.out");

    fin >> N >> Q;
    bales.resize(N);
    for (int& b : bales) fin >> b;
    sort(bales.begin(), bales.end());

    for (int i = 0; i < Q; i++) {
        int f, s;
        fin >> f >> s;
        fout << bs(s) - bs(f - 1) << endl;
    }

    return 0;

}
