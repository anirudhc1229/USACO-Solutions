/*
ID: anirudh71
TASK: spacedout
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("spacedout.in");
    ofstream fout("spacedout.out");

    int N;
    cin >> N;
    int beauty[N+1][N+1];
    for (int row = 0; row < N; row++)
        for (int col = 0; col < N; col++)
            cin >> beauty[row][col];

    int rowsMax = 0;
    for (int row = 0; row < N; row++) {
        int alt1 = 0;
        int alt2 = 0;
        for (int col = 0; col < N; col++) {
            if (col % 2) alt1 += beauty[row][col];
            else alt2 += beauty[row][col];
        }
        rowsMax += max(alt1, alt2);
    }

    int colsMax = 0;
    for (int col = 0; col < N; col++) {
        int alt1 = 0;
        int alt2 = 0;
        for (int row = 0; row < N; row++) {
            if (row % 2) alt1 += beauty[row][col];
            else alt2 += beauty[row][col];
        }
        colsMax += max(alt1, alt2);
    }

    cout << max(rowsMax, colsMax) << endl;

    return 0;

}
