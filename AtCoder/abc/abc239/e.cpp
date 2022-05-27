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
ostream &operator<<(ostream &os, const pair<T, U> &pair_var) {
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}
// vector
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    os << "{";
    for (int i = 0; i < (int)vec.size(); i++) {
        os << "\033[0;90m[" << i << "]\033[0m" << vec[i] << (i + 1 == (int)vec.size() ? "" : ", ");
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
#define dump(...)                                                              \
    DUMPOUT << "\033[0;90m[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]\033[0m"        \
            << endl                                                            \
            << " " ,                                                         \
        dump_func(#__VA_ARGS__,__VA_ARGS__)
#else
#define DEB if (false)
#define dump(...)
#endif
#pragma endregion dump

vector<ll> x;
vector<ll> xmax;
vector<ll> xmax2;
vector<vector<ll>> G;
vector<vector<ll>> top20s;

ll dfs(ll n, ll from){
    dump(n+1, from+1);
    ll currentmax = -1;
    for (auto i = 0; i < G[n].size(); i++){
        if (G[n][i] == from) continue;
        ll nextmax = dfs(G[n][i], n);
        if (nextmax > currentmax){
            currentmax = nextmax;
        }
    }
    if (currentmax == -1){
        return x[n];
    }
    xmax[n] = currentmax;
    return currentmax;
}

vector<ll> dfs_2(ll n, ll from){
    vector<ll> top20(20);
    priority_queue<ll> pque;
    // dump(n+1, from+1);
    pque.push(x[n]);
    // dump(G[n]);
    for (auto i = 0; i < G[n].size(); i++){
        if (G[n][i] == from) continue;
        vector<ll> nexts = dfs_2(G[n][i], n);
        // dump("n",nexts);
        for (auto v : nexts){
            pque.push(v);
        }
    }
    for (auto i = 0; i < 20; i++){
        if (!pque.empty()){
            top20[i] = pque.top();
            pque.pop();
        } else {
            top20[i] = -1;
        }
    }
    // dump(n+1, top20);
    top20s[n] = top20;
    return top20;
}

int main(void) {
    ll n, q;
    cin >> n >> q;
    x.resize(n);
    xmax.resize(n);
    xmax2.resize(n);
    top20s.resize(n);
    G.resize(n);
    for (auto i = 0; i < n; i++){
        cin >> x[i];
    }
    for (auto i = 0; i < n-1; i++){
        ll a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs_2(0,-1);
    // dump(res);
    dump(top20s[0]);
    dump(top20s[1]);
    dump(top20s[2]);
    for (auto i = 0; i < q; i++){
        ll v, k;
        cin >> v >> k;
        v--;k--;
        cout << top20s[v][k] << endl;
    }
    return 0;
}