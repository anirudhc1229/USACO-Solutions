/*
ID: anirudh71
TASK: balancing
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

void getLines(vector<int>& vert, vector<int>& horiz, vector<Cow> cows) {
    
    sort(cows.begin(), cows.end(), 
        [](Cow& c1, Cow& c2) -> bool {return c1.x < c2.x;});
    for (Cow c : cows) vert.push_back(c.x - 1);

    sort(cows.begin(), cows.end(), 
        [](Cow& c1, Cow& c2) -> bool {return c1.y < c2.y;});
    for (Cow c : cows) horiz.push_back(c.y - 1);

}

int main() {

    ifstream fin("balancing.in");
    ofstream fout("balancing.out");

    int N, B;
    fin >> N >> B;
    vector<Cow> cows;
    for (int i = 0; i < N; i++) {
        int x, y; 
        fin >> x >> y;
        cows.push_back({x, y});
    }

    int ans = N;
    vector<int> vert, horiz;
    getLines(vert, horiz, cows);

    for (int a : vert) {
        for (int b : horiz) {
            vector<int> quadrants{0, 0, 0, 0};
            for (Cow c : cows) {
                if (c.x > a && c.y > b) quadrants[0]++;
                if (c.x < a && c.y > b) quadrants[1]++;
                if (c.x < a && c.y < b) quadrants[2]++;
                if (c.x > a && c.y < b) quadrants[3]++;
            }
            ans = min(ans, *max_element(quadrants.begin(), quadrants.end()));
        }
    }

    fout << ans << endl;

    return 0;

}
