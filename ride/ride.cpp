/*
ID: anirudh71
TASK: ride
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    
    ifstream fin("ride.in");
    ofstream fout("ride.out");
    
    string comet;
    string group;
    fin >> comet >> group;
    
    int cometProduct = 1;
    for (int i = 0; i < comet.length(); i++) {
        cometProduct *= (int)comet[i] - 64;
    }
    int groupProduct = 1;
    for (int i = 0; i < group.length(); i++) {
        groupProduct *= (int)group[i] - 64;
    }
    
    if (cometProduct % 47 == groupProduct % 47) {
        fout << "GO" << endl;
    } else  {
        fout << "STAY" << endl;
    }
    
    return 0;

}