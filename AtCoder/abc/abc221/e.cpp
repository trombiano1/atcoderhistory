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
vector<ll> a = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3}
vector<ll> a_key;

a_key = compress(a);

a: {2, 0, 3, 0, 4, 6, 1, 5, 4, 2} // aが圧縮された値
a_key: {1, 2, 3, 4, 5, 6, 9} // 元の数字を取り出したい時用(a_key[a[i]])
*/

template <typename T>
struct SegTree { // Lazy Seg Tree
    vector<T> dat, lazy;
    ll n, size;
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
    ll nspaces = 3;
    os << endl << '\t';
    ll space = tree.n;
    ll linecount = 0;
    for(int i = 0; i < tree.size; i++){
        ll spacenum = space * nspaces - to_string(tree.dat[i].val).length();
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

template<int mod>
struct modular {
    long long val;
    constexpr modular(long long v = 0) noexcept : val(v % mod) {
        if (val < 0) val += mod;
    }
    constexpr int getmod() { return mod; }
    constexpr modular operator - () const noexcept {
        return val ? mod - val : 0;
    }
    constexpr modular operator + (const modular& r) const noexcept { return modular(*this) += r; }
    constexpr modular operator - (const modular& r) const noexcept { return modular(*this) -= r; }
    constexpr modular operator * (const modular& r) const noexcept { return modular(*this) *= r; }
    constexpr modular operator / (const modular& r) const noexcept { return modular(*this) /= r; }
    constexpr modular& operator += (const modular& r) noexcept {
        val += r.val;
        if (val >= mod) val -= mod;
        return *this;
    }
    constexpr modular& operator -= (const modular& r) noexcept {
        val -= r.val;
        if (val < 0) val += mod;
        return *this;
    }
    constexpr modular& operator *= (const modular& r) noexcept {
        val = val * r.val % mod;
        return *this;
    }
    constexpr modular& operator /= (const modular& r) noexcept {
        long long a = r.val, b = mod, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % mod;
        if (val < 0) val += mod;
        return *this;
    }
    constexpr bool operator == (const modular& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const modular& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream& operator << (ostream &os, const modular<mod>& x) noexcept {
        return os << x.val;
    }
    friend constexpr istream& operator >> (istream &is, modular<mod>& x) noexcept {
        is >> x.val;
        x.val %= mod;
        if (x.val < 0) x.val += mod;
        return is;
    }
};

const int mod = 998244353;
using mint = modular<mod>;

mint power(mint a, ll n) {
    mint res = 1;
    while (n > 0) {
        if (n & 1) {
            res *= a;
        }
        a *= a;
        n >>= 1;
    }
    return res;
}

int main(void) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<ll> keys = compress(a);
    SegTree<mint> tree(keys.size(), 0);
    mint res = 0;
    for(int i = n-1; i >= 0; i--){
        dump(tree.query(a[i], a[i]+1));
        res += tree.query(a[i], keys.size()) / power(2, i+1);
        tree.update(a[i], tree.query(a[i], a[i]+1) + power(2, i));
        dump(tree);
    }
    cout << res << endl;
    dump(tree);
    return 0;
}