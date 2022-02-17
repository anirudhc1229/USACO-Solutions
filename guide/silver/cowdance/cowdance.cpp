/*
ID: anirudh71
TASK: cowdance
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int N, T;
vector<int> cows;

bool check(int k) {
    int time = 0;
    priority_queue<int, vector<int>, greater<int>> stage;
    for (int c : cows) {
        if (stage.size() == k) {
            time = stage.top();
            stage.pop();
        }
        if (time + c > T) return false;
        stage.push(time + c);
    }
    return true;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("cowdance.in");
    ofstream fout("cowdance.out");

    fin >> N >> T;
    cows.resize(N);
    for (int& c : cows) fin >> c;

    int lo = 1, hi = N; 
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) hi = mid; 
        else lo = mid + 1;
    }

    fout << lo << endl;

    return 0;

}
