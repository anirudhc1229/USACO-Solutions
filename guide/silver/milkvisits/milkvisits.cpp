/*
ID: anirudh71
TASK: milkvisits
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int N, M;
string breeds;
vector<int> adj[1000001];
bool visited[1000001];
vector<int> st;
bool inPath[1000001];

void dfs(int cur, int end) {
    st.push_back(cur);
    // for (int i : st) cout << i << " "; cout << endl;
    if (cur == end) {
        for (int i : st) inPath[i] = true;
        return;
    }
    visited[cur] = true;
    for (int a : adj[cur]) {
        if (visited[a]) continue;
        dfs(a, end);
    }
    st.pop_back();
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("milkvisits.in");
    ofstream fout("milkvisits.out");

    fin >> N >> M;
    fin >> breeds;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        fin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    for (int i = 0; i < M; i++) {
        int a, b; char c;
        fin >> a >> b >> c;
        a--; b--;
        fill(visited, visited + N, false);
        fill(inPath, inPath + N, false);
        st.clear();
        dfs(a, b);
        bool happy = false;
        for (int j = 0; j < N; j++)
            if (inPath[j] && breeds[j] == c)
                happy = true;
        fout << happy;
    }

    return 0;

}
