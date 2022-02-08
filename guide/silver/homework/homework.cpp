/*
ID: anirudh71
TASK: homework
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
    ifstream fin("homework.in");
    ofstream fout("homework.out");

    int N; fin >> N;
    int questions[N];
    for (int i = 0; i < N; i++) fin >> questions[i];
    int suffixSum[N], suffixMin[N];
    suffixSum[N-1] = suffixMin[N-1] = questions[N-1];
    for (int i = N - 2; i >= 0; i--) {
        suffixSum[i] = suffixSum[i+1] + questions[i];
        suffixMin[i] = min(suffixMin[i+1], questions[i]);
    }

    int avgs[N];
    for (int k = 1; k <= N - 2; k++) {
        int sum = suffixSum[k];
        int lowest = suffixMin[k]; 
        int avg = (sum - lowest) / (N - k - 1);
        avgs[k] = avg;
    }

    int best = 0;
    for (int k = 1; k <= N - 2; k++)
        best = max(best, avgs[k]);
    for (int k = 1; k <= N - 2; k++)
        if (avgs[k] == best)
            fout << k << endl;

    return 0;

}
