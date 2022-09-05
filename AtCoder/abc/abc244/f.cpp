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
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    const long long inf = 1e18;
    vector dist(pow(2, n), vector<long long>(n, inf));
    queue<pair<int, int>> que;
    
    for (int i = 0; i < n; i++){
        dist[0^(1<<i)][i] = 1;
        que.push({0^(1<<i), i});
    }
    
    while (!que.empty()) {
        pair<int, int> v_pair = que.front();
        int s = v_pair.first;
        int v = v_pair.second;
        dump(bitset<8>(s), v);
        que.pop();
    
        for (long long nv : G[v]) {
            int ns = s^(1<<nv);
            if (dist[ns][nv] != inf) continue;
    
            dist[ns][nv] = dist[s][v] + 1;
            que.push({ns, nv});
        }
    }
    long long res = 0;
    for (int bit = 1; bit < (1<<n); ++bit) {
        long long mn = inf;
        for (int j = 0; j < n; j++){
            mn = min(mn, dist[bit][j]);
        }
        res += mn;
    }
    dump(dist);
    cout << res << endl;
    return 0;
}