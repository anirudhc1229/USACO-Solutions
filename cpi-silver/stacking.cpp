/*
ID: anirudh71
TASK: stacking
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int diff[1000001];
int arr[1000001];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("stacking.in");
    ofstream fout("stacking.out");

    int n, k; cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        diff[--a]++;
        diff[b]--;
    }

    int val = 0;
    for (int i = 0; i < n; i++) {
        val += diff[i];
        arr[i] = val;
    }

    sort(arr, arr + n);
    cout << arr[n / 2] << endl;

    return 0;

}