/*
ID: anirudh71
TASK: taming
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("taming.in");
    ofstream fout("taming.out");

    int N;
    fin >> N;
    vector<int> counter(N);
    for (int i = 0; i < N; i++) fin >> counter[i];

    bool good = true;
    if (counter[0] > 0) good = false;
    else counter[0] = 0;

    for (int i = 0; i < N; i++) {
        if (counter[i] > 0) {
            for (int j = i - 1; j >= i - counter[i]; j--) {
                if ((counter[j] != -1) && (counter[j] != counter[i] - (i - j))) {
                    good = false;
                    break;
                } else {
                    counter[j] = counter[i] - (i - j);
                }
            }
        }
    }

    if (good) {
        int min = 0;
        int max = 0;
        for (int i = 0; i < N; i++) {
            if (counter[i] == 0) min++;
            if (counter[i] <= 0) max++;
        }
        fout << min << " " << max << endl;
    } else {
        fout << -1 << endl;
    }

    return 0;

}
