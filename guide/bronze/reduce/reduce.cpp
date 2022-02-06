/*
ID: anirudh71
TASK: reduce
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Cow {
    int x;
    int y;
};

int main() {

    ifstream fin("reduce.in");
    ofstream fout("reduce.out");

    int N;
    fin >> N;
    vector<Cow> cows(N);
    for (int i = 0; i < N; i++) {
        Cow c;
        fin >> c.x >> c.y;
        cows[i] = c;
    }

    // remove the cow furthest from the average

    double avgX = 0;
    double avgY = 0;
    for (Cow c : cows) {
        avgX += c.x;
        avgY += c.y;
    }
    avgX /= N;
    avgY /= N;

    cout << avgX << " " << avgY << endl;

    sort(cows.begin(), cows.end(), [&](Cow& a, Cow& b) -> bool {
        return sqrt(pow(a.x - avgX, 2) + pow(a.y - avgY, 2)) < sqrt(pow(b.x - avgX, 2) + pow(b.y - avgY, 2));
    });
    for (Cow c : cows) cout << c.x << " " << c.y << endl;
    cows.erase(cows.end() - 1);

    int maxX = 0, maxY = 0, minX = 40000, minY = 40000;
    for (Cow c : cows) {
        maxX = max(maxX, c.x);
        maxY = max(maxY, c.y);
        minX = min(minX, c.x);
        minY = min(minY, c.y);
    }

    fout << (maxX - minX) * (maxY - minY) << endl;

    return 0;

}
