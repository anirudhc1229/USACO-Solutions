/*
ID: anirudh71
TASK: 2
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int play(vector<int> first, vector<int> second) { 
    int count = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (first[i] > second[j]) count++;
            else if (first[i] < second[j]) count--;
        }
    }
    if (count > 0) return 1;
    if (count < 0) return 2;
    return 0;
}

int main() {

    ifstream fin("2.in");
    ofstream fout("2.out");

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {

        vector<int> A(4);
        vector<int> B(4);
        for (int i = 0; i < 4; i++) cin >> A[i];
        for (int i = 0; i < 4; i++) cin >> B[i];

        bool good = false;
        for (int i = 1; i <= 10; i++) {
            for (int j = 1; j <= 10; j++) {
                for (int k = 1; k <= 10; k++) {
                    for (int l = 1; l <= 10; l++) {
                        vector<int> C = {i, j, k, l};
                        int aWins = 0, bWins = 0, cWins = 0;
                        int AB = play(A, B), BC = play(B, C), CA = play(C, A);
                        if (AB == 1) aWins++; else if (AB == 2) bWins++;
                        if (BC == 1) bWins++; else if (BC == 2) cWins++;
                        if (CA == 1) cWins++; else if (CA == 2) aWins++;
                        if (aWins == 1 && bWins == 1 && cWins == 1) {
                            good = true;
                            goto br;
                        }
                    }
                }
            }
        }

        br:
        if (good) cout << "yes" << endl;
        else cout << "no" << endl;
    
    }

    return 0;

}
