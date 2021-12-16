/*
ID: anirudh71
TASK: mowing
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Cell {
    int x;
    int y;
    int t;
};

int main() {

    ifstream fin("mowing.in");
    ofstream fout("mowing.out");

    int N;
    fin >> N; 
    Cell start;
    start.x, start.y, start.t = 0;
    vector<Cell> cells{start};
    int fjx = 0, fjy = 0, fjt = 0;
    vector<int> revisit;

    for (int i = 0; i < N; i++) {
        
        char dir;
        fin >> dir;
        int steps;
        fin >> steps;

        for (int i = 0; i < steps; i++) {
            
            if (dir == 'N') fjy++;
            else if (dir == 'S') fjy--;
            else if (dir == 'E') fjx++;
            else if (dir == 'W') fjx--;

            for (Cell c : cells) {
                if (fjx == c.x && fjy == c.y) {
                    revisit.push_back(fjt - c.t);
                }
            }

            Cell c;
            c.x = fjx, c.y = fjy, c.t = fjt;
            cells.push_back(c);

            fjt++;
        
        }
    
    }

    int ans = revisit.empty() ? -1 : *min_element(revisit.begin(), revisit.end());
    fout << ans << endl;

    return 0;

}
