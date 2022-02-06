/*
ID: anirudh71
TASK: lazy
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int grid[801][801];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("lazy.in");
    ofstream fout("lazy.out");

    int N, K;
    fin >> N >> K;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            fin >> grid[i+j][N-i+j-1];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

}
