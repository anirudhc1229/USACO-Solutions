/*
ID: anirudh71
TASK: revegetate
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Cow {
    int fav1;
    int fav2;
};

int getMin(int N) {
    string sMin = "";
    for (int i = 0; i < N; i++) {
        sMin += '1';
    }
    return stoi(sMin);
}

int getMax(int N) {
    string sMax = "";
    for (int i = 0; i < N; i++) {
        sMax += '4';
    }
    return stoi(sMax);
}

int ctoi(char c) {
    return (int)(c - '0');
}

char itoc(int n) {
    return (char)n + '0';
}

void iter(int& grasses, int N) {
    grasses++;
    string sGrasses = to_string(grasses);
    for (int i = N; i > 0; i--) {
        if (ctoi(sGrasses[i-1]) > 4) {
            sGrasses[i-1] = itoc(ctoi(sGrasses[i-1]) % 4); 
            sGrasses[i-2] = itoc(ctoi(sGrasses[i-2]) + 1);
        }
    }
    grasses = stoi(sGrasses);
}

int main() {

    ifstream fin("revegetate.in");
    ofstream fout("revegetate.out");

    int numFields;
    fin >> numFields;
    int numCows;
    fin >> numCows;
    vector<Cow> cows;
    for (int i = 0; i < numCows; i++) {
        Cow c;
        fin >> c.fav1 >> c.fav2;
        cows.push_back(c);
    }

    int ans;
    
    for (int grasses = getMin(numFields); grasses <= getMax(numFields); iter(grasses, numFields)) { 
        string sGrasses = to_string(grasses);
        int valid = true;
        for (int i = 0; i < cows.size() && valid; i++) {
            if (sGrasses[cows[i].fav1 - 1] == sGrasses[cows[i].fav2 - 1]) valid = false; 
        }
        if (valid) {
            ans = grasses;
            break;
        }
    }

    fout << ans << endl;

    return 0;

}
