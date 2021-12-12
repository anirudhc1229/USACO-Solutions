/*
ID: anirudh71
TASK: daisy
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("daisy.in");
    ofstream fout("daisy.out");

    int N;
    fin >> N;
    vector<int> petals;
    for (int i = 0; i < N; i++) {
        int p;
        fin >> p;
        petals.push_back(p);
    }

    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            vector<int> photo;
            for (int k = i; k <= j; k++) photo.push_back(petals[k]);
            float avg = 0;
            for (int flower : photo) avg += flower;
            avg /= photo.size();
            for (int flower : photo) {
                if (flower == avg) {
                    ans++;
                    break;
                }
            }
        }
    }

    fout << ans << endl;

    return 0;

}
