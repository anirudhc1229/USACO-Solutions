/*
ID: anirudh71
TASK: hoofball
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("hoofball.in");
    ofstream fout("hoofball.out");

    int N;
    fin >> N;
    vector<int> cows(N);
    for (int i = 0; i < N; i++) fin >> cows[i];
    sort(cows.begin(), cows.end());

    vector<int> next(N);
    for (int i = 0; i < N; i++) {
        if (i == 0) next[i] = i + 1;
        else if (i == N-1) next[i] = i - 1;
        else {
            if ((cows[i] - cows[i-1]) <= (cows[i+1] - cows[i])) next[i] = i - 1;
            else next[i] = i + 1;
        }
    }

    vector<int> popularity(N);
    for (int i = 0; i < N; i++) popularity[i] = 0;
    for (int i = 0; i < N; i++) popularity[next[i]]++;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (popularity[i] == 0) ans++;
        if (next[i] == i + 1 && next[i+1] == i && popularity[i] == 1 && popularity[i+1] == 1) ans++;
    }

    fout << ans << endl;

    return 0;

}
