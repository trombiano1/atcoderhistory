#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

struct segtree {
    using T = int;
    using M = int;

    const T ex = 0;
    const M em = 0;
    
    T fx(T x1, T x2) {
        return x1 + x2;
    }
    
    T fa(T x, M m) { 
        return m;
    }

    M fm(M m1, M m2) { 
        return m2;
    }

    int n;
    vector<T> node;
    vector<M> lazy;
    
    segtree() : segtree(0) {}
    segtree(int n_): n(), node(n_ * 4, ex), lazy(n_ * 4, em) {
        int x = 1;
        while (n_ > x) x *= 2;
        n = x;
    }
    segtree(vector<T> v){
        int n_ = (int)v.size();
        int x = 1;
        while (n_ > x) x *= 2;
        n = x;
        node.resize(n_ * 4, ex);
        lazy.resize(n_ * 4, em);
        for (int i = 0; i < n_; i++){
            node[i + n - 1] = v[i];
        }
        build();
    }

    // sets tree; O(N)
    void set(int i, T x) { node[i + n - 1] = x; }
    void build() {
        for (int k = n - 2; k >= 0; k--) node[k] = fx(node[2 * k + 1], node[2 * k + 2]);
    }

    // lazy eval
    void eval(int k) {
        if (lazy[k] == em) return;  // 更新するものが無ければ終了
        if (k < n - 1) {            // 葉でなければ子に伝搬
            lazy[k * 2 + 1] = fm(lazy[k * 2 + 1], lazy[k]);
            lazy[k * 2 + 2] = fm(lazy[k * 2 + 2], lazy[k]);
        }
        // 自身を更新
        node[k] = fa(node[k], lazy[k]);
        lazy[k] = em;
    }

    // update [a, b) to x; O(logN)
    void update(int a, int b, M x, int k, int l, int r) {
        eval(k);
        if (a <= l && r <= b) {  // 完全に内側の時
            lazy[k] = fm(lazy[k], x);
            eval(k);
        } else if (a < r && l < b) {                     // 一部区間が被る時
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);  // 左の子
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);  // 右の子
            node[k] = fx(node[k * 2 + 1], node[k * 2 + 2]);
        }
    }
    void update(int a, int b, M x) { update(a, b, x, 0, 0, n); }

    T get_sub(int a, int b, int k, int l, int r) {
        eval(k);
        if (r <= a || b <= l) {  // 完全に外側の時
            return ex;
        } else if (a <= l && r <= b) {  // 完全に内側の時
            return node[k];
        } else {  // 一部区間が被る時
            T vl = get_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = get_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return fx(vl, vr);
        }
    }
    T get(int a){ return get_sub(a, a+1, 0, 0, n); }
    T get(int a, int b) { return get_sub(a, b, 0, 0, n); }
};
#ifdef DEBUG_
// dump. extremely slow; for debug only
ostream &operator<<(ostream &os, const segtree &tree) {
    vector<segtree::T> leaves(tree.n);
    segtree copy = tree;
    for (int i = 0; i < tree.n; i++){
        leaves[i] = copy.get(i);
    }
    os << leaves;
    return os;
}
#else
#endif

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> range(m);
    for (int i = 0; i < m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        l--; r--;
        range[i] = {l, r, x};
    }
    sort(range.begin(), range.end(), [](auto i, auto j){
        return get<1>(i) < get<1>(j);
    });
    segtree tree(n);
    for (int i = 0; i < m; i++) {
        int l = get<0>(range[i]), r = get<1>(range[i]), x = get<2>(range[i]);
        if (tree.get(l, r+1) >= x){
            continue;
        }
        int k = x - tree.get(l, r+1);
        for (int j = r; k > 0; j--){
            dump(k);
            if (tree.get(j) == 0){
                tree.update(j, j + 1, 1);
                k--;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << tree.get(i) << " ";
    }
    cout << endl;
    return 0;
}