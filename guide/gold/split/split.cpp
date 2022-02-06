/*
ID: anirudh71
TASK: split
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int getArea(int minX, int maxX, int minY, int maxY) {
    return (maxX - minX) * (maxY - minY);
}

vector<pii> cows;
int N;
int ans;

void sweep() {
    
    sort(cows.begin(), cows.end());
    vector<int> preMin(N), preMax(N);
    preMin[0] = preMax[0] = cows[0].second;
    for (int i = 1; i < N; i++) {
        preMin[i] = min(preMin[i-1], cows[i].second);
        preMax[i] = max(preMax[i-1], cows[i].second);
    } // PREFIXES WORK PERFECT

    int area = getArea(cows[0].first, cows[N-1].first, preMin[N-1], preMax[N-1]); // AREA WORKS PERFECT
    int best = area;

    // THIS PART IS FUCKED
    for (int i = 0; i < N; i++) {
        int lArea, rArea;
        if (i) lArea = getArea(cows[0].first, cows[i-1].first, preMin[i-1], preMax[i-1]);
        else lArea = 0;
        cout << lArea << endl;
        if (i) rArea = getArea(cows[i].first, cows[N-1].first, preMin[N-1] - preMin[i-1], preMax[N-1] - preMax[i-1]);
        else rArea = getArea(cows[i].first, cows[N-1].first, preMin[N-1], preMax[N-1]);
        best = min(best, lArea + rArea);
    }

    ans = max(ans, area - best);

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("split.in");
    ofstream fout("split.out");

    fin >> N;
    cows.resize(N);
    for (pii& c : cows) fin >> c.first >> c.second;
    sweep();
    for (pii& c : cows) swap(c.first, c.second);
    sweep();
    fout << ans << endl;

    return 0;

}
