#include <bits/stdc++.h>

using namespace std;

#define INF 1e18
#define ll long long
#define repi(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)

#pragma region dump
// vector
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &x : vec) is >> x;
    return is;
}
// pair
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &pair_var) {
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}
// vector
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    os << "{";
    for (int i = 0; i < (int)vec.size(); i++) {
        os << vec[i] << (i + 1 == (int)vec.size() ? "" : ", ");
    }
    os << "}";
    return os;
}
// map
template <typename T, typename U>
ostream &operator<<(ostream &os, map<T, U> &map_var) {
    os << "{";
    repi(itr, map_var) {
        os << *itr;
        itr++;
        if (itr != map_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
// set
template <typename T>
ostream &operator<<(ostream &os, set<T> &set_var) {
    os << "{";
    repi(itr, set_var) {
        os << *itr;
        itr++;
        if (itr != set_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}

#define DUMPOUT cerr

void dump_func() {
    DUMPOUT << endl;
}
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&... tail) {
    DUMPOUT << head;
    if (sizeof...(Tail) > 0) {
        DUMPOUT << ", ";
    }
    dump_func(std::move(tail)...);
}
#ifdef DEBUG_
#define DEB
#define dump(...)                                                              \
    DUMPOUT << "  \033[1m" << string(#__VA_ARGS__) << "\033[0m: "                            \
            << "\033[0;90m[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]\033[0m"        \
            << endl                                                            \
            << "    " ,                                                         \
        dump_func(__VA_ARGS__)
#else
#define DEB if (false)
#define dump(...)
#endif
#pragma endregion dump

struct Node{
    ll value = INF;
};

int main(void) {
    ll n, m;
    cin >> n >> m;
    map<pair<ll, ll>, Node> G;
    for (auto i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        G[make_pair(a,b)].value = c;
    }
    vector<vector<vector<ll>>> dp(n+2);
    for (auto i = 0; i < n+2; i++){
        dp[i].resize(n+2);
        for (auto j = 0; j < n+2; j++){
            dp[i][j].resize(n+2);
        }
    }
    // k = 0
    for (auto s = 1; s < n+2; s++){
        for (auto t = 1; t < n+2; t++){
            if (s==t){dp[0][s][t] = 0; continue;}
            dp[0][s][t] = G[make_pair(s,t)].value;
        }
    }
    ll res = 0;
    for (auto k = 0; k <= n; k++){
        for (auto s = 1; s < n+1; s++){
            for (auto t = 1; t < n+1; t++){
                // dump(k, s, t);
                dp[k+1][s][t] = min(dp[k][s][t], dp[k][s][k+1]+dp[k][k+1][t]);
                if (min(dp[k][s][t], dp[k][s][k+1]+dp[k][k+1][t]) < INF) {
                    res += min(dp[k][s][t], dp[k][s][k+1]+dp[k][k+1][t]);
                    // dump(k,s,t,min(dp[k][s][t], dp[k][s][k+1]+dp[k][k+1][t]));
                }
            }
        }
    }
    // dump(dp);  
    dump(res);
    cout << res << endl;
    return 0;
}