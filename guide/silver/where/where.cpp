/*
ID: anirudh71
TASK: where
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int N;
char photo[21][21];
bool visited[21][21];
int i_min, j_min, i_max, j_max;

struct pcl {
    int x1;
    int y1;
    int x2;
    int y2;
};

bool valid(int i, int j) {
    return i >= i_min && i <= i_max && j >= j_min && j < j_max;
}

void dfs(int i, int j, char color) {
    if (!valid(i, j) || photo[i][j] != color || visited[i][j]) return;
    visited[i][j] = true;
    dfs(i + 1, j, color);
    dfs(i - 1, j, color);
    dfs(i, j + 1, color);
    dfs(i, j - 1, color);
}

bool is_pcl(int x1, int y1, int x2, int y2) {
    
    i_min = x1; i_max = y1; j_min = x2; j_max = y2;

    
    for (int color = 0; color < 26; color++) {
        
        for (int i = i_min; i <= i_max; i++)
            for (int j = j_min; j <= j_max; j++)
                visited[i][j] = false;
        
        for (int i = i_min; i <= i_max; i++)
            for (int j = j_min; j <= j_max; j++)
                if (!visited[i][j]) dfs(i, j, (char)(color + 65));
        
        for (int i = i_min; i <= i_max; i++)
            for (int j = j_min; j <= j_max; j++)

    
    }

    // valid pcl needs
        // exactly 2 colors
        // 

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("where.in");
    ofstream fout("where.out");

    fin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            fin >> photo[i][j];

    vector<pcl> pcls;
    for (int x1 = 1; x1 < N; x1++)
        for (int y1 = 1; y1 < N; y1++)
            for (int x2 = x1 + 1; x2 < N; x2++)
                for (int y2 = y1 + 1; y2 < N; y2++)
                    if (is_pcl(x1, y1, x2, y2))
                        pcls.push_back({x1, y1, x2, y2});

    for (pcl a : pcls)
        for (pcl b : pcls)
            

    return 0;

}
