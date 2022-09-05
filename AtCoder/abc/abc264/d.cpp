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

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    map<char, int> mp;
    vector<int> a(7);
    mp['a'] = 0; mp['t'] = 1; mp['c'] = 2; mp['o'] = 3; mp['d'] = 4; mp['e'] = 5; mp['r'] = 6;
    for (int i = 0; i < 7; i++){
        a[i] = mp[s[i]];
    }
    dump(a);
    SegTree<long long> tree(7, 0);
    long long res = 0;
    for (int i = 0; i < 7; i++){
        tree.update(a[i], 1);
        res += tree.query(0, 7) - tree.query(0, a[i]+1);
    }
    cout << res << endl;
    return 0;
}