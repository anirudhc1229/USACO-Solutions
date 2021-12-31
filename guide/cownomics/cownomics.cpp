/*
ID: anirudh71
TASK: cownomics
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {

    ifstream fin("cownomics.in");
    ofstream fout("cownomics.out");

    int N, M;
    fin >> N >> M;
    vector<string> spotty(N);
    for (int i = 0; i < N; i++) fin >> spotty[i];
    vector<string> plain(N);
    for (int i = 0; i < N; i++) fin >> plain[i];

    map<char, int> spottyCt;
    map<char, int> plainCt;
    int ans = 0;
    
    for (int i = 0; i < M; i++) {
        
        spottyCt['A'] = spottyCt['C'] = spottyCt['G'] = spottyCt['T'] = 0;
        plainCt['A'] = plainCt['C'] = plainCt['G'] = plainCt['T'] = 0;

        for (int j = 0; j < N; j++) {
            spottyCt[spotty[j][i]]++;
            plainCt[plain[j][i]]++;
        }

        bool valid = true;
        for (auto const& x : spottyCt) {
            if (x.second > 0 && plainCt[x.first] > 0) {
                valid = false;
                break;
            }
        }

        if (valid) ans++;

    }

    fout << ans << endl;

    return 0;

}
