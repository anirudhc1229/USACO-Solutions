/*
ID: anirudh71
TASK: highcard
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("highcard.in");
    ofstream fout("highcard.out");

    int N; fin >> N;
    vector<bool> elsieHas(N * 2);
    for (int i = 0; i < N; i++) {
        int card; fin >> card;
        elsieHas[i] = true;
    }

    vector<int> bessie;
    vector<int> elsie;
    for (int i = 1; i <= N; i++) {
        if (elsieHas[i]) elsie.push_back(i);
        else bessie.push_back(i);
    }

    vector<bool> used(N);
    for (int i = 0; i < N; i++) used[i] = false;

    int ans = 0;
    for (int card : elsie) {
        int i = 0;
        while ((bessie[i] <= card || used[i]) && i < N-1) i++;
        used[i] = true;
        if (bessie[i] > card) ans++;
    } 

    fout << ans << endl;

    return 0;

}
