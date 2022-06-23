/*
ID: anirudh71
TASK: 3
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

ll M, N, K;
vector<ll> emails;

bool lowerInFuture(ll start, ll bound) { // binary search?
    for (ll i = start; i < N; i++)
        if (emails[i] < bound) return true;
    return false;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("3.in");
    ofstream fout("3.out");

    ll T; fin >> T;
    for (ll t = 0; t < T; t++) {

        fin >> M >> N >> K;
        emails.resize(N);
        for (ll& e : emails) fin >> e;
        // if (t == 4) for (ll e : emails) cout << e << " ";
        
        ll eLo = 0, eHi = K - 1, fLo = 0, fHi = K - 1;
        priority_queue<ll> cur;
        for (ll i = eLo; i <= eHi; i++) cur.push(-emails[i]);
        stack<ll> skipped;
        
        while (eLo < N) { // first time through
            
            ll lowest = -cur.top();
            // place it if possible
            // if not: 
                // if any later email is less than hypothetical lower bound if you scroll folders, then skip current email and add to stack
                // hypothetical lower bound = current email - K?
                // if none are, then you can scroll folders and place current email
            if (lowest > fHi) {
                if (lowerInFuture(eLo + 1, lowest - K)) {
                    skipped.push(lowest);
                }
                else {
                    fLo = lowest - K;
                    fHi = lowest;
                }
            }

            cur.pop();
            eLo++;
            eHi++;
            cur.push(-emails[min(eHi, N-1)]);

        }

        // pop all stack emails one by one and attempt to assign
        // YES if all get assigned, else NO
        bool good = true;
        while (!skipped.empty()) {
            ll s = skipped.top();
            skipped.pop();
            if (s < fLo || s > fHi) {
                good = false;
                break;
            }
        }
        
        if (good) fout << "YES" << endl;
        else fout << "NO" << endl;

    }

    return 0;

}
