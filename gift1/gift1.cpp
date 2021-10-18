/*
ID: anirudh71
TASK: gift1
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

#define LEN(arr) sizeof(arr) / sizeof(arr[0])

using namespace std;

class Person {
public:
    string name;
    int money;
};

int main() {
    
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");

    int numPpl;
    fin >> numPpl;

    Person ppl[numPpl] = {};
    for (int i = 0; i < numPpl; i++) {
        Person p;
        fin >> p.name;
        p.money = 0;
        ppl[i] = p;
    }

    string str;
    while (getline(fin, str)) {

        string giver;
        fin >> giver;
        int amount;
        int splitNum;
        fin >> amount >> splitNum;

        if (splitNum == 0) {
            continue;
        }

        for (int i = 0; i < numPpl; i++) {
            if (ppl[i].name == giver) {
                ppl[i].money -= amount;
                ppl[i].money += amount % splitNum;
            }
        }
        
        for (int i = 0; i < splitNum; i++) {
            string name;
            fin >> name;
            for (int j = 0; j < numPpl; j++) {
                if (ppl[j].name == name) {
                    ppl[j].money += floor(amount / splitNum);
                }
            }
        }

    }

    for (int i = 0; i < numPpl; i++) {
        fout << ppl[i].name << " " << ppl[i].money << endl;
    }
    
    return 0;

}