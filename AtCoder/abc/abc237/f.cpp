#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

template <long long mod>
struct modular {
    long long value;
    modular(long long x = 0) {
        value = x % mod;
        if (value < 0) value += mod;
    }
    modular& operator+=(const modular& other) {
        if ((value += other.value) >= mod) value -= mod;
        return *this;
    }
    modular& operator-=(const modular& other) {
        if ((value -= other.value) < 0) value += mod;
        return *this;
    }
    modular& operator*=(const modular& other) {
        value = value * other.value % mod;
        return *this;
    }
    modular& operator/=(const modular& other) {
        long long a = 0, b = 1, c = other.value, m = mod;
        while (c != 0) {
            long long t = m / c;
            m -= t * c;
            swap(c, m);
            a -= t * b;
            swap(a, b);
        }
        a %= mod;
        if (a < 0) a += mod;
        value = value * a % mod;
        return *this;
    }
    friend modular operator+(const modular& lhs, const modular& rhs) { return modular(lhs) += rhs; }
    friend modular operator-(const modular& lhs, const modular& rhs) { return modular(lhs) -= rhs; }
    friend modular operator*(const modular& lhs, const modular& rhs) { return modular(lhs) *= rhs; }
    friend modular operator/(const modular& lhs, const modular& rhs) { return modular(lhs) /= rhs; }
    modular& operator++() { return *this += 1; }
    modular& operator--() { return *this -= 1; }
    modular operator++(int) {
        modular res(*this);
        *this += 1;
        return res;
    }
    modular operator--(int) {
        modular res(*this);
        *this -= 1;
        return res;
    }
    modular operator-() const { return modular(-value); }
    bool operator==(const modular& rhs) const { return value == rhs.value; }
    bool operator!=(const modular& rhs) const { return value != rhs.value; }
    bool operator<(const modular& rhs) const { return value < rhs.value; }
};
template <long long mod>
string to_string(const modular<mod>& x) {
    return to_string(x.value);
}
template <long long mod>
ostream& operator<<(ostream& stream, const modular<mod>& x) {
    return stream << x.value;
}
template <long long mod>
istream& operator>>(istream& stream, modular<mod>& x) {
    stream >> x.value;
    x.value %= mod;
    if (x.value < 0) x.value += mod;
    return stream;
}
 
constexpr long long mod = 998244353;
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
    int n, m;
    cin >> n >> m;
    vector dp(n, vector(m+2, vector(m+2, vector<mint>(m+2))));
    int inf = m+1;
    for (int i = 1; i <= m; i++){
        dp[0][inf][inf][i] = 1;
    }
    // dump(dp[0][inf][inf]);
    for (int i = 0; i < n-1; i++){
        for (int a = 1; a <= inf; a++){
            for (int b = 1; b <= inf; b++){
                for (int c = 1; c <= inf; c++){
                    for (int d = 1; d <= m; d++){
                        if (b < d && d <= a){
                            dp[i+1][d][b][c] += dp[i][a][b][c];
                        } else if (c < d && d <= b){
                            dp[i+1][a][d][c] += dp[i][a][b][c];
                        } else if (d <= c){
                            dp[i+1][a][b][d] += dp[i][a][b][c];
                        }
                    }
                }
            }
        }
    }
    dump(dp[1][inf]);
    mint res = 0;
    for (int a = 1; a <= m; a++){
        for (int b = 1; b <= m; b++){
            for (int c = 1; c <= m; c++){
                res += dp[n-1][a][b][c];
            }
        }
    }
    // dump(dp[n-1]);
    cout << res << endl;
    return 0;
}