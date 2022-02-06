/*
ID: anirudh71
TASK: geteven
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<char, vector<int>> var2val;
vector<int> values;
int ans = 0;

char next(char c) {
    string letters = "BESIGOM";
    for (int i = 0; i < 6; i++)
        if (letters[i] == c) 
            return letters[i+1];
    return '0';
}

void solve(char c) {
    if (c == '0') {
        int expression = (values[0] + values[1] + values[2] + values[2] + values[3] + values[1])
            * (values[4] + values[5] + values[1] + values[2])
            * (values[6] + values[5] * values[5]);
        for (int v : values) cout << v << " "; cout << endl; 
        cout << expression << endl;
        if (expression % 2) {
            cout << "YES" << endl;
            ans++;
        } else {
            cout << "NO" << endl;
        }
    }
    for (int v : var2val[c]) {
        values.push_back(v);
        solve(next(c));
        values.pop_back();
    }
}

int main() {

    ifstream fin("geteven.in");
    ofstream fout("geteven.out");

    int N;
    fin >> N;
    for (int i = 0; i < N; i++) {
        char c;
        fin >> c;
        int v;
        fin >> v;
        var2val[c].push_back(v);
    }

    solve('B');

    fout << ans << endl;

    return 0;

}
