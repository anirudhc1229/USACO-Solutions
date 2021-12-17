/*
ID: anirudh71
TASK: blocks
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {

    ifstream fin("blocks.in");
    ofstream fout("blocks.out");

    int N;
    fin >> N;
    map<char, int> blocks;
    for (int i = 0; i < 26; i++) blocks[(char)(i + 97)] = 0;

    for (int i = 0; i < N; i++) {

        string word1, word2;
        fin >> word1 >> word2;
        map<char, int> inWord1, inWord2;
        for (int i = 0; i < 26; i++) {
            inWord1[(char)(i + 97)] = 0;
            inWord2[(char)(i + 97)] = 0;
        }

        for (int i = 0; i < word1.length(); i++) inWord1[word1[i]]++;
        for (int i = 0; i < word2.length(); i++) inWord2[word2[i]]++;

        for (int i = 0; i < 26; i++) blocks[(char)(i + 97)] += max(inWord1[(char)(i + 97)], inWord2[(char)(i + 97)]);

    }

    for (auto const& pair : blocks) fout << pair.second << endl;

    return 0;

}
