/*
ID: anirudh71
TASK: sort
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("sort.in");
    ofstream fout("sort.out");

    int N;
    fin >> N;
    int A[N];
    for (int i = 0; i < N; i++) fin >> A[i];

    int ans = 0;
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        ans++;
        for (int i = 0; i < N - 1; i++) {
            if (A[i+1] < A[i]) {
                swap(A[i+1], A[i]);
                sorted = false;
            }
        }
    }

    fout << ans << endl;

    return 0;

}
