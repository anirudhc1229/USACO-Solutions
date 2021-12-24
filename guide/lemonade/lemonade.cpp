/*
ID: anirudh71
TASK: lemonade
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("lemonade.in");
    ofstream fout("lemonade.out");

    int N;
    fin >> N;
    vector<int> cows(N);
    for (int i = 0; i < N; i++) fin >> cows[i];

    sort(cows.begin(), cows.end(), greater<int>());
    vector<int> line;
    
    for (int cow : cows) {
        if (cow >= line.size()) line.push_back(cow);
    }

    fout << line.size() << endl;

    return 0;

}
