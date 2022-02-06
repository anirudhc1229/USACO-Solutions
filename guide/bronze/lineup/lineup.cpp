/*
ID: anirudh71
TASK: lineup
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {

    ifstream fin("lineup.in");
    ofstream fout("lineup.out");

    int N;
    fin >> N;
    
    vector<pair<string, string>> constraints(N);
    for (int i = 0; i < N; i++) {
        string line;
        while (getline(fin, line)) {
            constraints[i] = make_pair(line[0], line[5]);
        }
    }

    vector<string> lineup{"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};

    do {
        
        bool good = true;
        
        for (pair<string, string> c : constraints) {
            auto first = find(lineup.begin(), lineup.end(), c.first);
            auto second = find(lineup.begin(), lineup.end(), c.second);
            if (abs(distance(first, second)) > 1) {
                good = false;
                break;
            }
        } 
        
        if (good) break;
    
    } while (next_permutation(lineup.begin(), lineup.end()));

    for (string cow : lineup) fout << cow << endl;

    return 0;

}
