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
        dump(siz, par);
    }

    int root(int x) {
        if (par[x] == x) return x;
        par[x] = root(par[x]);
        return par[x];
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
    int n;
    cin >> n;
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    vector<vector<ll>> circles(n);
    for(int i = 0; i < n; i++){
        ll x, y, r;
        cin >> x >> y >> r;
        circles[i] = {x, y, r};
    }
    dump(circles);
    UnionFind tree(n);
    ll s_c, t_c;
    dump("test");
    for(int i = 0; i < n; i++){
        ll x1 = circles[i][0];
        ll y1 = circles[i][1];
        ll r1 = circles[i][2];
        dump(x1, y1, r1, i);
        if ((sx - x1) * (sx - x1) + (sy - y1) * (sy - y1) == r1*r1){
            s_c = i;
        }
        if ((tx - x1) * (tx - x1) + (ty - y1) * (ty - y1) == r1*r1){
            t_c = i;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (i == j) continue;

            ll x1 = circles[i][0];
            ll y1 = circles[i][1];
            ll r1 = circles[i][2];

            ll x2 = circles[j][0];
            ll y2 = circles[j][1];
            ll r2 = circles[j][2];

            if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= (r1 + r2) * (r1 + r2) && (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) >= (r1 - r2) * (r1 - r2)){
                tree.merge(i, j);
                dump(i, j);
            }
        }
    }
    // dump(tree.same(0,3));
    if (tree.same(s_c, t_c)){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}