/*
ID: anirudh71
TASK: teleport
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

    ifstream fin("teleport.in");
    ofstream fout("teleport.out");

    int a, b, x, y;
    fin >> a >> b >> x >> y;

    int opt1 = abs(a - b);
    int opt2 = abs(a - x) + abs(b - y);
    int opt3 = abs(a - y) + abs(b - x);
    fout << min(opt1, min(opt2, opt3)) << endl;

    return 0;

}
