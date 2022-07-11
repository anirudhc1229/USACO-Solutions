/*
ID: anirudh71
TASK: triangles
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<pii> posts;
int sumx[2001][2001];
int sumy[2001][2001];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("triangles.in");
    ofstream fout("triangles.out");

    cin >> n;
    posts.resize(n);
    for (pii& p : posts) cin >> p.first >> p.second;
    sort(posts.begin(), posts.end());

    for (int i = 0; i < n; i++) {
        int j = i + 1;
        while (posts[j].first == posts[i].first) {
            
        }
    }

    return 0;

}