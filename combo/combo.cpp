/*
ID: anirudh71
TASK: combo
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isValid(int a, int b, int N) {
    if (a < b) swap(a, b); 
    return min(a - b, N - a + b) <= 2;
}

int main() {

    ifstream fin("combo.in");
    ofstream fout("combo.out");

    int N;
    fin >> N;
    vector<int> farmer(3);
    for (int i = 0; i < 3; i++) fin >> farmer[i];
    vector<int> master(3);
    for (int i = 0; i < 3; i++) fin >> master[i];
    
    int ans = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (isValid(i, farmer[0], N) && isValid(j, farmer[1], N) && isValid(k, farmer[2], N)) ans++;
                else if (isValid(i, master[0], N) && isValid(j, master[1], N) && isValid(k, master[2], N)) ans++;
            }
        }
    }

    fout << ans << endl;

}
