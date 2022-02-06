/*
ID: anirudh71
TASK: speeding
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("speeding.in");
    ofstream fout("speeding.out");

    int N, M;
    fin >> N >> M;
    vector<int> limit, speed;
    for (int i = 0; i < N; i++) {
        int len, lim;
        fin >> len >> lim;
        for (int j = 0; j < len; j++) 
            limit.push_back(lim);
    }
    for (int i = 0; i < M; i++) {
        int len, mph;
        fin >> len >> mph;
        for (int j = 0; j < len; j++) 
            speed.push_back(mph);
    }

    int ans = 0;
    for (int i = 0; i < 100; i++)
        ans = max(ans, speed[i] - limit[i]);

    fout << ans << endl;

    return 0;

}
