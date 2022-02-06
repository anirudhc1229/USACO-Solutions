/*
ID: anirudh71
TASK: reorder
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

    ifstream fin("reorder.in");
    ofstream fout("reorder.out");

    int N;
    fin >> N;
    vector<int> orig(N);
    vector<int> goal(N);
    for (int i = 0; i < N; i++) fin >> orig[i];
    for (int i = 0; i < N; i++) fin >> goal[i];

    int cycles = 0;
    int longest = -1;
    while (orig != goal) {
        cycles++;
        int curIndex = 0;
        while (orig[curIndex] == goal[curIndex]) curIndex++;
        int cur = orig[curIndex];
        do {
            for (int i = 0; i < N; i++) cout << orig[i] << " "; cout << endl;
            for (int i = 0; i < N; i++) cout << goal[i] << " "; cout << endl;
            int moveIndex = find(goal.begin(), goal.end(), cur) - goal.begin();
            orig[curIndex] = -1;
            longest = max(longest, abs(moveIndex - curIndex));
            int prev = cur;
            cur = orig[moveIndex];
            curIndex = moveIndex;
            orig[moveIndex] = prev;
        } while (find(orig.begin(), orig.end(), -1) != orig.end());
    }
    
    fout << cycles << " " << longest << endl;

    return 0;

}
