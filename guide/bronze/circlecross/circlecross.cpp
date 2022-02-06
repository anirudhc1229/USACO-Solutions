/*
ID: anirudh71
TASK: circlecross
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("circlecross.in");
    ofstream fout("circlecross.out");

    string field;
    fin >> field;
    
    vector<char> letters;
    for (int i = 0; i < 26; i++) {
        letters.push_back(static_cast<char>('A' + i));
    }

    int ans = 0;

    for (char a : letters) {
        for (char b : letters) {
            
            if (a == b) continue;

            int findA1 = field.find(a); 
            int findB1 = field.find(b);
            if (findA1 > findB1) continue; 

            int findA2 = field.find(a, findA1 + 1);
            int findB2 = field.find(b, findB1 + 1); 
            if (findA2 > findB2 || findA2 < findB1) continue;
            
            ans++; 
        
        }
    }

    fout << ans << endl;

    return 0;

}
