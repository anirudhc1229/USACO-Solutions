/*
ID: anirudh71
TASK: censor
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("censor.in");
    ofstream fout("censor.out");

    string s, t;
    fin >> s >> t;

    while (s.find(t) != -1) s.erase(s.find(t), t.length());

    fout << s << endl;

    return 0;

}
