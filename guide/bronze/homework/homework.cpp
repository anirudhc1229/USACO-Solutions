/*
ID: anirudh71
TASK: homework
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("homework.in");
    ofstream fout("homework.out");

    int N;
    fin >> N;
    vector<int> scores(N);
    for (int i = 0; i < N; i++) fin >> scores[i];

    vector<int> prefix(N);
    prefix[0] = scores[0];
    for (int i = 1; i < N; i++) {
        prefix[i] = prefix[i-1] + scores[i];
    }
    
    vector<int> suffixSum(N), suffixMin(N);
    suffixSum[N-1] = suffixMin[N-1] = scores[N-1];
    for (int i = N - 2; i >= 0; i--) {
        suffixSum[i] = suffixSum[i+1] + scores[i];
        suffixMin[i] = min(suffixMin[i+1], scores[i]);
    }

    vector<float> kScores(N);
    for (int K = 1; K <= N - 2; K++) {
        kScores.push_back((suffixSum[] - min) / (N - K));
    }

    for (int K = 1; K < N - 1; K++) {

    }

    return 0;

}
