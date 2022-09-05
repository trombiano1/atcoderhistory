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
    vector<vector<pair<int, int>>> G(n); // to, #
    for (int i = 0; i < m; i++){
        int s, t;
        cin >> s >> t;
        s--; t--;
        G[s].push_back({t, i});
    }

    map<int, bool> shortest;
    int mindist = -1;
    {
        vector<int> pre(n, -1);
        vector<long long> dist(n, -1);
        vector<vector<int>> paths(n);
        queue<int> que;
        
        dist[0] = 0;
        que.push(0);
        
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            if (v == n - 1){
                mindist = dist[v];
                break;
            }
        
            for (auto edge : G[v]) {
                int nv = edge.first;
                if (dist[nv] != -1) continue;

                auto current_path = paths[v];
                current_path.push_back(edge.second);
                
                dist[nv] = dist[v] + 1;
                paths[nv] = current_path;
                que.push(nv);
            }
        }
        
        for (auto v : paths[n - 1]) {
            shortest[v] = true;
        }
    }
    dump(shortest, mindist);

    for (int i = 0; i < m; i++){
        if (!shortest[i]){
            cout << mindist << endl;
            continue;
        }

        vector<long long> dist(n, -1);
        queue<int> que;
        
        dist[0] = 0;
        que.push(0);

        
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            if (v == n - 1){
                break;
            }
        
            for (auto edge : G[v]) {
                int nv = edge.first;
                int e = edge.second;
                if (e == i) {
                    continue;
                }
                if (dist[nv] != -1) {
                    continue;
                }
        
                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }
        cout << dist[n-1] << endl;
    }
    return 0;
}