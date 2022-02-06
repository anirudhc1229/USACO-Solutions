/*
ID: anirudh71
TASK: mixmilk
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Bucket {
    int capacity;
    int amount;
};

int main() {

    ifstream fin("mixmilk.in");
    ofstream fout("mixmilk.out");

    vector<Bucket> buckets(3);
    for (int i = 0; i < 3; i++) {
        int c, a; fin >> c >> a;
        buckets[i] = {c, a};
    }

    for (int i = 0; i < 100; i++) {
        int from = i % 3;
        int to = (i + 1) % 3;
        int pour = min(buckets[from].amount, buckets[to].capacity - buckets[to].amount);
        buckets[from].amount -= pour;
        buckets[to].amount += pour;
    }

    for (Bucket b : buckets) fout << b.amount << endl;

    return 0;

}
