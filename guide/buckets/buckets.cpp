/*
ID: anirudh71
TASK: buckets
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("buckets.in");
    ofstream fout("buckets.out");

    pair<int, int> lake, barn, rock;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            char square;
            fin >> square;
            if (square == 'L') lake = {i, j};
            else if (square == 'B') barn = {i, j};
            else if (square == 'R') rock = {i, j};
        }
    }

    int ans = abs(lake.first - barn.first) + abs(lake.second - barn.second) - 1;
    if (rock.first == barn.first || rock.second == lake.second) ans += 2;
    
    fout << ans << endl;

    return 0;

}
