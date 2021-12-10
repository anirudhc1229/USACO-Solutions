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

int main() {

    ifstream fin("balancing.in");
    ofstream fout("balancing.out");

    int N;
    fin >> N;
    int B;
    fin >> B;
    vector<Cow> cows;
    for (int i = 0; i < N; i++) {
        Cow c;
        fin >> c.x >> c.y;
        cows.push_back(c);
    }

    int ans = N;

    for (int a = 0; a <= B; a += 2) {
        for (int b = 0; b <= B; b += 2) {
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
