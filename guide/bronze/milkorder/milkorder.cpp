/*
ID: anirudh71
TASK: milkorder
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("milkorder.in");
    ofstream fout("milkorder.out");

    int N, M, K;
    fin >> N >> M >> K;
    vector<int> hierarchy(M);
    for (int i = 0; i < M; i++) {
        int cow;
        fin >> cow;
        hierarchy[i] = --cow;
    }
    vector<pair<int, int>> demands(K);
    for (int i = 0; i < K; i++) {
        int cow, pos;
        fin >> cow >> pos;
        demands[i] = {--cow, --pos};
    }

    vector<int> order(N);
    vector<bool> placed(N);
    for (int i = 0; i < N; i++) {
        order[i] = -1;
        placed[i] = false;
    }
    
    for (auto d : demands) {
        order[d.second] = d.first;
        placed[d.first] = true;
    }

    // if cow = 1, move to as early as possible, else as late as possible

    for (int i = 0; i < M; i++) {
        
        if (placed[hierarchy[i]]) continue;

        // get latest spot that hierarchy[i] can be placed
        // should at least leave space for placements 
        int latest = N - (M - i);
        // needs to come before demanded ones that come after it in hierarchy and leave space for other highers of that demand
        for (int j = i + 1; j < M; j++) {
            if (find(demands.begin(), demands.end(), hierarchy[j]) != demands.end()) {
                
            }
        }    
    
    }

    return 0;

}
