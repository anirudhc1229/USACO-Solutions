/*
ID: anirudh71
TASK: family
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {

    ifstream fin("family.in");
    ofstream fout("family.out");

    int N;
    fin >> N;
    string cow1, cow2;
    fin >> cow1 >> cow2;
    unordered_map<string, string> motherOf;
    unordered_map<string, vector<string>> daughtersOf;
    for (int i = 0; i < N; i++) {
        string mother, daughter;
        fin >> mother >> daughter;
        motherOf[daughter] = mother;
        daughtersOf[mother].push_back(daughter);
    }
    
    string cur;
    string relation;
    bool found;

    // CHECK1
    if (motherOf[cow1] == motherOf[cow2]) {
        fout << "SIBLINGS" << endl;
        return 0;
    }

    // CHECK2
    cur = motherOf[cow1];
    relation = "mother";
    found = false;
    while (cur.length() != 0) {
        if (cur == cow2) {
            found = true;
            break;
        }
        cur = motherOf[cur];
        if (relation == "mother") relation = "grand-" + relation;
        else relation = "great-" + relation;
    }
    if (found) {
        fout << cow2 << " is the " << relation << " of " << cow1 << endl;
        return 0;
    }
    cur = motherOf[cow2];
    relation = "mother";
    found = false;
    while (cur.length() != 0) {
        if (cur == cow1) {
            found = true;
            break;
        }
        cur = motherOf[cur];
        if (relation == "mother") relation = "grand-" + relation;
        else relation = "great-" + relation;
    }
    if (found) {
        fout << cow1 << " is the " << relation << " of " << cow2 << endl;
        return 0;
    }

    // CHECK3
    cur = motherOf[motherOf[cow1]];
    relation = "aunt";
    found = false;
    while (daughtersOf[cur].size() != 0) {
        if (find(daughtersOf[cur].begin(), daughtersOf[cur].end(), cow2) != daughtersOf[cur].end()) {
            found = true;
            break;
        }
        cur = motherOf[cur];
        relation = "great-" + relation;
    }
    if (found) {
        fout << cow2 << " is the " << relation << " of " << cow1 << endl;
        return 0;
    }
    cur = motherOf[motherOf[cow2]];
    relation = "aunt";
    found = false;
    while (daughtersOf[cur].size() != 0) {
        if (find(daughtersOf[cur].begin(), daughtersOf[cur].end(), cow1) != daughtersOf[cur].end()) {
            found = true;
            break;
        }
        cur = motherOf[cur];
        relation = "great-" + relation;
    }
    if (found) {
        fout << cow1 << " is the " << relation << " of " << cow2 << endl;
        return 0;
    }
 
    //CHECK4
    string cur1 = motherOf[cow1];
    string cur2 = motherOf[cow2];
    while (cur1.length() != 0 && cur2.length() != 0) {
        if (cur1 == cur2) {
            fout << "COUSINS" << endl;
            return 0;
        }
        cur1 = motherOf[cur1];
        cur2 = motherOf[cur2];
    }

    fout << "NOT RELATED" << endl;

    return 0;

}
