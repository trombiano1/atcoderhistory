#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

vector<int> c;

struct UnionFind {
    vector<int> par;
    vector<int> siz;
    vector<map<int, int>> mp;

    UnionFind(int sz_) : par(sz_), siz(sz_, 1) {
        mp.resize(sz_);
        for(int i = 0; i < sz_; i++){
            par[i] = i;
            mp[i][c[i]] = 1;
        }
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
        for (auto i : mp[ry]){
            mp[rx][i.first] += i.second;
        }
        // mp[rx].insert(mp[ry].begin(), mp[ry].end());
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
    int n, q;
    cin >> n >> q;
    c.resize(n);
    for(int i = 0; i < n; i++){
        cin >> c[i];
        c[i]--;
    }
    UnionFind tree(n);
    for(int i = 0; i < q; i++){
        int t;
        cin >> t;
        if (t == 1){
            long long a, b;
            cin >> a >> b;
            a--; b--;
            tree.merge(a, b);
        } else {
            long long x, y;
            cin >> x >> y;
            x--; y--;
            cout << tree.mp[tree.root(x)][y] << endl;
        }
    }
    return 0;
}