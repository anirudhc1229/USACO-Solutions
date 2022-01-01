/*
ID: anirudh71
TASK: guess
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Animal {
    string name;
    vector<string> desc;
};

int main() {

    ifstream fin("guess.in");
    ofstream fout("guess.out");

    int N; 
    fin >> N;
    vector<Animal> animals;
    for (int i = 0; i < N; i++) {
        string name; fin >> name;
        int count; fin >> count;
        vector<string> desc(count);
        for (int i = 0; i < count; i++) fin >> desc[i];
        animals.push_back({name, desc});
    }

    int ans = 0; 
    for (Animal i : animals) {
        for (Animal j : animals) {
            if (i.name == j.name) continue;
            map<string, int> descCount;
            for (string s : i.desc) descCount[s]++;
            for (string s : j.desc) descCount[s]++;
            int common = 0;
            for (auto x : descCount) if (x.second > 1) common++;
            ans = max(ans, common);
        }
    }

    fout << ans + 1 << endl;

    return 0;

}
