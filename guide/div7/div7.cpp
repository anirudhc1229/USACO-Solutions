/*
ID: anirudh71
TASK: div7
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("div7.in");
    ofstream fout("div7.out");

    int N;
    fin >> N;
    int cows[N];
    for (int i = 0; i < N; i++) fin >> cows[i];
    
    long long prefix[N];
    prefix[0] = cows[0];
    for (int i = 1; i < N; i++) 
        prefix[i] = prefix[i-1] + cows[i];
    
    int ans = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            long long sum;
            if (i == 0) sum = prefix[j];
            else sum = prefix[j] - prefix[i-1];
            if (sum % 7 == 0) ans = max(ans, j - i + 1);
        }
    }  

    fout << ans << endl;  

    return 0;

}
