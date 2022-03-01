/*
ID: anirudh71
TASK: stacking
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
    ifstream fin("stacking.in");
    ofstream fout("stacking.out");

    int N, K; 
    fin >> N >> K;
    int diff[100001];
    for (int i = 0; i < K; i++) {
        int a, b;
        fin >> a >> b;
        diff[--a]++;
        diff[b]--;
    }

    int orig[100001];
    orig[0] = diff[0];
    for (int i = 1; i < N; i++)
        orig[i] = orig[i-1] + diff[i];
    
    sort(orig, orig + N);
    for (int i = 0; i < N; i++) cout << orig[i];
    fout << orig[N/2] << endl;

    return 0;

}
