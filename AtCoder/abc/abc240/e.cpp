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

vector<bool> seen;
vector<vector<int>> G;
vector<pair<ll, ll>> res;

ll c = 0;

void dfs(int v, int frm) {
    dump(v, c);
    seen[v] = true;
    // global_array[v] = global_val;
    ll l = c+1;
    bool leaf = true;
    for (auto nv : G[v]) { 
        if (nv == frm) continue;
        leaf = false;
        dfs(nv, v);
    }
    if (leaf){
        c++;
        res[v] = {c, c};
    } else {
        res[v] = {l, c};
    }
}

int main(void) {
    int n;
    cin >> n;
    G.resize(n);
    seen.resize(n);
    res.resize(n);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dump(G);
    dfs(0, -1);
    dump(res);
    for(int i = 0; i < n; i++){
        cout << res[i].first << " " << res[i].second << endl;
    }
    return 0;
}