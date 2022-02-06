/*
ID: anirudh71
TASK: stacking
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("stacking.in");
    ofstream fout("stacking.out");

    int N, K;
    fin >> N >> K;
    int bales[N];
    for (int i = 0; i < N; i++) bales[i] = 0;
    for (int i = 0; i < K; i++) {
        int a, b;
        fin >> a >> b;
        for (int j = a - 1; j < b; j++) bales[j]++;
    }
    sort(bales, bales + N);
    fout << bales[N/2] << endl;

    return 0;

}
