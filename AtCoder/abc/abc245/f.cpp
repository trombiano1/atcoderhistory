#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e9
#define LINF 100000000000000000LL
#define all(x) begin(x), end(x)

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

ll n, m;
vector<vector<int>> G;
vector<bool> seen, ok;

bool dfs(int v) {
    dump(v);
    seen[v] = true;
    if (ok[v] == true) return true;

    ok[v] = true;

    bool returnflag = false;

    for (auto nv : G[v]) {
        if (ok[nv]) return true;
        if (seen[nv]){
            
        } else if (dfs(nv)){
            returnflag = true;
        }
    }
    dump(v, returnflag);
    ok[v] = returnflag;
    return returnflag;
}

int main(void) {
    cin >> n >> m;
    G.resize(n);
    seen.resize(n);
    ok.resize(n, false);
    for(int i = 0; i < m; i++){
        ll u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
    }
    dump(G);
    for(int i = 0; i < n; i++){
        if (!seen[i]){
            dfs(i);
        }
    }
    dump(ok, seen);
    ll res = 0;
    for(int i = 0; i < n; i++){
        if (ok[i]) res++;
    }
    cout << res << endl;
    return 0;
}