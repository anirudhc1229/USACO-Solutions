/*
ID: anirudh71
TASK: notlast
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

    ifstream fin("notlast.in");
    ofstream fout("notlast.out");

    int N;
    fin >> N;

    map<string, int> entries;
    entries["Bessie"] = 0;
    entries["Elsie"] = 0;
    entries["Daisy"] = 0;
    entries["Gertie"] = 0;
    entries["Annabelle"] = 0;
    entries["Maggie"] = 0;
    entries["Henrietta"] = 0;

    for (int i = 0; i < N; i++) {
        string name;
        fin >> name;
        int count;
        fin >> count;
        entries[name] = count;
    }

    int min = (*min_element(entries.begin(), entries.end(),
            [](const auto& l, const auto& r) { return l.second < r.second; })).second;

    auto it = entries.begin();
    while (it != entries.end()) {
        if (it->second == min) it = entries.erase(it);
        else it++;
    }

    int min2 = (*min_element(entries.begin(), entries.end(),
            [](const auto& l, const auto& r) { return l.second < r.second; })).second;

    vector<string> secondSmallest;
    it = entries.begin();
    while (it != entries.end()) {
        if (it->second == min2) secondSmallest.push_back(it->first);
        it++;
    }

    if (secondSmallest.size() == 1) fout << secondSmallest[0];
    else fout << "Tie";
    fout << endl;

    return 0;

}
