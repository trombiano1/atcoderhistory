#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

template <typename T>
struct SegTree { // Lazy Seg Tree
    vector<T> dat, lazy;
    long long n, size;
    T def;

    // defines function.
    // make sure fx(x, def) = x (モノイド)
    //   ex. min(INF, INF) = INF, min(x, INF) = x
    //       max(-INF, INF) = INF, max(x, INF) = x
    //       lcm(1, 1) = 1, lcm(1, a) = a
    //       gcf(全ての数の倍数, a) = a
    //           fxでINFが来たら相手になるように実装

    T fx(T a, T b){
        return (a + b);
    }

    // 木の構築. 全てをdefにセット.
    SegTree(int N, T def_) : dat(2*pow(2,ceil(log2(N)))-1), lazy(2*pow(2,ceil(log2(N)))-1) {
        n = pow(2,ceil(log2(N)));
        size = 2 * n - 1;
        def = def_;
        for (size_t i = 0; i < dat.size(); i++){
            dat[i] = def;
            lazy[i] = def;
        }
    }

    // [a, b)の区間をxにセット. 
    void update(int a, int b, T x, int k, int l, int r){
        eval(k);
        if (a <= l && r <= b){
            lazy[k] = x;
            eval(k);
        } else if (a < r && l < b){
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);
            dat[k] = fx(dat[k * 2 + 1], dat[k * 2 +  2]);
        }
    }
    void update(int a, int b, T x) { update(a, b, x, 0, 0, n); }
    void update(int a, T x) { update(a, a+1, x, 0, 0, n); }
    
    // 遅延評価用. 
    void eval(int k) { // 配列のk番目を更新
        if (lazy[k] == def) return; // 更新するものがなければ終了
        if (k < n-1){ // 葉でなければ子に伝搬
            lazy[k*2 + 1] = lazy[k];
            lazy[k*2 + 2] = lazy[k];
        }
        // update self
        dat[k] = lazy[k];
        lazy[k] = def;
    }

    // [a, b)のfxを返す.
    T query(int a, int b){ return query_sub(a, b, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r){
        eval(k);
        if(b <= l || r <= a) return def;
        if(a <= l && r <= b) return dat[k];
        T vl = query_sub(a, b, 2*k+1, l, (l+r)/2);
        T vr = query_sub(a, b, 2*k+2, (l+r)/2, r);
        return fx(vl,vr);
    }

    // fast set
    void set(int i, T x) { dat[i + n - 1] = x; }
    void build() {
        for (int k = n - 2; k >= 0; k--){
            dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }

    // print functions
    void print(){
        vector<T> seg;
        for (auto i = size-n; i < size; i++){
            seg.push_back(dat[i]);
        }
        // dump(seg);
    }
};
template <typename T>
ostream &operator<<(ostream &os, const SegTree<T> &tree) {
    long long nspaces = 3;
    os << endl << '\t';
    long long space = tree.n;
    long long linecount = 0;
    for(int i = 0; i < tree.size; i++){
        long long spacenum = space * nspaces - to_string(tree.dat[i]).length();
        // to_stringでエラーが出たらstringの長さを出せるように(mintだとtree.dat[i].val)
        os << tree.dat[i];
        for(int j = 0; j < spacenum; j++){
            os << " ";
        }
        linecount += space;
        if (linecount >= tree.n){
            linecount = 0;
            space /= 2;
            os << endl << '\t';
        }
    }
    os << "\033[0;30m";
    for(int i = 0; i < tree.n; i++){
        os << i;
        for(unsigned long long j = 0; j < nspaces - to_string(i).length(); j++) os << " ";
    }
    os << "\033[0m";
    return os;
}

template <typename T>
vector<T> compress(vector<T> &X) {
    // ソートした結果を vals に
    vector<T> vals = X;
    sort(vals.begin(), vals.end());
    // 隣り合う重複を削除(unique), 末端のゴミを削除(erase)
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    // 各要素ごとに二分探索で位置を求める
    for (int i = 0; i < (int)X.size(); i++) {
        X[i] = lower_bound(vals.begin(), vals.end(), X[i]) - vals.begin();
    }
    return vals;
}

/* ex.
vector<long long> a = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3}
vector<long long> a_key;

a_key = compress(a);

a: {2, 0, 3, 0, 4, 6, 1, 5, 4, 2} // aが圧縮された値
a_key: {1, 2, 3, 4, 5, 6, 9} // 元の数字を取り出したい時用(a_key[a[i]])
*/

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> c(n);
    vector<long long> x(n);
    for (int i = 0; i < n; i++){
        cin >> c[i];
        c[i]--;
    }
    for (int i = 0; i < n; i++){
        cin >> x[i];
        x[i]--;
    }
    vector<vector<long long>> c_c(n);
    for (int i = 0; i < n; i++){
        c_c[c[i]].push_back(x[i]);
    }
    dump(c_c);
    for (auto &vec: c_c){
        compress(vec);
    }
    dump(c_c);
    SegTree<long long> tree(n, 0);
    long long m0 = 0;
    for (int i = 0; i < n; i++){
        dump(x[i]);
        tree.update(x[i], tree.dat[(tree.size-1)/2+x[i]]+1);
        m0 += tree.query(x[i]+1, n);
        dump(tree, m0);
    }
    dump(m0);
    for (auto vec: c_c){
        long long res_ = 0;
        if ((int)vec.size() < 2) continue;
        SegTree tree1((int)vec.size(), 0);
        for (int i = 0; i < (int)vec.size(); i++){
            tree1.update(vec[i], tree1.dat[(tree1.size-1)/2+vec[i]]+1);
            res_ += tree1.query(vec[i]+1, (int)vec.size());
            dump(tree1);
        }
        m0 -= res_;
        dump(vec, res_);
    }
    cout << m0 << endl;
    return 0;
}