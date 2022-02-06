/*
ID: anirudh71
TASK: breedflip
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("breedflip.in");
    ofstream fout("breedflip.out");

    int N;
    fin >> N;
    string from, to;
    fin >> from >> to;

    int ans = 0;

    for (int i = 0; i < N; i++) {
        if (from[i] != to[i]) {
            ans++;
            int j = i + 1;
            while (from[j] != to[j]) j++;
            for (int c = i; c < j; c++) from[c] = to[c];
        }
    }

    fout << ans << endl;

    return 0;

}
