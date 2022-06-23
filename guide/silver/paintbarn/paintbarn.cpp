/*
ID: anirudh71
TASK: paintbarn
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
    ifstream fin("paintbarn.in");
    ofstream fout("paintbarn.out");

    int N, K;
    fin >> N >> K;
    const int LEN = 1001;
    vector<vector<int>> prefix(LEN, vector<int>(LEN));
    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        fin >> x1 >> y1 >> x2 >> y2;
        prefix[x2][y2]++;
        prefix[x1][y2]--;
        prefix[x2][y1]--;
        prefix[x1][y1]++;
    }

    int ans = 0;
    for (int i = 0; i < LEN; i++) {
        for (int j = 0; j < LEN; j++) {
            if (i) prefix[i][j] += prefix[i-1][j];
            if (j) prefix[i][j] += prefix[i][j-1];
            if (i && j) prefix[i][j] -= prefix[i-1][j-1];
            if (prefix[i][j] == K) ans++;
        }
    }

    fout << ans << endl;

    return 0;

}
