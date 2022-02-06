/*
ID: anirudh71
TASK: photo
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

    ifstream fin("photo.in");
    ofstream fout("photo.out");

    int N;
    fin >> N;
    int bessie[N-1];
    for (int i = 0; i < N-1; i++) fin >> bessie[i];
    int farmer[N];

    for (int i = 1; i <= N; i++) {
        
        farmer[0] = i;
        for (int j = 1; j < N; j++) 
            farmer[j] = bessie[j-1] - farmer[j-1];

        bool good = true;
        unordered_set<int> used;
        for (int j = 0; j < N; j++) {
            if (used.count(farmer[j]) || farmer[j] < 1) {good = false; break;}
            else used.insert(farmer[j]);
        }

        if (good) break;

    }

    for (int i = 0; i < N - 1; i++) fout << farmer[i] << " ";
    fout << farmer[N-1] << endl;

    return 0;

}
