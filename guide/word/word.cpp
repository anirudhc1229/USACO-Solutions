/*
ID: anirudh71
TASK: word
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

    ifstream fin("word.in");
    ofstream fout("word.out");

    int N, K;
    fin >> N >> K;
    int count = 0;
    for (int i = 0; i < N; i++) {
        string word;
        fin >> word;
        if (count + word.length() > K) {
            fout << endl;
            count = word.length();
        } else {
            if (i != 0) fout << " ";
            count += word.length();
        }
        fout << word;
    }

    return 0;

}
