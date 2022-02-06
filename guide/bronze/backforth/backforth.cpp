/*
ID: anirudh71
TASK: backforth
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

unordered_set<int> possible;

void search(vector<int> first, vector<int> second, int day, int gallons) {
    
    if (day == 4) {
        possible.insert(gallons);
        return;
    }
    
    if (day % 2) {
        for (int i = 0; i < second.size(); i++) {
            vector<int> f(first); f.push_back(second[i]);
            vector<int> s(second); s.erase(s.begin() + i);
            search(f, s, day + 1, gallons + second[i]);
        }
    } 
    
    else {
        for (int i = 0; i < first.size(); i++) {
            vector<int> f(first); f.erase(f.begin() + i);
            vector<int> s(second); s.push_back(first[i]);
            search(f, s, day + 1, gallons - first[i]);
        }
    }

}

int main() {

    ifstream fin("backforth.in");
    ofstream fout("backforth.out");

    vector<int> first(10);
    for (int i = 0; i < 10; i++) fin >> first[i];
    vector<int> second(10);
    for (int i = 0; i < 10; i++) fin >> second[i];

    search(first, second, 0, 1000);
    for (int i : possible) cout << i << endl;
    fout << possible.size() << endl;

    return 0;

}
