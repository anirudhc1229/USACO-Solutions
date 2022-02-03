/*
ID: anirudh71
TASK: paint
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("paint.in");
    ofstream fout("paint.out");

    bool painted[101];
    for (int i = 0; i < 101; i++)
        painted[i] = false;
    int a1, b1, a2, b2;
    fin >> a1 >> b1 >> a2 >> b2;
    for (int i = a1; i < b1; i++)
        painted[i] = true;
    for (int i = a2; i < b2; i++)
        painted[i] = true;

    int ans = 0;
    for (int i = 0; i < 101; i++) {
        int streak = 0;
        for (int j = i; j < 101 && painted[j]; j++)
            streak++;
        ans = max(ans, streak);
    }

    fout << ans << endl;

    return 0;

}
