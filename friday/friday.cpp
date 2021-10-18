/*
ID: anirudh71
TASK: friday
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>

#define LEN(arr) sizeof(arr) / sizeof(arr[0])

using namespace std;

int getDays(int month, int year) {

    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }

    if (month == 2) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 29;
            }
            return 28;
        }
        if (year % 4 == 0) {
            return 29;
        }
        return 28;
    }

    return 31;

}

int main() {
    
    ifstream fin("friday.in");
    ofstream fout("friday.out");
    
    int N;
    fin >> N;
    int start = 1900;
    int weekday = 3;
    int counts[7] = {};
    for (int i = 0; i < 7; i++) {
        counts[i] = 0;
    }
    
    for (int year = start; year < start + N; year++) {
        for (int month = 1; month <= 12; month++) {
            for (int day = 1; day <= getDays(month, year); day++) {
                if (day == 13) {
                    counts[weekday-1]++;
                }
                (weekday %= 7)++;
            }
        }
    }

    for (int i = 0; i < LEN(counts); i++) {
        string output = to_string(counts[i]);
        if (i < LEN(counts) - 1) {
            output += " ";
        }
        fout << output;
    }
    fout << endl;
    
    return 0;

}