/*
ID: anirudh71
TASK: marathon
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    int x;
    int y;
};

int main() {

    ifstream fin("marathon.in");
    ofstream fout("marathon.out");

    int N;
    fin >> N;
    vector<Point> points(N);
    for (int i = 0; i < N; i++) {
        Point p;
        fin >> p.x >> p.y;
        points[i] = p;
    }

    int total = 0;
    for (int i = 1; i < N; i++) {
        total += abs(points[i].x - points[i-1].x) + abs(points[i].y - points[i-1].y);
    }
    
    int ans = total;
    for (int i = 1; i < N - 1; i++) {
        int hypo = total;
        hypo -= abs(points[i].x - points[i-1].x) + abs(points[i].y - points[i-1].y);
        hypo -= abs(points[i].x - points[i+1].x) + abs(points[i].y - points[i+1].y);
        hypo += abs(points[i-1].x - points[i+1].x) + abs(points[i-1].y - points[i+1].y);
        ans = min(ans, hypo);
    }

    fout << ans << endl;

    return 0;

}
