/*
ID: anirudh71
TASK: namenum
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> getNames(string serial, vector<string> dict) {
    
    vector<string> ans;

    unordered_map<char, char> keypad;
    keypad['A'] = keypad['B'] = keypad['C'] = '2';
    keypad['D'] = keypad['E'] = keypad['F'] = '3';
    keypad['G'] = keypad['H'] = keypad['I'] = '4';
    keypad['J'] = keypad['K'] = keypad['L'] = '5';
    keypad['M'] = keypad['N'] = keypad['O'] = '6';
    keypad['P'] = keypad['R'] = keypad['S'] = '7';
    keypad['T'] = keypad['U'] = keypad['V'] = '8';
    keypad['W'] = keypad['X'] = keypad['Y'] = '9';

    vector<string> filteredDict;
    for (string name : dict) {
        if (name.length() == serial.length()) {
            filteredDict.push_back(name);
        }
    }

    for (string name : filteredDict) {
        bool match = true;
        for (int i = 0; i < serial.length(); i++) {
            if (keypad[name[i]] != serial[i]) {
                match = false;
                break;
            }
        }
        if (match) {
            ans.push_back(name);
        }
    }

    return ans;

}

int main() {
    
    ifstream fin("namenum.in");
    ifstream fin2("dict.txt");
    ofstream fout("namenum.out");

    string serial;
    fin >> serial;
    cout << serial << endl;

    vector<string> dict;
    string line;
    while (getline(fin2, line)) {
        dict.push_back(line);
    }

    vector<string> ans = getNames(serial, dict);
    
    if (ans.empty()) {
        fout << "NONE" << endl;
    } else {
        for (string name : ans) {
            fout << name << endl;
        }
    }
    
    return 0;

}