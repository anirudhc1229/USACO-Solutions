/*
ID: anirudh71
TASK: cbarn
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("cbarn.in");
    ofstream fout("cbarn.out");

    int N;
    fin >> N;
    vector<int> rooms(N);
    for (int i = 0; i < N; i++) fin >> rooms[i];

    int ans = 1000000000;

    for (int i = 0; i < N; i++) {
        int dist = 0;
        for (int j = i; j < N + i; j++)
            dist += rooms[j % N] * (j - i);
        ans = min(ans, dist);
        cout << dist << endl;
    }

    fout << ans << endl;

    return 0;

}
