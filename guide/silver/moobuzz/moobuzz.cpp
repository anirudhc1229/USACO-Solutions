/*
ID: anirudh71
TASK: moobuzz
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
    ifstream fin("moobuzz.in");
    ofstream fout("moobuzz.out");

    int N; fin >> N;
    int num = 1;
    for (int i = 0; i < N; num++) {
        if (num % 3 && num % 5) i++;
    }

    fout << num - 1 << endl;

    return 0;

}
