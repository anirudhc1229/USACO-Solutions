/*
ID: anirudh71
TASK: planting
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int deg[100001];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("planting.in");
    ofstream fout("planting.out");

    int n; cin >> n;
    for (int i = 0; i < n; i++) deg[i] = 0;
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        deg[a]++;
        deg[b]++;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, deg[i]);
    cout << ++ans << endl;

    return 0;

}