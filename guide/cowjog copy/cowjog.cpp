/*
ID: anirudh71
TASK: cowjog
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

    ifstream fin("cowjog.in");
    ofstream fout("cowjog.out");

    int N, T;
    fin >> N >> T;
    int pos[N];
    int speed[N];
    for (int i = 0; i < N; i++)
        fin >> pos[i] >> speed[i];

    int groups = N;
    for (int i = N - 2; i >= 0; i--) {
        if (pos[i] + speed[i] * T >= pos[i+1] + speed[i+1] * T) {
            speed[i] = speed[i+1];
            groups--;
        }
    }

    fout << groups << endl;

    return 0;

}
