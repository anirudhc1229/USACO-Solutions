/*
ID: anirudh71
TASK: gymnastics
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("gymnastics.in");
    ofstream fout("gymnastics.out");

    int K, N;
    fin >> K >> N;
    int performance[K][N];
    for (int day = 0; day < K; day++) {
        for (int cow = 0; cow < N; cow++) {
            fin >> performance[day][cow];
        }
    }

    int ans = 0;

    for (int a = 0; a < N; a++) {
        for (int b = 0; b < N; b++) {
            for (int day = 0; day < K; day++) {
                if (performance[day][a] < performance[day][b]) goto br;
            }
            ans++;
        }
        br: continue;
    }

    fout << ans << endl;

    return 0;

}
