/*
ID: anirudh71
TASK: ariprog
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {

    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");

    int N, M;
    fin >> N >> M;
    
    bool bsq[2*M*M + 1];
    for (int p = 0; p < M; p++) 
        for (int q = 0; q < M; q++) 
            bsq[p*p + q*q] = true;
    bool marked[2*M*M + 1];
    for (int i = 0; i < 2*M*M; i++) marked[i] = false;

    for (int dif = 1; dif <= N; dif++) {
        for (int i = 1; i <= 2*M*M; i++) {
            if (!bsq[i] || marked[i] || !bsq[i+dif] || marked[i+dif]) continue;
            for (int cur = i; cur < 2*M*M && bsq[cur]; cur += dif)
                marked[cur] = true;
            fout << i << " " << dif << endl;
        }
    }

    return 0;

}
