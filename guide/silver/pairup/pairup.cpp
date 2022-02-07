/*
ID: anirudh71
TASK: pairup
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("pairup.in");
    ofstream fout("pairup.out");

    int N; fin >> N;
    vector<pii> cows;
    for (int i = 0; i < N; i++) {
        int x, y; fin >> x >> y;
        cows.push_back({y, x});
    }
    sort(cows.begin(), cows.end());

    int ans = 0; // max sum of any two on opp sides
    int left = 0;
    int right = cows.size() - 1;

    while (left < right) {
        ans = max(ans, cows[left].first + cows[right].first);
        int cancel = min(cows[left].second, cows[right].second);
        cows[left].second -= cancel;
        cows[right].second -= cancel;
        if (!cows[left].second) left++;
        if (!cows[right].second) right--;
    }

    fout << ans << endl;

    return 0;

}
