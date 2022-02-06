/*
ID: anirudh71
TASK: emop
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

    ifstream fin("emop.in");
    ofstream fout("emop.out");

    int N;
    cin >> N;
    vector<int> cows(N);
    for (int i = 0; i < N; i++) cin >> cows[i];

    int even = 0;
    int odd = 0;
    for (int c : cows) {
        if (c % 2 == 0) even++;
        else odd++;
    }

    int groups;
    for (groups = N; groups >= 1; groups--) {
        int e = even;
        int o = odd;
        bool good = true;
        for (int group = 0; group < groups; group++) {
            if (group % 2 == 0) {
                if (e >= 1) e--;
                else if (o >= 2) o -= 2;
                else good = false;
            } else {
                if (o >= 1) o--;
                else good = false;
            }
            if (!good) break;
            if (group == groups - 1 && o % 2 == 1) good = false;
        }
        if (good) break;
    }

    cout << groups << endl;

    return 0;

}
