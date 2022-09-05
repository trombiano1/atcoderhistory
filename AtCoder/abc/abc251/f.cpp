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

    {
        vector<bool> seen(n);
        vector<pair<int, int>> T1;

        function<void(int)> dfs = [&](int v) -> void {
            seen[v] = true;
            for (int nv : G[v]) { 
                if (seen[nv]) continue;
                T1.push_back({v, nv});
                dfs(nv);
            }
        };
        dfs(0);

        for (auto i : T1){
            cout << i.first+1 << " " << i.second+1 << endl;
        }
    }

    {
        // bfs
        vector<pair<int, int>> T2;
        vector<long long> dist(n, -1);
        queue<int> que;
        
        dist[0] = 0;
        que.push(0);
        
        while (!que.empty()) {
            int v = que.front();
            que.pop();
        
            for (int nv : G[v]) {
                if (dist[nv] != -1) continue;

                T2.push_back({v, nv});
                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }
        for (auto i : T2){
            cout << i.first+1 << " " << i.second+1 << endl;
        }
    }
    return 0;
}