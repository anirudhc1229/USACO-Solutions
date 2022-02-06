/*
ID: anirudh71
TASK: socdist1
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

    ifstream fin("socdist1.in");
    ofstream fout("socdist1.out");

    int N;
    fin >> N;
    bool occupied[N];
    string o;
    fin >> o;
    for (int i = 0; i < N; i++)
        occupied[i] = o[i] == '1';
    
    vector<int> streaks;
    int cur = 0;
    for (int i = 1; i < N; i++) {
        if (!occupied[i]) cur++;
        else {
            streaks.push_back(cur);
            cur = 0;
        }
    }

    for (int s : streaks) cout << s << " "; cout << endl;

    if (streaks.size() == 1) { // change
        fout << 1 << endl;
        return 0;
    }

    streaks.erase(max_element(streaks.begin(), streaks.end()));
    for (int s : streaks) cout << s << " "; cout << endl;
    fout << ceil(*max_element(streaks.begin(), streaks.end()) / 2.0) << endl;

    return 0;

}
