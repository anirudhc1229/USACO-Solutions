/*
ID: anirudh71
TASK: race
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("race.in");
    ofstream fout("race.out");

    int K, N;
    fin >> K >> N;
    vector<int> X(N);
    for (int i = 0; i < N; i++) fin >> X[i];

    for (int x : X) {
        int pos = 0, speed = 0, time = 0;
        while (pos < K) {
            // if difference between projected position and end less difference betweeen current speed and goal speed, 
            // won't be able to slow down in time if you don't slow down now
            if (K - (pos + speed) < speed - x) speed--;
            // if increasing the speed causes inability to slow down in time, keep same speed
            else if (K - (pos + (speed + 1)) < (speed + 1) - x) speed = speed;
            // otherwise, we're allowed to increase
            else speed++;
            pos += speed;
            time++;
        }
        fout << time << endl;
    }

    return 0;

}
