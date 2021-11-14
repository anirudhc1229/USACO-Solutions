/*
ID: anirudh71
TASK: transform
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define LEN(arr) sizeof(arr) / sizeof(*arr)

using namespace std;

void mirrorMatrix(vector<vector<char>>& mat, int N) {

    // for each row, start at each end and switch the two indeces until you get to the halfway point
    
    for (int row = 0; row < N; row++) {
        int start = 0;
        int end = N - 1;
        while (start < end) {
            int temp = mat[row][start];
            mat[row][start] = mat[row][end];
            mat[row][end] = temp;
            start++;
            end--;
        }
    }

}

void rotateMatrix(vector<vector<char>>& mat, int N) {
    
    // move elements clockwise from outermost layer to innermost layer (there are floor(N/2) layers)
    // for each layer, move the group of elements at each index of that layer on each side clockwise
   
    for (int row = 0; row < N / 2; row++) {
        for (int col = row; col < N - row - 1; col++) {
            int temp = mat[row][col];
            mat[row][col] = mat[N - 1 - col][row];
            mat[N - 1 - col][row] = mat[N - 1 - row][N - 1 - col];
            mat[N - 1 - row][N - 1 - col] = mat[col][N - 1 - row];
            mat[col][N - 1 - row] = temp;
        }
    }

}

int getTransformation(vector<vector<char>> orig, vector<vector<char>> mod, int N) {

    // rotate 3 times
    // each time, check if equals: return i + 1
    // rotate back
    // check if equals: return 6
    // mirror
    // check if equals: return 4
    // rotate 3 times
    // each time, check if equals: return 5
    // return 7

    vector<vector<char>> hypo;
    copy(orig.begin(), orig.end(), back_inserter(hypo));

    for (int i = 0; i < 3; i++) {
        rotateMatrix(hypo, N);
        bool rmatch = true;
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                if (hypo[row][col] != mod[row][col]) {
                    rmatch = false;
                    goto cont2;
                }
            }
        }
        cont2:
        if (rmatch) {
            return i + 1;
        }
    }

    rotateMatrix(hypo, N);
    if (hypo == mod) {
        return 6;
    }
    
    mirrorMatrix(hypo, N);
    bool mmatch = true;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (hypo[row][col] != mod[row][col]) {
                mmatch = false;
                goto br;
            }
        }
    }
    br:
    if (mmatch) {
        return 4;
    }

    for (int i = 0; i < 3; i++) {
        rotateMatrix(hypo, N);
        bool mrmatch = true;
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                if (hypo[row][col] != mod[row][col]) {
                    mrmatch = false;
                    goto cont;
                }
            }
        }
        cont:
        if (mrmatch) {
            return 5;
        }
    }

    return 7;

}

int main() {
    
    ifstream fin("transform.in");
    ofstream fout("transform.out");

    int N;
    fin >> N;
    
    vector<vector<char>> orig(N, vector<char>(N));
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            fin >> orig[row][col];
        }
    }
    
    vector<vector<char>> mod(N, vector<char>(N));
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            fin >> mod[row][col];
        }
    }

    fout << getTransformation(orig, mod, N) << endl;
    
    return 0;

}