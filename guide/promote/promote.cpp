/*
ID: anirudh71
TASK: promote
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("promote.in");
    ofstream fout("promote.out");

    pair<int, int> bronze, silver, gold, plat;
    fin >> bronze.first >> bronze.second >> silver.first >> silver.second >> gold.first >> gold.second >> plat.first >> plat.second;
    int promote[3];
    promote[2] = plat.second - plat.first;
    promote[1] = promote[2] + gold.second - gold.first;
    promote[0] = promote[1] + silver.second - silver.first;

    for (int i = 0; i < 3; i++)
        fout << promote[i] << endl;

    return 0;

}
