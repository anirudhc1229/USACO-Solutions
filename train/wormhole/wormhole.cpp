/*
ID: anirudh71
TASK: wormhole
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Wormhole {
    int x;
    int y;
    bool paired;
    Wormhole* next;
    Wormhole* partner;
};

bool check(vector<Wormhole> wormholes, int N) {

    for (int start = 0; start < N; start++) {
        Wormhole* current = &wormholes[start];
        for (int i = 0; i < N; i++) {
            cout << i << endl; cout << current->next->partner << endl;
            current = current->next->partner; // PROBLEM HERE
        }
        if (current != NULL) return true;
    }

    return false;

}

void dfs(vector<Wormhole> wormholes, int N, int& ans) {

    int first;
    for (first = 0; first < N && wormholes[first].paired; first++);
    if (first == N) {
        if (check(wormholes, N)) ans++;
    }

    for (int second = first + 1; second < N; second++) {
        if (!wormholes[second].paired) {
            wormholes[first].paired = wormholes[second].paired = true;
            wormholes[first].partner = &wormholes[second]; wormholes[second].partner = &wormholes[first];
            dfs(wormholes, N, ans);
            wormholes[first].paired = wormholes[second].paired = false;
        }
    } 

}

int main() {

    ifstream fin("wormhole.in");
    ofstream fout("wormhole.out");

    int N;  
    fin >> N;
    vector<Wormhole> wormholes;
    for (int i = 0; i < N; i++) {
        Wormhole wh;
        fin >> wh.x >> wh.y;
        wormholes.push_back(wh);
    }

    // find pairs of wormholes that can be traversed without infinite looping
    
    int ans = N;
    
    for (int i = 0; i < wormholes.size(); i++) {
        for (int j = 0; j < wormholes.size(); j++) {
            // cant map wormhole to itself
            // cow only moves in +x direction, so a.x < b.x && a.y == b.y
            // this mapping is only valid if a doesn't have a pair or b comes before current pairing (meaning a would hit b first instead of current)
            if (i != j) {
                Wormhole a = wormholes[i];
                Wormhole b = wormholes[j];
                if (a.x < b.x && a.y == b.y && (a.next == NULL || b.x < a.next->x)) a.next = &b;
            }
        }
    }

    dfs(wormholes, N, ans);

    fout << ans << endl;

    return 0;

}
