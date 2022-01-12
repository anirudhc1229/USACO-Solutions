/*
ID: anirudh71
TASK: acow1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("acow1.in");
    ofstream fout("acow1.out");

    int N, L;
    fin >> N >> L;
    vector<int> citations(N);
    for (int i = 0; i < N; i++) fin >> citations[i];
    sort(citations.begin(), citations.end());
    
    int h = 0;
    while (h < N) {
        if (citations[h] < N - 1 - h) h++;
        else break;
    }

    for (int i = 0; i < L; i++) {
        citations[h]++;
        h++;
        if (h == N) h = 0;
    }

    int h2 = 0;
    while (h2 < N) {
        if (citations[h2] < N - 1 - h2) h2++;
        else break;
    }

    fout << citations[h2] << endl;

    return 0;

}
