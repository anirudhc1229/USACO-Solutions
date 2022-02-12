/*
ID: anirudh71
TASK: highcard
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("highcard.in");
    ofstream fout("highcard.out");

    int N; fin >> N;
    vector<int> elsie(N);
    set<int> deck;
    for (int& e : elsie) {
        fin >> e;
        deck.insert(e);
    }
    vector<int> bessie;
    for (int i = 1; i <= 2*N; i++)
        if (!deck.count(i))
            bessie.push_back(i);
    vector<bool> used(N);

    int wins = 0;
    for (int e : elsie) {
        int i = 0;
        while (bessie[i] < e || used[i]) i++; 
        if (i < N) {
            wins++;
            used[i] = true;
        } 
    }

    fout << wins << endl;

    return 0;

}
