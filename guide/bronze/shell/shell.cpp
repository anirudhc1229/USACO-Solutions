/*
ID: anirudh71
TASK: shell
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("shell.in");
    ofstream fout("shell.out");

    int N;
    fin >> N;
    int first[N], second[N], guess[N];
    for (int i = 0; i < N; i++) {
        int a, b, g;
        fin >> a >> b >> g;
        first[i] = --a;
        second[i] = --b;
        guess[i] = --g;
    }
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        int pebble = i;
        int correct = 0;
        for (int j = 0; j < N; j++) {
            if (pebble == first[j]) pebble = second [j];
            else if (pebble == second[j]) pebble = first[j];
            if (guess[j] == pebble) correct++;
        }
        ans = max(ans, correct);
    }

    fout << ans << endl;

    return 0;

}
