/*
ID: anirudh71
TASK: stalling
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int cows[21];
int stalls[21];
bool visited[21];
long long ans = 0;

void getSolutions(int cur) {

    if (cur == N) ans++;

    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        if (cows[cur] > stalls[i]) continue;
        visited[i] = true;
        getSolutions(cur + 1);
        visited[i] = false;
    }

}

int main() {

    ifstream fin("stalling.in");
    ofstream fout("stalling.out");

    cin >> N;
    for (int i = 0; i < N; i++) cin >> cows[i];
    for (int i = 0; i < N; i++) cin >> stalls[i];
    for (int i = 0; i < N; i++) visited[i] = false;

    getSolutions(0);
    cout << ans << endl;

    return 0;

}
