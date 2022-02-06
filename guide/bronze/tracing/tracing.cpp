/*
ID: anirudh71
TASK: tracing
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Entry {
    int time;
    int cow1;
    int cow2;
};

int main() {

    ifstream fin("tracing.in");
    ofstream fout("tracing.out");

    int N, T;
    fin >> N >> T;
    vector<bool> infected;
    string s; fin >> s;
    for (int i = 0; i < N; i++) infected.push_back(s[i] != '0');
    vector<Entry> entries;
    for (int i = 0; i < T; i++) {
        int time, cow1, cow2;
        fin >> time >> cow1 >> cow2;
        entries.push_back({time, --cow1, --cow2});
    }

    sort(entries.begin(), entries.end(), 
        [](Entry& a, Entry &b) -> bool {return a.time < b.time;}
    );
    
    int pat0 = 0; 
    int kMin = T; 
    int kMax = 0;
    
    for (int cow = 0; cow < N; cow++) {
        
        if (!infected[cow]) continue;
        vector<bool> kValid;
        
        for (int K = 0; K <= T; K++) {
            
            vector<bool> hypo;
            for (int i = 0; i < N; i++) {
                if (i == cow) hypo.push_back(true);
                else (hypo.push_back(false));
            }

            vector<int> handshakes;
            for (int i = 0; i < N; i++) handshakes.push_back(0);

            for (Entry e : entries) {
                if (hypo[e.cow1] && handshakes[e.cow1] < K) {
                    hypo[e.cow2] = true;
                    handshakes[e.cow1]++;
                }
                if (hypo[e.cow2] && handshakes[e.cow2] < K) {
                    hypo[e.cow1] = true;
                    handshakes[e.cow2]++;
                }
            }

            kValid.push_back(hypo == infected);

        }

        if (find(kValid.begin(), kValid.end(), true) != kValid.end()) {
            pat0++;
            int mini = find(kValid.begin(), kValid.end(), true) - kValid.begin();
            int maxi = kValid.rend() - find(kValid.rbegin(), kValid.rend(), true) - 1;
            kMin = min(kMin, mini);
            kMax = max(kMax, maxi);
        }
    }

    fout << pat0 << " " << kMin << " " << 
        ((kMax == T) ? "Infinity" : to_string(kMax)) 
    << endl;

    return 0;

}
