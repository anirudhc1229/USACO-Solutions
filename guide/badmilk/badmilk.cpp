/*
ID: anirudh71
TASK: badmilk
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Person {
    int id;
    vector<int> milks;
    vector<int> times;
    int sick;
};

int main() {

    ifstream fin("badmilk.in");
    ofstream fout("badmilk.out");

    int N, M, D, S;
    fin >> N >> M >> D >> S;
    
    vector<Person> people;
    for (int i = 0; i < D; i++) {
        int p, m, t;
        fin >> p >> m >> t;
        bool exists = false;
        for (Person pers : people) {
            if (pers.id == p) {
                exists = true;
                pers.milks.push_back(m);
                pers.times.push_back(t);
            }
        }
        if (!exists) {
            Person pers;
            pers.id = p;
            pers.milks.push_back(m);
            pers.times.push_back(t);
            pers.sick = -1;
            people.push_back(pers);
        }
    }

    for (int i = 0; i < S; i++) {
        int p, t;
        fin >> p >> t;
        for (Person pers : people) {
            if (pers.id == p) pers.sick = t;
        }
    }
    
    vector<Person> sickPpl;
    for (Person pers : people) {
        if (pers.sick != -1) sickPpl.push_back(pers);
    }

    int ans = 0;

    for (int milk = 1; milk <= M; milk++) {

        bool allSickDrank = true;
        for (Person pers : sickPpl) {
            if (find(pers.milks.begin(), pers.milks.end(), milk) == pers.milks.end()) {
                allSickDrank = false;
                break;
            }
        }

        if (!allSickDrank) continue;

        bool allSickAfter = true;
        for (Person pers : sickPpl) {
            int lastTimeDrank = 0;
            for (int i = 0; i < pers.milks.size(); i++) {
                if (pers.milks[i] == milk && pers.times[i] > lastTimeDrank) {
                    lastTimeDrank = pers.times[i];
                }
            }
            if (pers.sick <= lastTimeDrank) {
                allSickAfter = false;
                break;
            }
        }

        if (!allSickAfter) continue;

        int numDrank = 0;        
        for (Person pers : people) {
            for (int m : pers.milks) {
                if (m == milk) numDrank++;
            }
        }

        ans = max(ans, numDrank); 

    }

    fout << ans << endl;

    return 0;

}
