/*
ID: anirudh71
TASK: dualpal
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string decToB(int num_10, int B) {

    string num_B = "";
    
    // repeatedly divide num_10 by B and add remainder to num_B
    while (num_10 > 0) {
        int digit = num_10 % B;
        char trueDigit;
        if (digit <= 9) {
            trueDigit = (char)(digit + '0');
        } else {
            trueDigit = (char)(digit - 10 + 'A');
        }
        num_B += trueDigit;
        num_10 /= B;
    }

    // when using repeated division method for base conversion, result must be reversed
    reverse(num_B.begin(), num_B.end());

    return num_B;

}

bool isPalindrome(string num) {

    string backwards(num);
    reverse(backwards.begin(), backwards.end()); 
    
    return num == backwards;

}

int main() {

    ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");

    int N;
    fin >> N;
    int S;
    fin >> S;

    int num = S + 1;
    for (int found = 0; found < N; num++) {
        int bases = 0;
        for (int B = 2; B <= 10; B++) {
            if (isPalindrome(decToB(num, B))) bases++;
            if (bases == 2) {
                fout << num << endl;
                found++;
                break;
            }
        }
    }

    return 0;

}