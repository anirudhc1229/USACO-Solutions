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
    for (Route r1 : routes) {
        if (find(r1.cities.begin(), r1.cities.end(), A) == r1.cities.end()) continue;
        for (Route r2 : routes) {
            if (find(r2.cities.begin(), r2.cities.end(), B) == r2.cities.end()) continue;
            for (int c : r1.cities) {
                if (find(r1.cities.begin(), r1.cities.end(), c) < find(r1.cities.begin(), r1.cities.end(), A)) continue;
                if (find(r2.cities.begin(), r2.cities.end(), c) > find(r2.cities.begin(), r2.cities.end(), B)) continue;
                if (r1.cities == r2.cities && r1.cost == r2.cost) ans = min(ans, r1.cost);
                else ans = min(ans, r1.cost + r2.cost);
            }
        }
    }

    if (ans == INT32_MAX) ans = -1;
    fout << ans << endl;

    return 0;

}
