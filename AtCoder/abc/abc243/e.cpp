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
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> G_all(m);
    vector<bool> removed;
    removed.assign(m, false);
    ll res = 0;
    for (auto i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        // G[a].push_back({b,c});
        // G[b].push_back({a,c});
        G_all[i] = {a,b,c};
    }
    
    for (auto k = 0; k < m; k++){
        vector<vector<vector<ll>>> G(n);
        vector<vector<vector<ll>>> G_t(n);
        vector<ll> fastest(n, INF);
        vector<bool> vis(n,false);
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> que;
        ll x, y;
        x = G_all[k][0]; y = G_all[k][1];
        for (auto i = 0; i < m; i++){
            if (!removed[i]){
                G[G_all[i][0]].push_back({G_all[i][1], G_all[i][2]});
                G[G_all[i][1]].push_back({G_all[i][0], G_all[i][2]});
            } else {
                G[G_all[i][0]].push_back({G_all[i][1], 1000000000000000000});
                G[G_all[i][1]].push_back({G_all[i][0], 1000000000000000000});
            }
        }
        
        fastest[x] = 0;
        que.push(make_pair(0,x));

        while (!que.empty()){
            ll v = que.top().second;
            que.pop();
            if (vis[v]) continue;
            // if (v == y){
            //     cout << fastest[v] << endl;
            //     return 0;
            // }
            vis[v] = true;
            for (auto nv : G[v]){
                ll newtime = fastest[v] + nv[1];
                if (fastest[nv[0]] > newtime){
                    fastest[nv[0]] = newtime;
                    que.push(make_pair(fastest[nv[0]],nv[0]));
                }
            }
        }
        ll original_fastest = fastest[y];
        dump(original_fastest);

        vector<vector<vector<ll>>> G_new(n);
        vector<vector<vector<ll>>> G_t_new(n);
        fastest.assign(n, INF);
        vis.assign(n,false);
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> que2;
        x = G_all[k][0]; y = G_all[k][1];
        for (auto i = 0; i < m; i++){
            if (!removed[i] && i != k){
                G_new[G_all[i][0]].push_back({G_all[i][1], G_all[i][2]});
                G_new[G_all[i][1]].push_back({G_all[i][0], G_all[i][2]});
            } else {
                G_new[G_all[i][0]].push_back({G_all[i][1], 1000000000000000000});
                G_new[G_all[i][1]].push_back({G_all[i][0], 1000000000000000000});
            }
        }
        fastest[x] = 0;
        que2.push(make_pair(0,x));

        while (!que2.empty()){
            ll v = que2.top().second;
            que2.pop();
            if (vis[v]) continue;
            // if (v == y){
            //     cout << fastest[v] << endl;
            //     return 0;
            // }
            vis[v] = true;
            for (auto nv : G_new[v]){
                ll newtime = fastest[v] + nv[1];
                if (fastest[nv[0]] > newtime){
                    fastest[nv[0]] = newtime;
                    que2.push(make_pair(fastest[nv[0]],nv[0]));
                }
            }
        }
        ll removed_fastest = fastest[y];

        dump(removed_fastest);
        if (!(removed_fastest > original_fastest)){
            removed[k] = true;
            res++;
        }
    }
    cout << res << endl;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define INF 1e18
// #define ll long long
// #define MAX_V 300

// #pragma region dump
// #define repi(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)
// // vector
// template <typename T>
// istream &operator>>(istream &is, vector<T> &vec) {
//     for (T &x : vec) is >> x;
//     return is;
// }
// // pair
// template <typename T, typename U>
// ostream &operator<<(ostream &os, const pair<T, U> &pair_var) {
//     os << "(" << pair_var.first << ", " << pair_var.second << ")";
//     return os;
// }
// // vector
// template <typename T>
// ostream &operator<<(ostream &os, const vector<T> &vec) {
//     os << "{";
//     for (int i = 0; i < (int)vec.size(); i++) {
//         os << "\033[0;30m[" << i << "]\033[0m" << vec[i] << (i + 1 == (int)vec.size() ? "" : ", ");
//     }
//     os << "}";
//     return os;
// }
// // queue
// template <typename T>
// ostream &operator<<(ostream &os, const queue<T> &que) {
//     os << "{";
//     queue<T> que_copy = que; ll i = 0;
//     while (!que_copy.empty()){
//         os << "\033[0;30m[" << i << "]\033[0m" << que_copy.front();
//         que_copy.pop(); i++;
//         if (!que_copy.empty()) os << ", ";
//     }
//     os << "}" << endl;
//     return os;
// }
// // priority_queue
// template <typename T, typename U, typename V>
// ostream &operator<<(ostream &os, const priority_queue<T, U, V> &que) {
//     os << "{";
//     priority_queue<T, U, V> que_copy = que; ll i = 0;
//     while (!que_copy.empty()){
//         os << "\033[0;30m[" << i << "]\033[0m" << que_copy.top();
//         que_copy.pop(); i++;
//         if (!que_copy.empty()) os << ", ";
//     }
//     os << "}" << endl;
//     return os;
// }
// // map
// template <typename T, typename U>
// ostream &operator<<(ostream &os, map<T, U> &map_var) {
//     os << "{";
//     repi(itr, map_var) {
//         os << *itr;
//         itr++;
//         if (itr != map_var.end()) os << ", ";
//         itr--;
//     }
//     os << "}";
//     return os;
// }
// // set
// template <typename T>
// ostream &operator<<(ostream &os, set<T> &set_var) {
//     os << "{";
//     repi(itr, set_var) {
//         os << *itr;
//         itr++;
//         if (itr != set_var.end()) os << ", ";
//         itr--;
//     }
//     os << "}";
//     return os;
// }

