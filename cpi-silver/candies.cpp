/*
ID: anirudh71
TASK: candies
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int T, n, q;
int arr[200001];
int single[200001];
int multi[200001];

void compute_prefix() {
    single[0] = 0;
    for (int i = 1; i < n; i++)
        single[i] = single[i - 1] + arr[i] * (i % 2 ? 1 : -1);
    multi[0] = 0;
    for (int i = 1; i < n; i++)
        multi[i] = multi[i - 1] + arr[i] * (i % 2 ? 1 : -1) * i;
    cout << "single: ";
    for (int i = 0; i < n; i++) cout << single[i] << " "; cout << endl;
    cout << "multi: ";
    for (int i = 0; i < n; i++) cout << multi[i] << " "; cout << endl;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("candies.in");
    ofstream fout("candies.out");

    cin >> T;
    for (int t = 0; t < T; t++) {

        cin >> n >> q;
        for (int i = 0; i < n; i++) 
            cin >> arr[i];
        compute_prefix();

        int total = 0;
        for (int i = 0; i < q; i++) {
            char c; cin >> c;
            int a, b; cin >> a >> b;
            if (c == 'Q') {
                cout << a << " " << b << ": " << (a % 2 ? 1 : -1) * (multi[b] - multi[a - 1] - (a - 1) * (single[b] - single[a - 1])) << endl;
                total += (a % 2 ? 1 : -1) * (multi[b] - multi[a - 1] - (a - 1) * (single[b] - single[a - 1]));
            } else {
                arr[a - 1] = b;
                compute_prefix();
            }
        }

        cout << "Case #" << (t + 1) << ": " << total << endl;    
    
    }

    return 0;

}