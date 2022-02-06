/*
ID: anirudh71
TASK: diamond
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

    ifstream fin("diamond.in");
    ofstream fout("diamond.out");

    int N, K;
    fin >> N >> K;
    int diamonds[N];
    for (int i = 0; i < N; i++) fin >> diamonds[i];
    sort(diamonds, diamonds + N);

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int good = 1;
        for (int j = i + 1; j < N; j++) {
            if (diamonds[j] - diamonds[i] <= K) good++;
        }
        ans = max(ans, good);
    }

    fout << ans << endl;

    return 0;

}
