/*
ID: anirudh71
TASK: bcount
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("bcount.in");
    ofstream fout("bcount.out");

    int N, K;
    fin >> N >> K;
    int cows[N];
    for (int i = 0; i < N; i++) fin >> cows[i];
    
    int prefix1[N], prefix2[N], prefix3[N];
    prefix1[0] = (cows[0] == 1);
    prefix2[0] = (cows[0] == 2);
    prefix3[0] = (cows[0] == 3);
    for (int i = 1; i < N; i++) {
        prefix1[i] = prefix1[i-1] + (cows[i] == 1);
        prefix2[i] = prefix2[i-1] + (cows[i] == 2);
        prefix3[i] = prefix3[i-1] + (cows[i] == 3);
    }

    for (int i = 0; i < K; i++) {
        int a, b;
        fin >> a >> b;
        a--; b--;
        if (a == 0) 
            fout << prefix1[b] << " " << prefix2[b] << " " << prefix3[b];
        else 
            fout << prefix1[b] - prefix1[a-1] << " " << prefix2[b] - prefix2[a-1] << " " << prefix3[b] - prefix3[a-1];
        fout << endl;
    }

    return 0;

}
