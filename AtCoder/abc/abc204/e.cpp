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
    const long long inf = 1e18;
    int n, m;
    cin >> n >> m;
    vector<long long> c(m);
    vector<long long> d(m);
    vector<vector<pair<int, int>>> G(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b >> c[i] >> d[i];
        a--; b--;
        G[a].push_back({b, i}); // to, num
        G[b].push_back({a, i});
    }
    // dijkstra
    using P = pair<long long, int>;
    
    vector<long long> arrival(n, inf);
    priority_queue<P, vector<P>, greater<P>> pque;
    
    int start = 0; // start point
    arrival[start] = 0;
    pque.push({0, start});
    
    while (!pque.empty()) {
        P p = pque.top();
        pque.pop();
        long long t = p.first; // arrival (minなら確定)
        int v = p.second; // point
    
        if (arrival[v] < t){
            continue; // 最短以外は無視 else vは確定
        }
        // ここでreturn 0で出ても良い (見つからなかった場合の処理を忘れない)
    
        for (auto edge : G[v]) { // vに繋がってる点が更新できれば候補に入れる
            int nv = edge.first;
            long long nc = c[edge.second];
            long long nd = d[edge.second];
            
            long long mn = inf;
            long long sr = sqrt((double)nd);
            for (long long i = max(sr - (t + 1) - 4, 0ll);; i++) {
                long long dur;
                if (i + t + 1 <= 0){
                    continue;
                }
                dur = i + nc + nd / (i + t + 1);
                dump(dur, mn);
                if (dur > mn) {
                    break;
                }
                mn = min(mn, dur);
            }
            dump(mn);

            if (arrival[nv] > arrival[v] + mn) {
                arrival[nv] = arrival[v] + mn;
                pque.push({arrival[nv], nv});
            }
        }
    }
    
    dump(arrival);
    cout << (arrival[n - 1] != inf ? arrival[n - 1] : -1) << endl;

    return 0;
}