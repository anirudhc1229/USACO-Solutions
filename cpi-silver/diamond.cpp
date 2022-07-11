/*
ID: anirudh71
TASK: diamond
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int n, k;
int arr[50001];
int sizes[50001];
int max_after[50001];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("diamond.in");
    ofstream fout("diamond.out");

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
        for (int j = i; j < n && arr[j] - arr[i] <= k; j++) 
            sizes[i]++;

    max_after[n] = 0;
    for (int i = n - 1; i >= 0; i--)
        max_after[i] = max(sizes[i], max_after[i + 1]);

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, sizes[i] + max_after[i + sizes[i]]);

    cout << ans << endl;

    return 0;

}