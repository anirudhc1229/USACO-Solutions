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

int N, K;
vector<int> bales;

bool check(int R) {
    int start = 0;
    for (int i = 0; i < K; i++) {
        int cowPos = bales[start] + R;
        int end = cowPos + R;
        while (bales[start] <= end && start < N) start++;
    }
    return start == N;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("angry.in");
    ofstream fout("angry.out");

    fin >> N >> K;
    bales.resize(N);
    for (int& c : bales) fin >> c;
    sort(bales.begin(), bales.end());

    int lo = 1, hi = N;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) hi = mid; 
        else lo = mid + 1;
    }

    fout << lo << endl;

    return 0;

}
