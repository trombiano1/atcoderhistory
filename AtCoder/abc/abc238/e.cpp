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

struct UnionFind {
    vector<int> par;
    vector<int> siz;

    UnionFind(int sz_) : par(sz_), siz(sz_, 1) {
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
    }

    bool same(int x, int y) {
       return root(x) == root(y);
    }

    int size(int x) {
        return siz[root(x)];
    }
};

int main(void) {
    int n, q;
    cin >> n >> q;
    UnionFind tree(n+1);
    for(int i = 0; i < q; i++){
        ll r, l;
        cin >> l >> r;
        tree.merge(r, l-1);
    }
    if (tree.same(0, n)){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}