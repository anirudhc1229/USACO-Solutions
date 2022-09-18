/*
ID: anirudh71
TASK: perimeter
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int N;
bool ice[1001][1001];
bool visited[1001][1001];
int a;
int p;

bool valid(int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < N;
}

int surrounding(int i, int j) {
    int s = 0;
    if (valid(i + 1, j) && ice[i+1][j]) s++;
    if (valid(i - 1, j) && ice[i-1][j]) s++;
    if (valid(i, j + 1) && ice[i][j+1]) s++;
    if (valid(i, j - 1) && ice[i][j-1]) s++;
    return s;
}

void dfs(int i, int j) {
    if (!valid(i, j) || !ice[i][j]) return;
    if (visited[i][j]) return;
    visited[i][j] = true;
    a++;
    p += 4 - surrounding(i, j);
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("perimeter.in");
    ofstream fout("perimeter.out");

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c; cin >> c;
            ice[i][j] = c == '#';
        }
    }

    int best_a = 0, best_p = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (ice[i][j] && !visited[i][j]) {
                a = 0; p = 0;
                dfs(i, j);
                if (a == best_a) {
                    best_p = min(best_p, p);
                } else if (a > best_a) {
                    best_a = a;
                    best_p = p;
                }
            }
        }
    }
    
    cout << best_a << " " << best_p << endl;

    return 0;

}
