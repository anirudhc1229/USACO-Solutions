/*
ID: anirudh71
TASK: skidesign
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

    ifstream fin("skidesign.in");
    ofstream fout("skidesign.out");

    int N;
    fin >> N;
    vector<int> hills;
    for (int num; fin >> num;) hills.push_back(num);

    vector<int> costs;
    
    for (int lb = 0; lb <= 83; lb++) {
        int ub = lb + 17;
        int cost = 0;
        for (int hill : hills) {
            if (hill > ub) cost += pow(ub - hill, 2);
            else if (hill < lb) cost += pow(hill - lb, 2);
        }
        costs.push_back(cost);
    }

    fout << *min_element(costs.begin(), costs.end()) << endl;

    return 0;

}
