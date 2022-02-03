/*
ID: anirudh71
TASK: cowphabet
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

    ifstream fin("cowphabet.in");
    ofstream fout("cowphabet.out");

    string cowphabet, word;
    cin >> cowphabet >> word;

    int count = 0;
    while (word != "") {
        count++;
        for (int i = 0; i < 26; i++) {
            if (cowphabet[i] == word[0])
                word.erase(0, 1);
            if (word == "") break;
        }
    }

    cout << count << endl;

    return 0;

}
