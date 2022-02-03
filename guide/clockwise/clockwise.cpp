/*
ID: anirudh71
TASK: clockwise
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

    ifstream fin("clockwise.in");
    ofstream fout("clockwise.out");

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string fence;
        cin >> fence;
        int cw = 0;
        int ccw = 0;
        for (int j = 1; j < fence.length(); j++) {
            if (fence[j-1] == 'N') {
                if (fence[j] == 'E') cw++;
                if (fence[j] == 'W') ccw++;
            }
            if (fence[j-1] == 'E') {
                if (fence[j] == 'S') cw++;
                if (fence[j] == 'N') ccw++;
            }
            if (fence[j-1] == 'S') {
                if (fence[j] == 'W') cw++;
                if (fence[j] == 'E') ccw++;
            }
            if (fence[j-1] == 'W') {
                if (fence[j] == 'N') cw++;
                if (fence[j] == 'S') ccw++;
            }
        }
        if (cw > ccw) cout << "CW" << endl;
        else cout << "CCW" << endl;
    }

    return 0;

}
