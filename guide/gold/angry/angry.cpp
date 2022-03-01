/*
ID: anirudh71
TASK: angry
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int N; 
vector<int> bales;

bool check(int R) {
    // binary search on location of first cow
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("angry.in");
    ofstream fout("angry.out");

    fin >> N;
    bales.resize(N);
    for (int& b : bales) fin >> b;

    int lo = 1, hi = 1e9;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }

    return 0;

}
