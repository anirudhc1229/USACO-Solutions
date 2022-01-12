/*
ID: anirudh71
TASK: swap
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("swap.in");
    ofstream fout("swap.out");

    int N, K;
    fin >> N >> K;
    vector<int> cows;
    for (int c = 1; c <= N; c++) cows.push_back(c);
    int a1, a2, b1, b2;
    fin >> a1 >> a2 >> b1 >> b2;

    for (int i = 0; i < K; i++) {
        reverse(cows.begin() + a1 - 1, cows.begin() + a2);
        reverse(cows.begin() + b1 - 1, cows.begin() + b2);
        for (int c : cows) cout << c; cout << endl;
    }

    for (int c : cows) fout << c << endl;

    return 0;

}
