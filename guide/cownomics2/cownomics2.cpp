/*
ID: anirudh71
TASK: cownomics2
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

    ifstream fin("cownomics2.in");
    ofstream fout("cownomics2.out");

    int N, M;
    fin >> N >> M;
    vector<string> spotty(N);
    for (int i = 0; i < N; i++) fin >> spotty[i];
    vector<string> plain(N);
    for (int i = 0; i < N; i++) fin >> plain[i];

    map<char, int> spottyCt;
    map<char, int> plainCt;
    int ans = 0;

    for (int pos1 = 0; pos1 < M - 2; pos1++) {
        for (int pos2 = pos1 + 1; pos2 < M - 1; pos2++) {
            for (int pos3 = pos1 + 2; pos3 < M; pos3++) {

                bool valid1 = true;
                
                spottyCt['A'] = spottyCt['C'] = spottyCt['G'] = spottyCt['T'] = 0;
                plainCt['A'] = plainCt['C'] = plainCt['G'] = plainCt['T'] = 0;
                
                for (int i = 0; i < N; i++) {
                    spottyCt[spotty[i][pos1]]++;
                    plainCt[plain[i][pos1]]++;
                }

                for (auto const& x : spottyCt) {
                    if (x.second > 0 && plainCt[x.first] > 0) {
                        valid1 = false;
                        break;
                    }
                }

                bool valid2 = true;

                spottyCt['A'] = spottyCt['C'] = spottyCt['G'] = spottyCt['T'] = 0;
                plainCt['A'] = plainCt['C'] = plainCt['G'] = plainCt['T'] = 0;
                
                for (int i = 0; i < N; i++) {
                    spottyCt[spotty[i][pos2]]++;
                    plainCt[plain[i][pos2]]++;
                }

                for (auto const& x : spottyCt) {
                    if (x.second > 0 && plainCt[x.first] > 0) {
                        valid2 = false;
                        break;
                    }
                }

                bool valid3 = true;

                spottyCt['A'] = spottyCt['C'] = spottyCt['G'] = spottyCt['T'] = 0;
                plainCt['A'] = plainCt['C'] = plainCt['G'] = plainCt['T'] = 0;
                
                for (int i = 0; i < N; i++) {
                    spottyCt[spotty[i][pos3]]++;
                    plainCt[plain[i][pos3]]++;
                }

                for (auto const& x : spottyCt) {
                    if (x.second > 0 && plainCt[x.first] > 0) {
                        valid3 = false;
                        break;
                    }
                }

                if (valid1 || valid2 || valid3) ans++;

            }
        }
    }

    fout << ans << endl;

    return 0;

}
