/*
ID: anirudh71
TASK: citystate
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {

    ifstream fin("citystate.in");
    ofstream fout("citystate.out");

    int N;
    fin >> N;

    map<string, string> ctos;
    for (int i = 0; i < N; i++) {
        string c, s;
        fin >> c >> s;
        ctos[c.substr(0, 2)] = s;
    }

    int ans = 0;

    for (auto a = ctos.begin(); a != ctos.end(); a++) {
        for (auto b = a; b != ctos.end(); b++) {
            if (a->first == b->second && b->first == a->second && a->second != b->second) {
                //cout << a->first << " " << a->second << " : " << b->first << " " << b->second << endl;
                ans++;
            }
        }
    }

    fout << ans << endl;

    return 0;

}
