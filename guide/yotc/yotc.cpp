/*
ID: anirudh71
TASK: yotc
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

    ifstream fin("yotc.in");
    ofstream fout("yotc.out");

    int N;
    fin >> N;

    map<string, int> zodiac;
    zodiac["Ox"] = 0;
    zodiac["Tiger"] = 1;
    zodiac["Rabbit"] = 2;
    zodiac["Dragon"] = 3;
    zodiac["Snake"] = 4;
    zodiac["Horse"] = 5;
    zodiac["Goat"] = 6;
    zodiac["Monkey"] = 7;
    zodiac["Rooster"] = 8;
    zodiac["Dog"] = 9;
    zodiac["Pig"] = 10;
    zodiac["Rat"] = 11;

    int ans = 0;
    string lastAnimal;
    
    for (int i = 0; i < N; i++) {

        string cur, time, animal, last, s;
        fin >> cur >> s >> s >> time >> animal >> s >> s >> last;
        
        if (time == "previous") {
            if (last == "Bessie") ans += zodiac[animal] - 12;
            else {
                ans += zodiac[animal] - zodiac[lastAnimal];
                if (zodiac[animal] > zodiac[lastAnimal]) ans -= 12;
            }
        }

        if (time == "next") {
            if (last == "Bessie") ans += zodiac[animal] + 12;
            else {
                ans += zodiac[animal] - zodiac[lastAnimal];
                if (zodiac[animal] < zodiac[lastAnimal]) ans += 12;
            }
        }

        if (cur == "Elsie") {
            fout << abs(ans) << endl;
            break;
        }

        lastAnimal = animal;   

    }

    return 0;

}
