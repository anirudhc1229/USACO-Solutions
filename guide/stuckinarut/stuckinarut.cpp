/*
ID: anirudh71
TASK: stuckinarut
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Line {
    int x1;
    int y1;
    int x2;
    int y2;
    bool north;
};

int get_line_intersection(float p0_x, float p0_y, float p1_x, float p1_y, 
    float p2_x, float p2_y, float p3_x, float p3_y, float *i_x, float *i_y)
{
    float s02_x, s02_y, s10_x, s10_y, s32_x, s32_y, s_numer, t_numer, denom, t;
    s10_x = p1_x - p0_x;
    s10_y = p1_y - p0_y;
    s32_x = p3_x - p2_x;
    s32_y = p3_y - p2_y;

    denom = s10_x * s32_y - s32_x * s10_y;
    if (denom == 0)
        return 0; // Collinear
    bool denomPositive = denom > 0;

    s02_x = p0_x - p2_x;
    s02_y = p0_y - p2_y;
    s_numer = s10_x * s02_y - s10_y * s02_x;
    if ((s_numer < 0) == denomPositive)
        return 0; // No collision

    t_numer = s32_x * s02_y - s32_y * s02_x;
    if ((t_numer < 0) == denomPositive)
        return 0; // No collision

    if (((s_numer > denom) == denomPositive) || ((t_numer > denom) == denomPositive))
        return 0; // No collision
    // Collision detected
    t = t_numer / denom;
    if (i_x != NULL)
        *i_x = p0_x + (t * s10_x);
    if (i_y != NULL)
        *i_y = p0_y + (t * s10_y);

    return 1;
}

int dist(pair<int, int> p1, pair<int, int> p2) {
    return sqrt(pow(p2.first - p1.first, 2) + pow(p2.second - p1.second, 2));
}

int main() {

    ifstream fin("stuckinarut.in");
    ofstream fout("stuckinarut.out");

    int N; 
    fin >> N;
    vector<Line> lines;
    for (int i = 0; i < N; i++) {
        char dir; fin >> dir;
        int x, y; fin >> x >> y;
        if (dir == 'N') lines.push_back({x, y, x, INT_MAX});
        else lines.push_back({x, y, INT_MAX, y});
    }

    vector<int> endings;
    for (int i = 0; i < N; i++) endings.push_back(INT_MAX);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            float x, y;
            int inter = get_line_intersection(lines[i].x1, lines[i].y1, lines[i].x2, lines[i].y2, lines[j].x1, lines[j].y1, lines[j].x2, lines[j].y2, &x, &y);
            if (inter) { // PROBLEM: if a line has already been stopped, it shouldnt be able stop another line in the future: (11, 2) is stopped by (10, 4), but it still stops (4, 6)
                int dist1 = dist({lines[i].x1, lines[i].y1}, {x, y});
                int dist2 = dist({lines[j].x1, lines[j].y1}, {x, y});
                if (dist1 > dist2 && endings[j] > dist2) endings[i] = min(endings[i], dist1);
                // if (i == 2 && j == 4) cout << dist1 << " " << dist2 << " " << endings[j] << " " << dist2;
                else if (dist2 > dist1 && endings[i] > dist1) endings[j] = min(endings[j], dist2);
            }
        }
    }

    for (int ans : endings) {
        if (ans == INT_MAX) fout << "INFINITY";
        else fout << ans;
        fout << endl;
    }

    return 0;

}
