/*
ID: anirudh71
TASK: censor
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("censor.in");
    ofstream fout("censor.out");

    string s, t;
    fin >> s >> t;
    
    string ans;

    for (int i = 0; i < s.length(); i++) {
        ans += s[i];
        if (ans.length() > t.length() && ans.substr(ans.length() - t.length()) == t) {
            ans.resize(ans.length() - t.length());
        }
    }

    fout << ans << endl;

    return 0;

}
