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
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    for (int i = 0; i < n; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> par(n);
    vector<bool> used(n);
    vector<bool> closed(n);

    int f, s;
    function<void(int, int)> Dfs = [&](int x,int y){
        par[x] = y;
        used[x] = 1;
        for(int to : G[x]){
            if (to == y) continue;
            if (used[to] == 1) {
                // revisit
                s = x;
                f = to;
                return;
            }
            Dfs(to,x);
        }
    };
    Dfs(1, -1);
    swap(f, s);

    // 閉路を辿る
    while (s!=f) {
        closed[s] = true;
        s = par[s];
    }
    closed[f] = true;
    
    vector<int> ans(n);
    function<void(int, int, int)> Dfs2 = [&](int x, int p, int par){
        ans[x] = par;
        for(int to : G[x]){
            if(to == p)continue;
            if(!closed[to]) Dfs2(to, x, par);
        }
    };
    for (int i = 0; i < n; i++){
        if (closed[i]){
            Dfs2(i, -1, i);
        }
    }
    dump(ans);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        if (ans[x] == ans[y]){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}