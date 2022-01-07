/*
ID: anirudh71
TASK: air
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getBounds(int& start, int& end, vector<int> initial, vector<int> goal, int N) {
    
    int dir;
    
    for (start = 0, end = N - 1; start < N, end > -1; start++, end--) {
        if (initial[start] < goal[start] && initial[end] < goal[end]) {
            dir = 1;
            break;
        }
        else if (initial[start] > goal[start] && initial[end] > goal[end]) {
            dir = -1;
            break;
        }
    }

    for (start = 0; start < N; start++) {
        if (initial[start] < goal[start]) {
            dir = 1; break;
        } else if (initial[start] > goal[start]) {
            dir = -1; break;
        }
    }

    for (end = N - 1; end > -1; end--) {
        if (dir == 1 && initial[end] < goal[end]) break;
        else if (dir == -1 && initial[end] > goal[end]) break;
    }

    return dir;

}

int main() {

    ifstream fin("air.in");
    ofstream fout("air.out");

    int N;
    cin >> N;
    vector<int> goal(N);
    vector<int> initial(N);
    for (int i = 0; i < N; i++) cin >> goal[i];
    for (int i = 0; i < N; i++) cin >> initial[i];

    int ans = 0;
    
    while (initial != goal) {
        
        int start, end;
        int dir = getBounds(start, end, initial, goal, N);

        while (initial[start] != goal[start] && initial[end] != goal[end]) {
            for (int i = start; i <= end; i++) initial[i] += dir;
            ans++;
        }

    }

    cout << ans << endl;

    return 0;

}
