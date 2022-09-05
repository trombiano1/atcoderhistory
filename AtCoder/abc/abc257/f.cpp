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
    vector<vector<int>> G(n);
    vector<int> Add;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (u == -1){
            Add.push_back(v);
        } else {
            G[u].push_back(v);
            G[v].push_back(u);
        }
    }
    dump(G, Add);

    const long long inf = 1e18;
    vector<long long> dist_from_min(n, inf);
    queue<int> que;
    dist_from_min[0] = 0;
    que.push(0);
    
    while (!que.empty()) {
        int v = que.front();
        que.pop();
    
        for (long long nv : G[v]) {
            if (dist_from_min[nv] != inf) continue;
    
            dist_from_min[nv] = dist_from_min[v] + 1;
            que.push(nv);
        }
    }

    vector<long long> dist_from_max(n, inf);
    dist_from_max[n-1] = 0;
    que.push(n-1);
    
    while (!que.empty()) {
        int v = que.front();
        que.pop();
    
        for (long long nv : G[v]) {
            if (dist_from_max[nv] != inf) continue;
    
            dist_from_max[nv] = dist_from_max[v] + 1;
            que.push(nv);
        }
    }
    long long cost0 = inf, costn = inf;
    for (auto t: Add){
        cost0 = min(cost0, dist_from_min[t]);
        costn = min(costn, dist_from_max[t]);
    }
    dump(cost0, costn);
    dump(dist_from_min, dist_from_max);

    for (int i = 0; i < n; i++){
        vector<long long> res;
        res.push_back(cost0+costn+2);
        res.push_back(dist_from_min[n-1]);
        if (dist_from_max[i] != inf){
            res.push_back(dist_from_max[i]+cost0+1);
        }
        if (dist_from_min[i] != inf){
            res.push_back(dist_from_min[i]+costn+1);
        }
        sort(res.begin(), res.end());
        dump(res);
        cout << (res[0] != inf ? res[0] : -1) << " ";
    }
    cout << endl;
    return 0;
}