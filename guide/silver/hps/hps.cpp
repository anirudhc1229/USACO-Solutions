/*
ID: anirudh71
TASK: hps
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("hps.in");
    ofstream fout("hps.out");

    int N; fin >> N;
    char fj[N];
    for (int i = 0; i < N; i++) fin >> fj[i];
    
    int h[N], p[N], s[N];
    h[0] = (fj[0] == 'S');
    p[0] = (fj[0] == 'H');
    s[0] = (fj[0] == 'P');
    for (int i = 1; i < N; i++) {
        h[i] = h[i-1] + (fj[i] == 'S');
        p[i] = p[i-1] + (fj[i] == 'H');
        s[i] = s[i-1] + (fj[i] == 'P');
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, h[i] + p[N-1] - p[i]);
        ans = max(ans, h[i] + s[N-1] - s[i]);
        ans = max(ans, p[i] + h[N-1] - h[i]);
        ans = max(ans, p[i] + s[N-1] - s[i]);
        ans = max(ans, s[i] + h[N-1] - h[i]);
        ans = max(ans, s[i] + p[N-1] - p[i]);
    }

    fout << ans << endl;

    return 0;

}
