#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

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

// nCr % mod, n! % mod
// to use fact[i], initialize first with C(max, 0);
vector<mint> fact(1, 1);
vector<mint> finv(1, 1);

mint C(int n, int k) {
    if (n < k || k < 0) {
        return mint(0);
    }
    while ((int) fact.size() < n + 1) {
        fact.emplace_back(fact.back() * (int) fact.size());
        finv.emplace_back(mint(1) / fact.back());
    }
    return fact[n] * finv[k] * finv[n - k];
}

// (a ^ n) % mod
mint power(mint a, long long n) {
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> G(n);
    for(int i = 0; i < m; i++){
        long long u, v;
        cin >> u >> v;
        u--; v--;
        G[u]++; 
        G[v]++;
    }
    dump(G);
    long long count = 0;
    for (int i = 0; i < n; i++){
        if (G[i] % 2 == 1){
            count++;
        }
    }
    mint res = 0;
    for (int i = 0; i <= k; i++){
        if (i % 2 == 1) continue;
        res += C(count, i) * C(n-count, k-i);
    }
    cout << res << endl;
    return 0;
}