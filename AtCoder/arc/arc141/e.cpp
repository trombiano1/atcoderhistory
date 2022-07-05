#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1001001001;
#define LINF 1001001001001001001ll;
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
    UnionFind tree(10);
    dump(tree.root(1));
    tree.merge(1,2);
    dump(tree.root(1));
    dump(tree.root(2));
    tree.merge(2, 3);
    dump(tree.size(1));
    return 0;
}