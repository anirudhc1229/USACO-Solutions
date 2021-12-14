/*
ID: anirudh71
TASK: factory
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {

    ifstream fin("factory.in");
    ofstream fout("factory.out");

    int N;
    fin >> N;
    
    vector<int> adj;
    for (int i = 0; i < N; i++) adj.push_back(0);

    for (int i = 0; i < N - 1; i++) {
        int cur, next;
        fin >> cur >> next;
        adj[cur-1]++;
    }

    int ans;
    vector<int> possible;

    for (int i = 0; i < N; i++) if (!adj[i]) possible.push_back(i);

    if (possible.size() != 1) ans = -1;
    else ans = possible[0] + 1;

    fout << ans << endl;

    return 0;

}
