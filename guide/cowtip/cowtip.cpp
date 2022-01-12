/*
ID: anirudh71
TASK: cowtip
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
bool tipped[11][11];

bool solved() {
    for (int row = 0; row < N; row++)
        for (int col = 0; col < N; col++)
            if (tipped[row][col]) return false;
    return true;
}

int main() {

    ifstream fin("cowtip.in");
    ofstream fout("cowtip.out");

    fin >> N;
    string line;
    int row = 0;
    getline(fin, line);
    while (getline(fin, line)) {
        for (int col = 0; col < N; col++) 
            tipped[row][col] = line[col] == '1';
        row++;
    }
    
    int ans = 0;

    while (!solved()) {
        
        ans++;
        int bestOnes = 0, bestZeros = 0, bestL = -1, bestW = -1;
        
        for (int l = 1; l <= N; l++) {
            for (int w = 1; w <= N; w++) {
                int ones = 0, zeros = 0;
                for (int row = 0; row < l; row++) {
                    for (int col = 0; col < w; col++) {
                        if (tipped[row][col]) ones++;
                        else zeros++;
                    }
                }
                if (ones > bestOnes || (ones == bestOnes && zeros < bestZeros)) {
                    bestOnes = ones;
                    bestZeros = zeros;
                    bestL = l;
                    bestW = w;
                }
            }
        }
        
        for (int row = 0; row < bestL; row++)
            for (int col = 0; col < bestW; col++)
                tipped[row][col] = !tipped[row][col];
    
    }

    fout << ans << endl;

    return 0;

}
