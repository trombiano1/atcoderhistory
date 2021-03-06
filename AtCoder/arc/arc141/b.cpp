#include <bits/stdc++.h>
using namespace std;
#define INF 1e18
#define ll long long
#define all(x) begin(x), end(x)

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

template<int mod> struct modular {
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
    ll n, m;
    cin >> n >> m;
    if (n > 65){
        cout << 0 << endl;
        return 0;
    }
    vector<vector<mint>> dp(n);
    ll max_bit_n = log2((ll)m)+1;
    for(int i = 0; i < n; i++) dp[i].assign(max_bit_n, 0);
    dump(dp);
    for(int i = 0; i < max_bit_n - 1; i++){
        dp[0][i] = power(2, i);
    }
    dump(max_bit_n);
    mint last_n = (mint)m - (power(2, max_bit_n-1) -1);
    dp[0][max_bit_n - 1] = (mint)m - (power(2, max_bit_n-1) -1);
    for(int i = 1; i < n; i++){
        for(int j = i; j < max_bit_n; j++){
            mint sum = 0;
            for(int k = 0; k < j; k++) {
                sum += dp[i-1][k];
            }
            dp[i][j] += sum * power(2, j);
        }
        mint sum = 0;
        for(int k = 0; k < max_bit_n - 1; k++){
            sum += dp[i-1][k];
        }
        dp[i][max_bit_n - 1] = sum * (last_n);
    }
    mint res = 0;
    for(int i = 0; i < max_bit_n; i++){
        res += dp[n-1][i];
    }
    cout << res << endl;
    return 0;
}