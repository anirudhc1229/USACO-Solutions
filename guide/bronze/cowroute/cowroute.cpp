/*
ID: anirudh71
TASK: cowroute
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Route {
    vector<int> cities;
    int cost;
};

int main() {

    ifstream fin("cowroute.in");
    ofstream fout("cowroute.out");

    int A, B, N;
    fin >> A >> B >> N;
    vector<Route> routes(N);
    for (int i = 0; i < N; i++) {
        Route r;
        int j;
        fin >> r.cost >> j;
        for (int i = 0; i < j; i++) {
            int c;
            fin >> c;
            r.cities.push_back(c);
        }
        routes[i] = r;
    }

    int ans = INT32_MAX;
    for (Route r : routes) {
        if (find(r.cities.begin(), r.cities.end(), A) == r.cities.end()) continue;
        if (find(r.cities.begin(), r.cities.end(), B) == r.cities.end()) continue;
        if (find(r.cities.begin(), r.cities.end(), A) > find(r.cities.begin(), r.cities.end(), B)) continue;
        ans = min(ans, r.cost);
    }

    if (ans == INT32_MAX) ans = -1;
    fout << ans << endl;

    return 0;

}
