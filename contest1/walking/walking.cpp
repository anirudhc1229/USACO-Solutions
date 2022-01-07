/*
ID: anirudh71
TASK: walking
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, K;
bool good[N][N];

int check1() {

    bool path1 = true;
    for (int i = 0; i < N; i++) {
        if (!good[0][i] || !good[i][N-1]) {
            path1 = false;
            break;
        }
    }
    
    bool path2 = true;
    for (int i = 0; i < N; i++) {
        if (!good[i][0] || !good[N-1][i]) {
            path2 = false;
            break;
        }
    }

    return path1 + path2;

}

int check2() {

    int valid;
    
    for (int i = 1; i < N - 1; i++) {
        for (int)
    }

    for (int i = 1; i < N - 1; i++) {

    }

}

int check3() {

}

int main() {

    ifstream fin("walking.in");
    ofstream fout("walking.out");

    fin >> T;
    
    for (int i = 0; i < T; T++) {

        fin >> N >> K;

        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                char c; fin >> c;
                good[row][col] = c == '.';
            }
        }    

        int paths = 0;

        if (K == 1) {
            paths += check1();
        }

        if (K == 2) {
            paths += check1() + check2();
        }

        if (K == 3) {
            paths += check1() + check2() + check3();
        }

        fout << paths << endl;

    }

    return 0;

}
