/*
ID: anirudh71
TASK: crypt1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Config 
{ 
    int num1;
    int num2;
    int pp1;
    int pp2;
    int ans;

    public:
    
        Config(int num1, int num2) {
            this->num1 = num1;
            this->num2 = num2;
            pp1 = getPp1();
            pp2 = getPp2();
            ans = num1 * num2;
        }

        int getPp1() { 
            int onesPlace = to_string(num2)[1] - '0';
            return num1 * onesPlace;
        }

        int getPp2() { 
            int tensPlace = to_string(num2)[0] - '0';
            return num1 * tensPlace;
        }

        bool isValid(vector<int> digits) {
            
            if (to_string(pp1).length() != 3) return false;
            if (to_string(pp2).length() != 3) return false;
            if (to_string(ans).length() != 4) return false;

            vector<int> allNums{num1, num2, pp1, pp2, ans};
            for (int num : allNums) {
                string snum = to_string(num);
                for (size_t i = 0; i < snum.length(); i++) {
                    int digit = snum[i] - '0';
                    if (find(digits.begin(), digits.end(), digit) == digits.end()) return false;
                }
            }

            return true;

        }

};

int main() {

    // get all possible configurations that follow given multiplication rules
        // eliminate configurations as you go
    // return number of those configurations that include only given digits
    
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");

    int N;
    fin >> N;
    vector<int> digits;
    for (int digit; fin >> digit;) digits.push_back(digit);

    int ans = 0;

    for (int num1 = 100; num1 <= 999; num1++) {
        for (int num2 = 10; num2 <= 99; num2++) {
            Config c(num1, num2);
            if (c.isValid(digits)) ans++;
        }
    }

    fout << ans << endl;

    return 0;

}
