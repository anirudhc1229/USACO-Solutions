/*
ID: anirudh71
TASK: max_subarray
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("max_subarray.in");
    ofstream fout("max_subarray.out");

    int n; cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    ll local_max = 0, global_max = INT_MIN;
    for (int i = 0; i < n; i++) {
        local_max = max(arr[i], local_max + arr[i]);
        global_max = max(global_max, local_max);
    }

    cout << global_max << endl;

    return 0;

}