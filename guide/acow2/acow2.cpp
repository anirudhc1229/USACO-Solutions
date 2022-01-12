/*
ID: anirudh71
TASK: acow2
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("acow2.in");
    ofstream fout("acow2.out");

    int K, N;
    cin >> K >> N;
    vector<string> names(N);
    for (int i = 0; i < N; i++) cin >> names[i];

    char output[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) output[i][j] = 'B';
            else output[i][j] = '?';
        }
    }

    for (int k = 0; k < K; k++) {
        vector<string> paper(N);
        for (int i = 0; i < N; i++) cin >> paper[i];
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (paper[j] < paper[j-1]) {
                    int iind = find(names.begin(), names.end(), paper[i]) - names.begin();
                    int jind = find(names.begin(), names.end(), paper[j]) - names.begin();
                    output[iind][jind] = '0';
                    output[jind][iind] = '1';
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << output[i][j];
        }
        cout << endl;
    }

    return 0;

}
