/*
ID: anirudh71
TASK: milk
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("milk.in");
    ofstream fout("milk.out");

    int N;
    fin >> N;
    int M;
    fin >> M;
    vector<int> P;
    vector<int> A;

    for (int i = 0; i < M; i++) {
        int price;
        int amount;
        fin >> price >> amount;
        P.push_back(price);
        A.push_back(amount);
    }

    int needed = N;
    int cost = 0;
    vector<int> prices(P);
    vector<int> amounts(A);

    while (needed > 0) { 
        int best = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < prices[best]) {
                best = i;
            }
        }
        cout << prices[best] << " " << amounts[best] << endl;
        while (needed > 0) { 
            cost += prices[best];
            needed--;
            amounts[best]--;
            if (amounts[best] == 0) { 
                prices.erase(prices.begin() + best);
                amounts.erase(amounts.begin() + best);
                break;
            }
        }
    }

    fout << cost << endl; // NOT REACHING THIS LINE

    return 0;

}
