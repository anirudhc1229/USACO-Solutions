/*
ID: anirudh71
TASK: angry
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {

    ifstream fin("angry.in");
    ofstream fout("angry.out");

    int N;
    fin >> N;
    vector<int> bales(N);
    for (int i = 0; i < N; i++) fin >> bales[i];
    
    int minBale = *min_element(bales.begin(), bales.end());
    int maxBale = *max_element(bales.begin(), bales.end());
    vector<bool> hasBale(maxBale + 1);
    int ans = 0;

    for (int start = minBale; start <= maxBale; start++) {

        for (int i = 0; i <= maxBale; i++) hasBale[i] = false;
        for (int b : bales) hasBale[b] = true;
        if (!hasBale[start]) continue;

        queue<int> toExplode;
        toExplode.push(start);
        int radius = 1;
        int exploded = 1;

        while (!toExplode.empty()) {
            int cur = toExplode.front();
            toExplode.pop();
            hasBale[cur] = false;
            for (int i = cur - radius; i <= cur + radius; i++) {
                if (i < minBale || i > maxBale) continue;
                if (hasBale[i]) {
                    toExplode.push(i);
                    if (start == 5 && cur == 8) cout << radius << endl;
                    hasBale[i] = false;
                    exploded++;
                }
            }
            radius++; // radius is wrong
        }

        // cout << start << ": " << exploded << endl;
        ans = max(ans, exploded);

    }

    fout << ans << endl;

    return 0;

}
