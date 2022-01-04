/*
ID: anirudh71
TASK: moo
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

int main() {

    ifstream fin("moo.in");
    ofstream fout("moo.out");

    int N;
    fin >> N;
    
    string ans = "moo";
    string middle = "moo";
    
    for (int i = 0; i < N; i++) {
        middle += 'o';
        ans = ans + middle + ans;
    }

    fout << ans[N-1] << endl;

    return 0;

}
