#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

struct unionfind {
    vector<int> par;
    vector<int> siz;

    unionfind(int sz_) : par(sz_), siz(sz_, 1) {
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    unionfind tree(20000000);
    auto Num = [&](int i, int j) {
        return (i + 2000) * 4000 + (j + 2000);
    };
    auto Coord = [&](int x) {
        return make_pair(x / 4000 - 2000, x % 4000 - 2000);
    };
    dump(Num(1000, 1000));
    dump(Coord(12003000));
    vector<bool> seen(20000000);
    for (int i = 0; i < n; i++) {
        int x_ = x[i], y_ = y[i];
        dump(x_, y_);
        dump(Num(x_ - 1, y_ - 1));
        if (seen[Num(x_ - 1, y_ - 1)]){
            tree.merge(Num(x_ - 1, y_ - 1), Num(x_, y_));
        }
        if (seen[Num(x_ - 1, y_)]){
            tree.merge(Num(x_ - 1, y_), Num(x_, y_));
        }
        if (seen[Num(x_, y_ - 1)]){
            tree.merge(Num(x_, y_ - 1), Num(x_, y_));
        }
        if (seen[Num(x_, y_ + 1)]){
            tree.merge(Num(x_, y_ + 1), Num(x_, y_));
        }
        if (seen[Num(x_ + 1, y_)]){
            tree.merge(Num(x_ + 1, y_), Num(x_, y_));
        }
        if (seen[Num(x_ + 1, y_ + 1)]){
            tree.merge(Num(x_ + 1, y_ + 1), Num(x_, y_));
        }
        seen[Num(x_, y_)] = true;
    }
    set<int> rt;
    for (int i = 0; i < n; i++) {
        rt.insert(tree.root(Num(x[i], y[i])));
        dump(Coord(tree.root(Num(x[i], y[i]))));
    }
    cout << rt.size() << endl;
    return 0;
}