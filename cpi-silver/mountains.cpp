/*
ID: anirudh71
TASK: mountains
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
#include <unordered_set>

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("mountains.in");
    ofstream fout("mountains.out");

    int n; cin >> n;
    vector<pii> points(n);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        points[i] = {a - b, a + b};
    }

    sort(points.begin(), points.end(), [](pii a, pii b) -> bool {
        return a.first == b.first ? a.second > b.second : a.first < b.first;
    });

    int max_end = -1;
    int ans = 0;
    for (pii p : points) {
        if (p.second > max_end) {
            max_end = p.second;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;

}