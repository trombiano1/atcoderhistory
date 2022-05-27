#include <bits/stdc++.h>
using namespace std;
#define INF 1e18
#define ll long long

#define MOD 1000000007

#pragma region dump
#define repdump(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, a, b) for(ll i = (ll)(a); i < (ll)(b); i++)
// vector
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &x : vec) is >> x;
    return is;
}
// pair
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &pair_var) {
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}
// vector
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    os << "{";
    for (int i = 0; i < (int)vec.size(); i++) {
        os << "\033[0;30m[" << i << "]\033[0m" << vec[i] << (i + 1 == (int)vec.size() ? "" : ", ");
    }
    os << "}";
    return os;
}
// queue
template <typename T>
ostream &operator<<(ostream &os, const queue<T> &que) {
    os << "{";
    queue<T> que_copy = que; ll i = 0;
    while (!que_copy.empty()){
        os << "\033[0;30m[" << i << "]\033[0m" << que_copy.front();
        que_copy.pop(); i++;
        if (!que_copy.empty()) os << ", ";
    }
    os << "}" << endl;
    return os;
}
// priority_queue
template <typename T>
ostream &operator<<(ostream &os, const priority_queue<T> &que) {
    os << "{";
    priority_queue<T> que_copy = que; ll i = 0;
    while (!que_copy.empty()){
        os << "\033[0;30m[" << i << "]\033[0m" << que_copy.top();
        que_copy.pop(); i++;
        if (!que_copy.empty()) os << ", ";
    }
    os << "}" << endl;
    return os;
}
// map
template <typename T, typename U>
ostream &operator<<(ostream &os, map<T, U> &map_var) {
    os << "{";
    repdump(itr, map_var) {
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
    repdump(itr, set_var) {
        os << *itr;
        itr++;
        if (itr != set_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}

#define DUMPOUT cerr
map<ll,ll> LINECOUNTER;

void dump_func(string vas) {
    (void)vas;
    DUMPOUT << endl;
}
template <class Head, class... Tail>
void dump_func(string vas, Head &&head, Tail &&... tail) {
    string varname;
    string rest;
    vas.erase(remove(vas.begin(), vas.end(), ' '), vas.end());
    if (sizeof...(Tail) > 0) {
        varname = vas.substr(0, vas.find(","));
        rest = vas.substr(vas.find(",")+1, vas.size());
    } else {
        varname = vas;
    }
    DUMPOUT << " \033[1m" << varname << "\033[0m " << ' ' << head;
    if (sizeof...(Tail) > 0) {
        DUMPOUT << endl << " ";
    }
    dump_func(vas.substr(vas.find(",")+1, vas.size()), std::move(tail)...);
}
#ifdef DEBUG_
#define DEB
#define dump(...)\
    DUMPOUT << "\033[0;0;40m[" << LINECOUNTER[__LINE__] << ":" << to_string(__LINE__)\
            << ":" << __FUNCTION__ << "]\033[0m"\
            << " " << endl\
            << " " ,\
    LINECOUNTER[__LINE__]++;\
    dump_func(#__VA_ARGS__,__VA_ARGS__)
#else
#define DEB if (false)
#define dump(...)
#endif
#pragma endregion dump

int main(void) {
    ll h, w;
    cin >> h >> w;
    vector<string> board(h);
    cin >> board;
    vector<vector<ll>> dp(h), x(h), y(h), z(h);
    rep(i, h){
        dp[i].assign(w, 0);
        x[i].assign(w, 0);
        y[i].assign(w, 0);
        z[i].assign(w, 0);
    }
    dp[0][0] = 1;
    x[0][0] = 1;
    y[0][0] = 1;
    z[0][0] = 1;
    rep(i, h) rep(j, w){
        if (i == 0 && j == 0) continue;
        if (board[i][j] == '#') continue;
        
        ll res = 0;
        if (j > 0) res += x[i][j-1];
        if (i > 0) res += y[i-1][j];
        res %= MOD;
        if (j > 0 && i > 0) res += z[i-1][j-1];
        res %= MOD;
        dp[i][j] = res;

        if (j > 0) x[i][j] = (x[i][j-1] + dp[i][j]) % MOD;
        else x[i][j] = dp[i][j];
        if (i > 0) y[i][j] = (y[i-1][j] + dp[i][j]) % MOD;
        else y[i][j] = dp[i][j];
        if (i > 0 && j > 0) z[i][j] = (z[i-1][j-1] + dp[i][j]) % MOD;
        else  z[i][j] = dp[i][j];
    }
    cout << dp[h-1][w-1]%MOD << endl;
    return 0;
}