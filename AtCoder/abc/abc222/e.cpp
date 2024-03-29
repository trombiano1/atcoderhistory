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

int main(void) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m);
    for(int i = 0; i < m; i++){
        cin >> a[i];
        a[i]--;
    }
    vector<vector<pair<int, int>>> G(n);
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back({v, i});
        G[v].push_back({u, i});
    }
    vector<int> pass_count(n-1);
    for(int i = 0; i < m-1; i++){
        // a[i] から a[i+1]でpass_countを++
        vector<ll> dist(n, -1);
        queue<pair<int, vector<int>>> que;
        
        dist[a[i]] = 0;
        que.push({a[i], {}});
        vector<int> s_path;
        while (!que.empty()) {
            pair<int, vector<int>> v = que.front();
            que.pop();
            if (v.first == a[i+1]){
                s_path = v.second;
                break;
            }
        
            for (pair<int, int> nv : G[v.first]) {
                if (dist[nv.first] != -1) continue;
        
                dist[nv.first] = dist[v.first] + 1;
                vector<int> path = v.second;
                path.push_back(nv.second);
                que.push({nv.first, path});
            }
        }
        for(int j = 0; j < (ll)s_path.size(); j++){
            pass_count[s_path[j]]++;
        }
    }
    vector<mint> dp(2*m*n);
    dp[m*n]=1;
    for(int i = 0; i < n-1; i++){
        vector<mint> dp_(2*m*n);
        for(int j = 0; j < 2*m*n; j++){
            if (dp[j] != 0){
                dp_[j + pass_count[i]] += dp[j];
                dp_[j - pass_count[i]] += dp[j];
            }
        }
        swap(dp, dp_);
    }
    if (k < -m*n || k > m*n - 1){
        cout << 0 << endl; 
        return 0;
    }
    cout << dp[k + m*n] << endl;
    return 0;
}