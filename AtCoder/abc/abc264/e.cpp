#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

vector<bool> g;

struct UnionFind {
    vector<int> par;
    vector<int> siz;

    UnionFind(int sz_) : par(sz_), siz(sz_, 0) {
        for(int i = 0; i < sz_; i++) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void merge(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        if (siz[rx] < siz[ry]) swap(rx, ry); // 小を大にくっつける(ry<rx)
        siz[rx] += siz[ry];
        par[ry] = rx;
        if (g[rx] || g[ry]){
            g[rx] = 1;
        }
    }

    bool same(int x, int y) {
       return root(x) == root(y);
    }

    int size(int x) {
        return siz[root(x)];
    }
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, e;
    cin >> n >> m >> e;
    g.resize(n+m);
    for (int i = n; i < n+m; i++){
        g[i] = true;
    }
    vector<pair<int, int>> E(e);
    for (int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        E[i] = {u, v};
    }
    int q;
    cin >> q;
    vector<bool> x(e, false);
    vector<int> x_in(q);
    for (int i = 0; i < q; i++){
        int x_;
        cin >> x_;
        x_--;
        x_in[i] = x_;
        x[x_] = true;
    }
    
    UnionFind tree(n+m);
    for (int i = 0; i < n; i++){
        tree.siz[i] = 1;
    }

    for (int i = 0; i < e; i++){
        if (!x[i]){
            tree.merge(E[i].first, E[i].second);
        }
    }
    long long res = 0;
    for (int i = 0; i < n; i++){
        if (g[tree.root(i)]){
            res++;
        }
    }
    vector<int> result;
    result.push_back(res);
    for (int i = q-1; i > 0; i--){
        pair<int, int> edge = E[x_in[i]];
        bool first_g, second_g;
        int first_sz, second_sz;
        first_g = g[tree.root(edge.first)];
        second_g = g[tree.root(edge.second)];
        first_sz = tree.siz[tree.root(edge.first)];
        second_sz = tree.siz[tree.root(edge.second)];

        tree.merge(edge.first, edge.second);

        if (g[tree.root(edge.first)]){
            if (!first_g){
                res += first_sz;
            }
            if (!second_g){
                res += second_sz;
            }
        }
        dump(first_g, second_g, edge);
        result.push_back(res);
    }
    dump(result);
    for (int i = q-1; i >= 0; i--){
        cout << result[i] << endl;
    }
    return 0;
}