/*
ID: anirudh71
TASK: maxcross
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("maxcross.in");
    ofstream fout("maxcross.out");

    int N, K, B;
    fin >> N >> K >> B;
    bool broken[N];
    for (int i = 0; i < N; i++) broken[i] = false;
    for (int i = 0; i < B; i++) {
        int s;
        fin >> s;
        broken[s] = true;
    }

    int prefix[N];
    prefix[0] = broken[0];
    for (int i = 1; i < N; i++)
        prefix[i] = prefix[i-1] + broken[i];
    
    int ans = INT32_MAX;
    for (int i = 1; i < N - K; i++) 
        ans = min(ans, prefix[i+K-1] - prefix[i-1]);

    fout << ans << endl;

    return 0;

}
