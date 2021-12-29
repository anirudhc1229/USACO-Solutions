/*
ID: anirudh71
TASK: billboard
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Billboard {
    int x1, x2, y1, y2;
};

int main() {

    ifstream fin("billboard.in");
    ofstream fout("billboard.out");

    Billboard bad;
    fin >> bad.x1 >> bad.y1 >> bad.x2 >> bad.y2;
    Billboard good;
    fin >> good.x1 >> good.y1 >> good.x2 >> good.y2;
    
    int tarpX;
    int tarpY;

    if (good.y1 <= bad.y1 && good.y2 >= bad.y2) { // good is taller and covers
        if (good.x1 <= bad.x1) {
            tarpX = bad.x2 - good.x2; // good is left of bad
        } else {
            tarpX = bad.x1 - good.x1; // good is right of bad
        }
    } else {
        tarpX = bad.x2 - bad.x1;
    }

    if (good.x1 <= bad.x1 && good.x2 >= bad.x2) { // good is wider and covers
        if (good.y1 <= bad.y1) {
            tarpY = bad.y2 - good.y2; // good is below bad
        } else {
            tarpY = good.y1 - bad.y1; // good is above bad
        }
    } else {
        tarpY = bad.y2 - bad.y1;
    }

    fout << abs(tarpX * tarpY) << endl;

    return 0;

}
