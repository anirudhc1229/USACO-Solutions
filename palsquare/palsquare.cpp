/*
ID: anirudh71
TASK: palsquare
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

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

string bToDec(string num_B, int B) {

    int num_10 = 0;
    int power = 1;

    // multiply each digit by B^i, where i is the distance from that digit to the last digit, then sum to get answer
    for (int i = num_B.length() - 1; i >= 0; i--) {
        char digit = num_B[i];
        int trueDigit;
        if (digit <= '9') {
            trueDigit = (int)digit - '0';
        } else {
            trueDigit = (int)digit - 'A' + 10;
        }
        num_10 += trueDigit * power;
        power *= B;
    }

    return to_string(num_10);

}

string square_B(string num_B, int B) {

    string num_10 = bToDec(num_B, B);
    int square_10 = pow(stoi(num_10), 2);
    
    return decToB(square_10, B);
    
}

bool isPalindrome(string num) {

    string backwards(num);
    reverse(backwards.begin(), backwards.end()); 
    
    return num == backwards;

}

int main() {

    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");

    int B;
    fin >> B;

    for (int i_10 = 1; i_10 <= 300; i_10++) {
        string i_B = decToB(i_10, B);
        string square = square_B(i_B, B);
        if (isPalindrome(square)) {
            fout << i_B << " " << square << endl;
        }
    }

    return 0;

}