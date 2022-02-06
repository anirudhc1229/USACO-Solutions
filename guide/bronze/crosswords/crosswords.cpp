/*
ID: anirudh71
TASK: crosswords
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool blocked[51][51];
int N, M;

bool valid(int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < N && !blocked[i][j];
}

int main() {

    ifstream fin("crosswords.in");
    ofstream fout("crosswords.out");

    fin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            fin >> c;
            blocked[i][j] = c == '#';
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << blocked[i][j] << " ";
        }
        cout << endl;
    }
    
    vector<pair<int, int>> clues;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == 1 && j == 1) {
                cout << (valid(i, j) && valid(i + 1, j) && valid(i + 2, j) && !valid(i - 1, j)) << endl;
                cout << (valid(i, j) && valid(i, j + 1) && valid(i, j + 2) && !valid(i, j - 1)) << endl;
            }
            if (valid(i, j) && valid(i + 1, j) && valid(i + 2, j) && !valid(i - 1, j))
                clues.push_back({i, j});
            else if (valid(i, j) && valid(i, j + 1) && valid(i, j + 2) && !valid(i, j - 1))
                clues.push_back({i ,j});
        }
    }

    fout << clues.size() << endl;
    for (auto clue : clues) {
        fout << clue.first + 1 << " " << clue.second + 1 << endl;
    }

    return 0;

}
