/*
ID: anirudh71
TASK: milk2
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define LEN(arr) sizeof(arr) / sizeof(*arr)

using namespace std;

typedef struct {
    int start;
    int end;
} Farmer;

vector<bool> getTimeline(vector<Farmer> farmers) {
    
    vector<bool> timeline;
    
    int maxTime = 0;
    for (Farmer f : farmers) {
        if (f.end > maxTime) {
            maxTime = f.end;
        }
    }
    
    int minTime = maxTime;
    for (Farmer f : farmers) {
        if (f.start < minTime) {
            minTime = f.start;
        }
    }
    
    for (size_t i = minTime; i < maxTime; i++) {
        timeline.push_back(false);
    }
    
    for (Farmer f : farmers) {
        for (size_t j = f.start; j < f.end; j++) {
            timeline[j-minTime] = true; 
        }
    }

    return timeline;

}

int getLongestMilk(vector<bool> timeline) {
    
    int ans = 1, current = 1;
    
    for (int i = 1; i < timeline.size(); i++) {
        if ((timeline[i] == timeline[i-1]) && timeline[i]) current++;
        else current = 1;
        if (current > ans) {
            ans = current;
        }
    }

    if (ans == 1) {
        bool found = false;
        for (bool time : timeline) {
            if (time) {
                found = true;
                break;
            }
        }
        if (!found) {
            ans = 0;
        }
    }

    return ans;

}

int getLongestNoMilk(vector<bool> timeline) {
    
    int ans = 1, current = 1;

    for (int i = 1; i < timeline.size(); i++) {
        if ((timeline[i] == timeline[i-1]) && !timeline[i]) current++;
        else current = 1;
        if (current > ans) {
            ans = current;
        }
    }

    if (ans == 1) {
        bool found = false;
        for (bool time : timeline) {
            if (!time) {
                found = true;
                break;
            }
        }
        if (!found) {
            ans = 0;
        }
    }
    
    return ans;

}

int main() {

    ifstream fin("milk2.in");
    ofstream fout("milk2.out");

    int N;
    fin >> N;
    vector<Farmer> farmers;
    
    for (size_t i = 0; i < N; i++) {
        Farmer f;
        fin >> f.start >> f.end;
        farmers.push_back(f);
    }

    vector<bool> timeline = getTimeline(farmers);

    int longestMilk = getLongestMilk(timeline);
    int longestNoMilk = getLongestNoMilk(timeline);

    fout << longestMilk << " " << longestNoMilk << endl;

    return 0;

}