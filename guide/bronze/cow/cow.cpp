/*
ID: anirudh71
TASK: cow
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

    ifstream fin("cow.in");
    ofstream fout("cow.out");

    int N;
    fin >> N;
    string cow;
    fin >> cow;

    long long c = 0, o = 0, w = 0;
    for (long long i = 0; i < N; i++) {
        if (cow[i] == 'C') c++;
        if (cow[i] == 'O') o += c;
        if (cow[i] == 'W') w += o;
    }

    fout << w << endl;

    return 0;

}
