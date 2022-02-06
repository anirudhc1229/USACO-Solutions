/*
ID: anirudh71
TASK: 3
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
int cows[100001];

bool allSame() {
    for (int i = 1; i < N; i++)
        if (cows[i] != cows[0]) return false;
    return true;
}

int main() {

    ifstream fin("3.in");
    ofstream fout("3.out");

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {

        cin >> N;
        for (int j = 0; j < N; j++) cin >> cows[j];

        int ans = 0;
        while (!allSame()) {
            int maxPair = 0;
            for (int j = 1; j < N - 1; j++)
                if (cows[j] + cows[j+1] > cows[maxPair] + cows[maxPair+1])
                    maxPair = j;
            cows[maxPair]--;
            cows[maxPair+1]--;
            ans += 2;
            if (cows[maxPair] < 0 || cows[maxPair+1] < 0) {
                ans = -1;
                break;
            } 
        }

        cout << ans << endl;
    
    }

    return 0;

}
