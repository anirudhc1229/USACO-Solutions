/*
ID: anirudh71
TASK: pails
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// int ans = 0;
// int X, Y, M;

// void subsets(vector<int> sub) {
//     if (sub.size() > floor(M / X)) return;
//     int sum = 0;
//     for (int s : sub) sum += s;
//     if (sum <= M) ans = max(ans, sum);
//     sub.push_back(X);
//     subsets(sub);
//     sub.pop_back();
//     sub.push_back(Y);
//     subsets(sub);
// }

int main() {

    ifstream fin("pails.in");
    ofstream fout("pails.out");

    // smartass answer
    // fin >> X >> Y >> M;
    // vector<int> sub;
    // sub.push_back(X);
    // subsets(sub);
    // sub.pop_back();
    // sub.push_back(Y);
    // subsets(sub);
    // fout << ans << endl;

    // brute force
    int X, Y, M;
    fin >> X >> Y >> M;
    int ans = 0;

    for (int xTimes = 0; xTimes < M; xTimes++) {
        for (int yTimes = 0; yTimes < M; yTimes++) {
            int sum = 0;
            for (int i = 0; i < xTimes; i++) sum += X;
            for (int i = 0; i < yTimes; i++) sum += Y;
            if (sum <= M) ans = max(ans, sum);
        }
    }

    fout << ans << endl;

    return 0;

}
