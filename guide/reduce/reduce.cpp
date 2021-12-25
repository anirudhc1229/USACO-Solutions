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

    int avg = 0;
    for (Cow c : cows) avg += c.x + c.y;
    avg /= N;

    int remove = 0;
    for (int i = 1; i < N; i++) {
        if (cows[i].x + cows[i].y - avg > cows[remove].x + cows[remove].y - avg) {
            remove = i;
        }
    }

    cows.erase(cows.begin() + remove);

    int maxX = 0, maxY = 0, minX = 40000, minY = 40000;
    for (Cow c : cows) {
        if (c.x > maxX) maxX = c.x;
        if (c.y > maxY) maxY = c.y;
        if (c.x < minX) minX = c.x;
        if (c.y < minY) minY = c.y;
    }

    fout << (maxX - minX) * (maxY - minY) << endl;

    return 0;

}
