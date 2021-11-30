/*
ID: anirudh71
TASK: barn1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    // Purchasing M boards means leaving M-1 sets of empty stalls unblocked (plus any empty sets on leftmost and rightmost)
    // Get the M-1 largest sets of empty stalls as the ones that will be unblocked
    
    ifstream fin("barn1.in");
    ofstream fout("barn1.out");

    int M, S, C;
    fin >> M >> S >> C;
    
    vector<bool> hasCow;
    for (size_t i = 0; i < S; i++) {
        hasCow.push_back(false);
    }

    int i;
    while (fin >> i) {
        hasCow[i-1] = true;
    }

    int lEmpty = -1;
    for (int i = 0; !hasCow[i] && i < hasCow.size(); i++) lEmpty++;
    int rEmpty = 1;
    for (int i = hasCow.size() - 1; !hasCow[i] && i > -1; i--) rEmpty++;

    for (int i = 0; i < 2; i++) {
        vector<bool>::iterator it = hasCow.begin();
        while (!*it) it = hasCow.erase(it);
        reverse(hasCow.begin(), hasCow.end());
    }

    vector<int> emptySizes;
    for (size_t i = 0; i < hasCow.size(); i++) { 
        if (!hasCow[i]) {
            if (i == 0 || hasCow[i-1]) {
                emptySizes.push_back(1);
            } else {
                emptySizes[emptySizes.size() - 1]++;
            }
        }
    }

    sort(emptySizes.begin(), emptySizes.end(), greater<int>());

    int blocked = S;
    for (size_t i = 0; i < M - 1 && i < emptySizes.size(); i++) blocked -= emptySizes[i];
    blocked -= (lEmpty + rEmpty);

    fout << blocked << endl;

    return 0;

}