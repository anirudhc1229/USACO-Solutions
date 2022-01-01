/*
ID: anirudh71
TASK: triangles
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Post {
    int x;
    int y;
};

int main() {

    ifstream fin("triangles.in");
    ofstream fout("triangles.out");

    int N;
    fin >> N;
    vector<Post> posts; 
    for (int i = 0; i < N; i++) {
        int x, y; 
        fin >> x >> y;
        posts.push_back({x, y});
    }

    int ans = 0;

    for (int p1 = 0; p1 < N; p1++) {
        for (int p2 = 0; p2 < N; p2++) {
            for (int p3 = 0; p3 < N; p3++) {
                if (posts[p1].y == posts[p2].y && posts[p1].x == posts[p3].x) {
                    int area = abs((posts[p2].x - posts[p1].x) * (posts[p3].y - posts[p1].y));
                    ans = max(ans, area);
                }
            }
        }
    }

    fout << ans << endl;

    return 0;

}
