/*
ID: anirudh71
TASK: div7
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int pre[50001];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("div7.in");
    ofstream fout("div7.out");

    int n; cin >> n;
    int first; cin >> first;
    pre[0] = first % 7;
    for (int i = 1; i < n; i++) {
        int x; cin >> x;
        pre[i] = (pre[i - 1] + x) % 7;
    }

    unordered_map<int, int> seen;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (seen.find(pre[i]) != seen.end())
            ans = max(ans, i - seen[pre[i]]);
        else seen[pre[i]] = i;
    }

    cout << ans << endl;

    return 0;

}