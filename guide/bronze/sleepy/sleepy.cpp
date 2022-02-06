/*
ID: anirudh71
TASK: sleepy
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("sleepy.in");
    ofstream fout("sleepy.out");

    int N;
    fin >> N;
    vector<int> cows(N);
    for (int i = 0; i < N; i++) fin >> cows[i];

    int ans = N - 1;
    for (int i = N - 2; i >= 0; i--) {
        if (cows[i] < cows[i+1]) ans = i;
        else break;
    }

    fout << ans << endl;

    return 0;

}
