/*
ID: anirudh71
TASK: closestcow
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
    ifstream fin("closestcow.in");
    ofstream fout("closestcow.out");

    int K, M, N;
    fin >> K >> M >> N;
    vector<pii> patches(K);
    for (pii& p : patches) fin >> p.first >> p.second;

    // place cows on N best patches, then count 

    return 0;

}
