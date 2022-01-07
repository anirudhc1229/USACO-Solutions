/*
ID: anirudh71
TASK: lonely
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("lonely.in");
    ofstream fout("lonely.out");

    int N;
    fin >> N;
    string cows;
    fin >> cows;

    int gSum[N];
    int hSum[N];
    gSum[0] = cows[0] == 'G';
    hSum[0] = cows[0] == 'H';
    for (int i = 1; i < N; i++) {
        gSum[i] = gSum[i-1] + (cows[i] == 'G');
        hSum[i] = hSum[i-1] + (cows[i] == 'H');
    }

    int ans = 0;

    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 2; j < N; j++) {
            if (i == 0) {
                if (gSum[j] == 1 || hSum[j] == 1) {
                    ans++;
                }
            } else {
                if ((gSum[j] - gSum[i-1] == 1) || (hSum[j] - hSum[i-1] == 1)) {
                    ans++;
                }
            }
        }
    }

    fout << ans << endl;

    return 0;

}