// #define DUMPOUT cerr
// map<ll,ll> LINECOUNTER;

// void dump_func(string vas) {
//     (void)vas;
//     DUMPOUT << endl;
// }
// template <class Head, class... Tail>
// void dump_func(string vas, Head &&head, Tail &&... tail) {
//     string varname;
//     string rest;
//     vas.erase(remove(vas.begin(), vas.end(), ' '), vas.end());
//     if (sizeof...(Tail) > 0) {
//         varname = vas.substr(0, vas.find(","));
//         rest = vas.substr(vas.find(",")+1, vas.size());
//     } else {
//         varname = vas;
//     }
//     DUMPOUT << " \033[1m" << varname << "\033[0m " << ' ' << head;
//     if (sizeof...(Tail) > 0) {
//         DUMPOUT << endl << " ";
//     }
//     dump_func(vas.substr(vas.find(",")+1, vas.size()), std::move(tail)...);
// }
// #ifdef DEBUG_
// #define DEB
// #define dump(...)\
//     DUMPOUT << "\033[0;0;40m[" << LINECOUNTER[__LINE__] << ":" << to_string(__LINE__)\
//             << ":" << __FUNCTION__ << "]\033[0m"\
//             << " " << endl\
//             << " " ,\
//     LINECOUNTER[__LINE__]++;\
//     dump_func(#__VA_ARGS__,__VA_ARGS__)
// #else
// #define DEB if (false)
// #define dump(...)
// #endif
// #pragma endregion dump

// int main(void) {
//     ll n, m;
//     cin >> n >> m;
//     vector<vector<ll>> edges(m);
//     for (auto i = 0; i < n; i++){
//         ll a, b, c;
//         cin >> a >> b >> c;
//         a--; b--;
//         edges[i] = {a,b,c};
//     }
//     dump(edges);
//     for (auto j = 0; j < m; j++){
//         ll f_a, f_b;
//         f_a = edges[j][0];
//         f_b = edges[j][1];
//         for (auto k = 0; k < m; k++){
//             G[k] = {};
//         }

//         while (!que.empty()){
//             ll v = que.top().second;
//             que.pop();
//             if (vis[v]) continue;
//             if (v == y){
//                 cout << fastest[v] << endl;
//                 return 0;
//             }
//             vis[v] = true;
//             dump(v);
//             for (auto nv : G[v]){
//                 dump(nv);
//                 ll newtime = fastest[v] + (nextmuldiff(fastest[v], nv[2])) + nv[1];
//                 if (fastest[nv[0]] > newtime){
//                     fastest[nv[0]] = newtime;
//                     que.push(make_pair(fastest[nv[0]],nv[0]));
//                 }
//                 dump(5);
//             }
//         }

//         for (auto k = 0; k < m; k++){
//             if (j != k){
//                 struct edge input_edge;
//                 input_edge.cost = edges[k][2];
//                 input_edge.to = edges[k][1];
//                 G[edges[k][0]].push_back(input_edge);
//                 struct edge input_edge2;
//                 input_edge2.cost = edges[k][2];
//                 input_edge2.to = edges[k][0];
//                 G[edges[k][1]].push_back(input_edge2);
//             } else {

//             }
//         }
//         dijkstra(f_a);
//         dump(f_a,f_b,d[0], d[1], d[2]);
//     }
//     return 0;
// }