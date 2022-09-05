#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

long long mod = 2;
 
struct mint {
    long long value;
    mint(long long x = 0) {
        value = x % mod;
        if (value < 0) value += mod;
    }
    mint& operator+=(const mint& other) {
        if ((value += other.value) >= mod) value -= mod;
        return *this;
    }
    mint& operator-=(const mint& other) {
        if ((value -= other.value) < 0) value += mod;
        return *this;
    }
    mint& operator*=(const mint& other) {
        value = value * other.value % mod;
        return *this;
    }
    mint& operator/=(const mint& other) {
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
    friend mint operator+(const mint& lhs, const mint& rhs) { return mint(lhs) += rhs; }
    friend mint operator-(const mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }
    friend mint operator*(const mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }
    friend mint operator/(const mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }
    mint& operator++() { return *this += 1; }
    mint& operator--() { return *this -= 1; }
    mint operator++(int) {
        mint result(*this);
        *this += 1;
        return result;
    }
    mint operator--(int) {
        mint result(*this);
        *this -= 1;
        return result;
    }
    mint operator-() const { return mint(-value); }
    bool operator==(const mint& rhs) const { return value == rhs.value; }
    bool operator!=(const mint& rhs) const { return value != rhs.value; }
    bool operator<(const mint& rhs) const { return value < rhs.value; }
};
string to_string(const mint& x) {
    return to_string(x.value);
}
ostream& operator<<(ostream& stream, const mint& x) {
    return stream << x.value;
}
istream& operator>>(istream& stream, mint& x) {
    stream >> x.value;
    x.value %= mod;
    if (x.value < 0) x.value += mod;
    return stream;
}
 
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

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n >> mod;
    vector dp(n, vector(n, vector<mint>(2, 0)));
    dp[0][0][1] = 1; // 辺がある(0本削除)
    dp[0][1][0] = 1; // 辺がない(1本削除)
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n; j++){
            // 削除なし
            dp[i+1][j][1] += dp[i][j][0] + dp[i][j][1];
            // 1本削除
            if (j+1 <= n-1){
                // 下のみ削除
                dp[i+1][j+1][1] += dp[i][j][1];
                // 上のみ削除
                dp[i+1][j+1][1] += dp[i][j][1];
                // 縦のみ削除
                dp[i+1][j+1][0] += dp[i][j][0];
                dp[i+1][j+1][1] += dp[i][j][1];
            }
            // 2本削除
            if (j+2 <= n-1){
                // 上だけのこす
                dp[i+1][j+2][0] += dp[i][j][1];
                // 下だけのこす
                dp[i+1][j+2][0] += dp[i][j][1];
                // 縦だけのこす
                // nope
            }
            // 3本削除
            //nope
        }
    }
    for (int i = 1; i <= n-1; i++){
        cout << dp[n-1][i][1] << " ";
    }
    cout << endl;
    return 0;
}