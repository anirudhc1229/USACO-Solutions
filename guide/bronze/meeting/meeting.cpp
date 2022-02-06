/*
ID: anirudh71
TASK: meeting
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

    ifstream fin("meeting.in");
    ofstream fout("meeting.out");

    int N, M;
    fin >> N >> M;
    vector<pair<int, int>> adj1[N];
    vector<pair<int, int>> adj2[N];
    for (int i = 0; i < M; i++) {
        int a, b, c, d;
        fin >> a >> b >> c >> d;
        adj1[a].push_back({b, c});
        adj2[a].push_back({b, d});
    }

    // go from field 1 to field N
    

    return 0;

}
