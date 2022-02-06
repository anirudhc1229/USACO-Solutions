/*
ID: anirudh71
TASK: whereami
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {

    ifstream fin("whereami.in");
    ofstream fout("whereami.out");

    int N;
    fin >> N;
    string colors;
    fin >> colors;
    int K;

    for (K = 1; K < N; K++) {
        unordered_set<string> sequences;
        bool good = true;
        for (int i = 0; i <= N - K; i++) {
            string seq = colors.substr(i, K);
            if (sequences.count(seq)) {
                good = false;
                break;
            }
            sequences.insert(seq);
        }
        if (good) break;
    }

    fout << K << endl;

    return 0;

}
