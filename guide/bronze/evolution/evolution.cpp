/*
ID: anirudh71
TASK: evolution
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool hasOne(string f1, string f2, vector<vector<string>> populations) {
    for (vector<string> p : populations) {
        if (find(p.begin(), p.end(), f1) != p.end() && find(p.begin(), p.end(), f2) == p.end()) {
            return true;
        }
    }
    return false;
}

bool hasBoth(string f1, string f2, vector<vector<string>> populations) {
    for (vector<string> p : populations) {
        if (find(p.begin(), p.end(), f1) != p.end() && find(p.begin(), p.end(), f2) != p.end()) {
            return true;
        }
    }
    return false;
}

int main() {

    ifstream fin("evolution.in");
    ofstream fout("evolution.out");

    int N;
    fin >> N;
    vector<vector<string>> populations(N);
    vector<string> allFeatures;
    for (int i = 0; i < N; i++) {
        int K;
        fin >> K;
        vector<string> features(K);
        for (int j = 0; j < K; j++) {
            fin >> features[j];
            allFeatures.push_back(features[j]);
        }
        populations[i] = features;
    }

    for (string f1 : allFeatures) {
        for (string f2 : allFeatures) {
            if (hasOne(f1, f2, populations) && hasOne(f2, f1, populations) && hasBoth(f1, f2, populations)) {
                fout << "no" << endl;
                return 0;
            }
        }
    }
    
    fout << "yes" << endl;

    return 0;

}
