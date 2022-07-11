/*
ID: anirudh71
TASK: sotv
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
    ifstream fin("sotv.in");
    ofstream fout("sotv.out");

    int n, x; cin >> n >> x;
    vector<int> arr(n);
    unordered_map<int, int> index_of;
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        if (index_of.find(x - arr[i]) != index_of.end()) {
            cout << i + 1 << " " << index_of[x - arr[i]] << endl;
            return 0;
        }
        index_of[arr[i]] = i + 1;
    }

    cout << "IMPOSSIBLE" << endl;

    // sort(arr.begin(), arr.end());
    // int l = 0, r = n - 1;
    // pii ans = {-1, -1};
    // while (l < r) {
    //     int sum = arr[l] + arr[r];
    //     if (sum == x) { ans = {index_of[arr[l]], index_of[arr[r]]}; break; } 
    //     else if (sum < x) l++;
    //     else r--;
    // }

    // if (ans == make_pair(-1, -1)) cout << "IMPOSSIBLE" << endl;
    // else cout << ans.first << " " << ans.second << endl;

    return 0;

}