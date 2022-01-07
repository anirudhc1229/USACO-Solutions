/*
ID: anirudh71
TASK: bcs
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;

struct Piece {
    bool grid[9][9];
    int parent;
}

bool overlap(Piece a, Piece b) {
    for (int row = 0; row < N; row++)
        for (int col = 0; col < N; col++)
            if (a.grid[row][col] && b.grid[row][col]) return true;
    return false;
}

Piece sum(Piece a, Piece b) {
    Piece s;
    s.parent = -1;
    for (int row = 0; row < N; row++) 
        for (int col = 0; col < N; col++) 
            s.grid[row][col] = a.grid[row][col] + b.grid[row][col];
    return s;
}

bool equal(Piece a, Piece b) {
    for (int row = 0; row < N; row++) 
        for (int col = 0; col < N; col++)
            if (a.grid[row][col] != b.grid[row][col]) return false;
    return true;
}

int main() {

    ifstream fin("bcs.in");
    ofstream fout("bcs.out");

    fin >> N >> K;
    Piece orig;
    orig.parent = -1;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            char c; fin >> c;
            orig.grid[row][col] = c == '#';
        }
    }
        
    vector<Piece> pieces;
    for (int i = 0; i < K; i++) {
        Piece p;
        p.parent = i;
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                char c; fin >> c;
                pieces.grid[row][col] = c == '#';
            }
        }
        pieces.push_back(p);
    }

    // for (int row = 0; row < N; row++) {
    //     for (int col = 0; col < N; col++) {
    //         cout << orig[row][col] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for (int i = 0; i < K; i++) {
    //     for (int row = 0; row < N; row++) {
    //         for (int col = 0; col < N; col++) {
    //             cout << pieces[i][row][col] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }

    vector<Piece> valid;

    for (int i = 0; i < K; i++) {
        for (int vert = 1 - N; vert <= N - 1; vert++) {
            for (int horiz = 1 - N; horiz <= N - 1; horiz++) {
                if (good) valid.push_back({orientation, i}); // create condition
            }
        }
    }

    int piece1, piece2;

    for (int i = 0; i < valid.size(); i++) {
        for (int j = 0; j < valid.size(); j++) {
            if (overlap(Piece a, Piece b)) continue;
            if (areEqual(sum(pieces[i], pieces[j]), orig)) { 
                piece1 = valid[i].parent;
                piece2 = valid[j].parent;
                goto br;
            }
        }
    }

    br:
    cout << piece1 + 1 << " " << piece2 + 1 << endl;

    return 0;

}
