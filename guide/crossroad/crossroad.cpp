/*
ID: anirudh71
TASK: crossroad
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("crossroad.in");
    ofstream fout("crossroad.out");

    int N;
    fin >> N;
    int side[10];
    for (int i = 0; i < 10; i++) side[i] = -1;
    
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int cow, s;
        fin >> cow >> s;
        cow--;
        if (side[cow] == 0 && s == 1 || side[cow] == 1 && s == 0)
            ans++;
        side[cow] = s; 
    }

    fout << ans << endl;

    return 0;

}
