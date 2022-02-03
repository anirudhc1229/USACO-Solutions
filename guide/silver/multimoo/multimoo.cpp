/*
ID: anirudh71
TASK: multimoo
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int N;
int grid[251][251];
bool visited[251][251];

void dfs1(int i, int j, int c) {
    
    if (i < 0 || i >= N || j < 0 || j >= N) return;
    if (grid[i][j] != c) return;
    if (visited[i][j]) return;

    visited[i][j] = true;
    dfs1(i + 1, j, c);
    dfs1(i - 1, j, c);
    dfs1(i, j + 1, c);
    dfs1(i, j - 1, c);

}

void dfs2(int i, int j, int c1, int c2) {
    
    if (i < 0 || i >= N || j < 0 || j >= N) return;
    if (grid[i][j] != c1 && grid[i][j] != c2) return;
    if (visited[i][j]) return;

    visited[i][j] = true;
    dfs2(i + 1, j, c1, c2);
    dfs2(i - 1, j, c1, c2);
    dfs2(i, j + 1, c1, c2);
    dfs2(i, j - 1, c1, c2);

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("multimoo.in");
    ofstream fout("multimoo.out");

    fin >> N;
    set<int> cows;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fin >> grid[i][j];
            cows.insert(grid[i][j]);
        }
    }

    int one = 0;
    int c1 = 0;
    for (int c : cows) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == c) {
                    for (int k = 0; k < N; k++) 
                        for (int l = 0; l < N; l++) 
                            visited[k][l] = false;
                    dfs1(i, j, c);
                    int sz = 0;
                    for (int k = 0; k < N; k++)
                        for (int l = 0; l < N; l++)
                            if (visited[k][l]) sz++;
                    if (sz > one) {
                        one = sz;
                        c1 = c;
                    }
                }
            }
        }
    }
    fout << one << endl;

    int two = 0;
    for (int c2 : cows) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == c1 || grid[i][j] == c2) {
                    for (int k = 0; k < N; k++) 
                        for (int l = 0; l < N; l++) 
                            visited[k][l] = false;
                    dfs2(i, j, c1, c2);
                    int sz = 0;
                    for (int k = 0; k < N; k++)
                        for (int l = 0; l < N; l++)
                            if (visited[k][l]) sz++;
                    if (sz > two) two = sz;
                }
            }
        }
    }
    fout << two << endl; 
    
    return 0;

}
