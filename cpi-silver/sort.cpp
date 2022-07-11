/*
ID: anirudh71
TASK: sort
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int n;
int arr[100001];
int sorted[100001];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("sort.in");
    ofstream fout("sort.out");

    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    copy(arr, arr + n, sorted);
    sort(sorted, sorted + n);
    unordered_map<int, int> indices;
    for (int i = 0; i < n; i++)
        indices[sorted[i]] = i;

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, i - indices[arr[i]]);
    cout << ans + 1 << endl;

    return 0;

}