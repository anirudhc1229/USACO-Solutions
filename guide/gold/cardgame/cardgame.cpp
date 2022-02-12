/*
ID: anirudh71
TASK: cardgame
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
    ifstream fin("cardgame.in");
    ofstream fout("cardgame.out");

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
    for (int e = 0; e < N/2; e++) {
        int b = 0;
        while (b < N/2 && (bessie[b] < elsie[e] || used[b])) b++;
        if (b < N/2) {
            wins++;
            used[b] = true;
        }
    }
    for (int e = N/2; e < N; e++) {
        int b = N - 1;
        while (b >= N/2 && (bessie[b] > elsie[e] || used[b])) b--;
        if (b >= N/2) {
            wins++;
            used[b] = true;
        }
    }

    fout << wins << endl;

    return 0;

}
