#include <bits/stdc++.h>
using namespace std;
#define INF 1e18
#define ll long long

#pragma region dump
#define repi(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)
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

ll nextmuldiff(ll a, ll b){
    if (a%b == 0){
        return 0;
    }
    return b - a%b;
}

int main(void) {
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    x--; y--;
    vector<vector<vector<ll>>> G(n);
    for (auto i = 0; i < m; i++){
        ll a, b, t, k;
        cin >> a >> b >> t >> k;
        a--; b--;
        G[a].push_back({b,t,k});
        G[b].push_back({a,t,k});
    }
    // dump(G);
    vector<ll> fastest(n, INF);
    vector<bool> vis(n,false);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> que;

    fastest[x] = 0;
    que.push(make_pair(0,x));

    // while (!que.empty()){
    //     ll v = que.top().second;
    //     // cout << v << endl;
    //     que.pop();
    //     for(auto nv : G[v]){
    //         if (fastest[nv[0]] != INF) {
    //             //visited
    //             fastest[nv[0]] = min(fastest[nv[0]],fastest[v] + (nextmuldiff(fastest[v], nv[2])) + nv[1]);
    //         } else {
    //             fastest[nv[0]] = fastest[v] + (nextmuldiff(fastest[v], nv[2])) + nv[1];
    //             que.push(make_pair(fastest[nv[0]],nv[0]));
    //         }
    //     }
    // }
    while (!que.empty()){
        ll v = que.top().second;
        que.pop();
        if (vis[v]) continue;
        if (v == y){
            cout << fastest[v] << endl;
            return 0;
        }
        vis[v] = true;
        dump(v);
        for (auto nv : G[v]){
            dump(nv);
            ll newtime = fastest[v] + (nextmuldiff(fastest[v], nv[2])) + nv[1];
            if (fastest[nv[0]] > newtime){
                fastest[nv[0]] = newtime;
                que.push(make_pair(fastest[nv[0]],nv[0]));
            }
            dump(5);
        }
    }
    // dump(fastest);
    // dump(fastest[y]);
    if (fastest[y] == INF) {cout << -1 << endl; return 0;}
    cout << fastest[y] << endl;
    return 0;
}