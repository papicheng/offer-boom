#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <climits>

using namespace std;

struct hash_pII {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ hash<int>()(p.second);
    }
};

unordered_map<pair<int, int>, int, hash_pII> m;
int min_road = INT_MAX;

void dfs(int start, int cur_road, int X, int N, vector<int> gone);

int main() {
    int N, P;
    cin >> N >> P;
    for(int i=0; i<P; i++) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        int val;
        cin >> val;
        m[p] = val;
    }
    int X;
    cin >> X;

    vector<int> gone(N, 0);
    dfs(0, 0, X, N, gone);
    cout << min_road << endl;
    return 0;
}

int hasRoad(int i, int j) {
    if(m.find(pair<int, int>(i, j))!=m.end()) {
        return m[pair<int, int>(i, j)];
    }
    if(m.find(pair<int, int>(j, i))!=m.end()) {
        return m[pair<int, int>(j, i)];
    }
    return -1;
}

void dfs(int start, int cur_road, int X, int N, vector<int> gone) {
    if(cur_road > min_road) {
        return;
    }
    if(start == X) {
        min_road = min(cur_road, min_road);
        return;
    }
    for(int i=0; i<N; i++) {
        if(start != i && hasRoad(start, i)>0 && gone[i]==0) {
            gone[i] = 1;
            dfs(i, cur_road+hasRoad(start, i), X, N, gone);
            gone[i] = 0;
        }
    }
    return;
}