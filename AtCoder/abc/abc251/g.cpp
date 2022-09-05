#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    // dijkstra
    using P = pair<long long, int>;
    const long long inf = 1e18;
    
    vector<vector<P>> G(n); // {cost, to}
    vector<long long> dist(n, inf);
    priority_queue<P, vector<P>, greater<P>> pque;
    
    int start = 0; // start point
    dist[start] = 0;
    pque.push({0, start});
    
    while (!pque.empty()) {
        P p = pque.top();
        pque.pop();
        long long d = p.first; // dist (minなら確定)
        int v = p.second; // point
    
        if (dist[v] < d) continue; // 最短以外は無視 else vは確定
        // ここでreturn 0で出ても良い (見つからなかった場合の処理を忘れない)
    
        for (auto edge : G[v]) { // vに繋がってる点が更新できれば候補に入れる
            long long c = edge.first;
            int nv = edge.second;
    
            if (dist[nv] > dist[v] + c) {
                dist[nv] = dist[v] + c;
                pque.push({dist[nv], nv});
            }
        }
    }
    
    dump(dist);
    return 0;
}