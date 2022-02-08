/*
ID: anirudh71
TASK: diamond
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
    ifstream fin("diamond.in");
    ofstream fout("diamond.out");

    int N, K;
    fin >> N >> K;
    int diamonds[N];
    for (int i = 0; i < N; i++) fin >> diamonds[i];
    sort(diamonds, diamonds + N);
    
    int sizes[N];
    for (int i = 0; i < N; i++) sizes[i] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (diamonds[j] - diamonds[i] <= K) sizes[i]++;
            else break;
        }
    }

    int maxAfter[N];
    for (int i = 0; i < N; i++) {
        maxAfter[i] = 0;
        for (int j = i + sizes[i]; j < N; j++)
            maxAfter[i] = max(maxAfter[i], sizes[j]);
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
        ans = max(ans, sizes[i] + maxAfter[i]);

    fout << ans << endl;

    return 0;

}
