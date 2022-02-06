/*
ID: anirudh71
TASK: outofplace
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("outofplace.in");
    ofstream fout("outofplace.out");

    int N;
    fin >> N;
    vector<int> heights;
    for (int i = 0; i < N; i++) {
        int h; 
        fin >> h;
        heights.push_back(h);
    }

    vector<int> sorted(heights);
    sort(sorted.begin(), sorted.end());

    int ans = -1;
    for (int i = 0; i < N; i++) if (heights[i] != sorted[i]) ans++;

    fout << ans << endl;

    return 0;

}
