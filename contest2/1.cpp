/*
ID: anirudh71
TASK: 1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int main() {

    ifstream fin("1.in");
    ofstream fout("1.out");

    char ans[3][3];
    char guess[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> ans[i][j];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> guess[i][j];

    int green = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (ans[i][j] == guess[i][j]) {
                green++;
                ans[i][j] = '-';
                guess[i][j] = '~';
            }
        } 
    }
    cout << green << endl;

    int yellow = 0;
    map<char, int> ansCounts;
    map<char, int> guessCounts;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ansCounts[ans[i][j]]++;
            guessCounts[guess[i][j]]++;
        }
    }
    for (auto x : guessCounts)
        yellow += min(x.second, ansCounts[x.first]);
    cout << yellow << endl;

    return 0;

}
