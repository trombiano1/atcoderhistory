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
    int s, t, m;
    cin >> s >> t >> m;
    vector<vector<int>> G(s);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        v -= s;
        G[u].push_back(v);
    }
    vector<vector<int>> mx(t, vector<int>(t, -1));
    dump(G);
    dump(mx);
    for (int z = 0; z < s; z++){
        for (auto x: G[z]){
            for (auto y : G[z]){
                if (x == y) continue;
                if (mx[x][y] != -1){
                    cout << mx[x][y]+1 << " " << z+1 << " " << x+s+1 << " " << y+s+1 << endl;
                    return 0;
                }
                mx[x][y] = z;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}