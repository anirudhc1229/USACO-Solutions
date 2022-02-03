/*
ID: anirudh71
TASK: learning
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Cow {
    int weight;
    bool spotty;
};

int main() {

    ifstream fin("learning.in");
    ofstream fout("learning.out");

    int N, A, B;
    fin >> N >> A >> B;
    vector<Cow> cows(N);
    for (int i = 0; i < N; i++) {
        Cow c;
        string s;
        fin >> s;
        c.spotty = s == "S";
        fin >> c.weight;
        cows[i] = c;
    }

    sort(cows.begin(), cows.end(), 
        [](Cow a, Cow b) -> bool {return a.weight < b.weight;});

    // need to actually use A and B
    
    int ans = 0;
    for (int i = 0; i < N - 1; i++) {
        if (cows[i].spotty && cows[i+1].spotty) {
            // ans += cows[i+1].weight - cows[i].weight + 1;
            for (int w = cows[i].weight; w <= cows[i+1].weight; w++) 
                if (w >= A && w <= B) ans++;
        }
        // else if (cows[i].spotty || cows[i+1].spotty)
        //     ans += ceil((cows[i+1].weight - cows[i].weight + 1) / 2.0);
        else if (cows[i].spotty) {
            for (int w = cows[i].weight; w <= ceil((cows[i+1].weight - cows[i].weight) / 2.0); w++) 
                if (w >= A && w <= B) ans++;
        }
        else if (cows[i+1].spotty) {
            for (int w = cows[i+1].weight; w >= floor((cows[i+1].weight - cows[i].weight) / 2.0); w--)
                if (w >= A && w <= B) ans++;
        }
    }

    fout << ans << endl;

    return 0;

}
