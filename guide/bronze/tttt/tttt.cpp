/*
ID: anirudh71
TASK: tttt
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {

    ifstream fin("tttt.in");
    ofstream fout("tttt.out");

    char board[3][3];
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            char c;
            fin >> c;
            board[row][col] = c;
        }
    }

    int ones = 0;
    int twos = 0;
    
    for (int row = 0; row < 3; row++) {
        set<char> used;
        used.insert(board[row][0]);
        used.insert(board[row][1]);
        used.insert(board[row][2]);
        if (used.size() == 1) ones++;
        else if (used.size() == 2) twos++;
    }

    for (int col = 0; col < 3; col++) {
        set<char> used;
        used.insert(board[0][col]);
        used.insert(board[1][col]);
        used.insert(board[2][col]);
        if (used.size() == 1) ones++;
        else if (used.size() == 2) twos++;
    }

    set<char> diag1Used;
    diag1Used.insert(board[0][0]);
    diag1Used.insert(board[1][1]);
    diag1Used.insert(board[2][2]);
    if (diag1Used.size() == 1) ones++;
    else if (diag1Used.size() == 2) twos++;

    set<char> diag2Used;
    diag2Used.insert(board[2][0]);
    diag2Used.insert(board[1][1]);
    diag2Used.insert(board[0][2]);
    if (diag2Used.size() == 1) ones++;
    else if (diag2Used.size() == 2) twos++;

    fout << ones << endl << twos << endl;

    return 0;

}
