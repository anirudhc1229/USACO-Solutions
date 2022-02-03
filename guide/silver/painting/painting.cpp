/*
ID: anirudh71
TASK: painting
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int prefix[1001][1001];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("painting.in");
    ofstream fout("painting.out");

    int N, K;
    fin >> N >> K;
    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        fin >> x1 >> y1 >> x2 >> y2;
        prefix[x2][y2]++;
        prefix[x2][y1]--;
        prefix[x1][y2]--;
        prefix[x1][y1]++;
    }

    int ans = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if (i) prefix[i][j] += prefix[i-1][j];
            if (j) prefix[i][j] += prefix[i][j-1];
            if (i && j) prefix[i][j] -= prefix[i-1][j-1];
            if (prefix[i][j] == K) ans++;
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << prefix[i][j] << " ";
        }
        cout << endl;
    }

    fout << ans << endl;

    return 0;

}
