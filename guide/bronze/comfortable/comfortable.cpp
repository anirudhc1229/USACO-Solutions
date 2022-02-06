/*
ID: anirudh71
TASK: comfortable
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int pasture[1001][1001];

bool valid(int x, int y) {
    return x >= 0 && x <= 1000 && y >= 0 && y <= 1000;
}

int check(int x, int y) {
    if (!valid(x, y)) return 0;
    if (pasture[x][y] == -1) return 0;
    int old = pasture[x][y];
    int comfort = 0;
    if (valid(x-1, y) && pasture[x-1][y] != -1) comfort++;
    if (valid(x+1, y) && pasture[x+1][y] != -1) comfort++;
    if (valid(x, y-1) && pasture[x][y-1] != -1) comfort++;
    if (valid(x, y+1) && pasture[x][y+1] != -1) comfort++;
    pasture[x][y] = comfort;
    if (old == 2 && pasture[x][y] == 3) return 1;
    if (old == 3 && pasture[x][y] == 4) return -1;
    return 0;
}

int main() {

    ifstream fin("comfortable.in");
    ofstream fout("comfortable.out");

    int N;
    cin >> N;
    for (int i = 0; i < 1000; i++) 
        for (int j = 0; j < 1000; j++) 
            pasture[i][j] = -1;

    int comfortable = 0;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        pasture[x][y] = 0;
        comfortable += check(x, y);
        comfortable += check(x-1, y);
        comfortable += check(x+1, y);
        comfortable += check(x, y-1);
        comfortable += check(x, y+1);
        cout << comfortable << endl;
    }

    return 0;

}
