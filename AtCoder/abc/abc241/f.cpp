#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

const int inf = 2e9;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w, n;
    cin >> h >> w >> n;
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    sx--; sy--; gx--; gy--;
    vector<map<int, vector<int>>> mp(2); // v, h
    for (int k = 0; k < n; k++){
        int i, j;
        cin >> i >> j;
        i--; j--;
        mp[0][i].push_back(j); // h
        mp[1][j].push_back(i); // v
    }
    for (int j = 0; j < 2; j++){
        for (auto &i : mp[j]){
            i.second.push_back(-inf);
            i.second.push_back(inf);
            sort(i.second.begin(), i.second.end());
        }
    }
    dump(mp[0]);

    // dijkstra
    using P = pair<long long, pair<int, int>>;

    // vector dist(n, inf);
    map<pair<int, int>, long long> dist;
    priority_queue<P, vector<P>, greater<P>> pque;
    
    pair<int, int> start = {sx, sy}; // start point
    dist[start] = 0;
    pque.push({0, start});
    
    while (!pque.empty()) {
        P p = pque.top();
        pque.pop();
        long long d = p.first; // dist (minなら確定)
        auto v = p.second; // point (x, y)
        int i = v.first;
        int j = v.second;

        dump(v);
    
        if (dist[v] < d && dist[v] != 0){
            continue; // 最短以外は無視 else vは確定
        }
        // ここでreturn 0で出ても良い (見つからなかった場合の処理を忘れない)
        if (v.first == gx && v.second == gy){
            cout << dist[v] << endl;
            return 0;
        }
        
        vector<pair<int, int>> dest;
        // v
        // vertical
        if ((int)mp[1][j].size() != 0){
            dest.push_back({*prev(lower_bound(mp[1][j].begin(), mp[1][j].end(), i))+1, j});
            dest.push_back({*lower_bound(mp[1][j].begin(), mp[1][j].end(), i)-1, j});
        }
        
        // horizontal
        if ((int)mp[0][i].size() != 0){
            dest.push_back({i, *prev(lower_bound(mp[0][i].begin(), mp[0][i].end(), j))+1});
            dest.push_back({i, *lower_bound(mp[0][i].begin(), mp[0][i].end(), j)-1});
        }



        for (auto nv : dest) { // vに繋がってる点が更新できれば候補に入れる
            // dump(nv);
            if (nv.first < 0 || nv.second < 0){
                continue;
            }
            if (nv.first >= h || nv.second >= w){
                continue;
            }
            if (nv == v){
                continue;
            }
            if (dist[nv] > dist[v] + 1 || dist[nv] == 0) {
                dist[nv] = dist[v] + 1;
                pque.push({dist[nv], nv});
            }
        }
    }
    // dump(dist);
    cout << -1 << endl;
    return 0;
}