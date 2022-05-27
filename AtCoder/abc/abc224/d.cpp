#include <bits/stdc++.h>
using namespace std;
#define INF 1e18
#define ll long long
#define ALL(x) begin(x), end(x)

#define MAX 9

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
// tuple
struct Functor {
    template<typename T>
    void operator()(ostream &os, T& t) const { os << t; }
};
 
template<std::size_t I = 0, typename FuncT, typename... Tp>
inline typename std::enable_if<I == sizeof...(Tp), void>::type
for_index(ostream &os, int, std::tuple<Tp...> &, FuncT)
{(void)os;}
 
template<std::size_t I = 0, typename FuncT, typename... Tp>
inline typename std::enable_if<I < sizeof...(Tp), void>::type
for_index(ostream &os, int index, std::tuple<Tp...>& t, FuncT f) {
    if (index == 0) f(os, std::get<I>(t));
    for_index<I + 1, FuncT, Tp...>(os, index-1, t, f);
}

template <typename... T>
ostream &operator<<(ostream &os, const tuple<T...> &tuple_var) {
    auto t = tuple_var;
    os << "(";
    // auto t = make_tuple(1, 2, "abc", "def", 4.0f);
    for (size_t i = 0; i < tuple_size<decltype(t)>::value; i++){
        for_index(os, i, t, Functor());
        if (i != tuple_size<decltype(t)>::value - 1){
            os << ",";
        }
    }
    os << ")";
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
template <typename T, typename U, typename V>
ostream &operator<<(ostream &os, const priority_queue<T, U, V> &que) {
    os << "{";
    priority_queue<T, U, V> que_copy = que; ll i = 0;
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
    repi(itr, map_var) {
        os << "\033[0;90m" << (*itr).first  << ":\033[0m";
        os << (*itr).second;
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

map<vector<ll>, vector<vector<ll>>> mp;
map<vector<ll>, bool> seen;
ll counter = 0;

// void dfs(vector<ll> vect){
//     dump(vect);
//     counter++;
//     seen[vect] = true;
//     if (vect == end){
//         cout << counter << endl;
//     } else {
//         for (auto i : mp[vect]){
//             if (!seen[i]){
//                 dfs(i);
//             }
//         }
//     }
// }

int main(void) {
    ll m;
    cin >> m;
    vector<vector<ll>> edges;
    for (auto i = 0; i < m; i++){
        ll u, v;
        cin >> u >> v;
        u--; v--;
        edges.push_back({u,v});
    }
    //     vector<ll> perm_vect;
    //     for (auto l = 0; l < 9; l++){
    //         if (l!=u && l!=v) perm_vect.push_back(l);
    //     }
    //     perm_vect.push_back(100);
    //     dump(perm_vect);
    //     do {
    //         vector<ll> new_vect(MAX);
    //         new_vect = perm_vect;
    //         ll k_remember;
    //         // dump(new_vect);
    //         for (auto k = 0;; k++){
    //             if (new_vect[k] == 100){
    //                 k_remember = k;
    //                 break;
    //             }
    //         }
    //         new_vect[k_remember] = u;
    //         perm_vect[k_remember] = v;
    //         mp[new_vect].push_back(perm_vect);
    //         mp[perm_vect].push_back(new_vect);
    //         new_vect[k_remember] = v;
    //         perm_vect[k_remember] = u;
    //         mp[new_vect].push_back(perm_vect);
    //         mp[perm_vect].push_back(new_vect);
    //         perm_vect[k_remember] = 100;
    //     } while (next_permutation(perm_vect.begin(), perm_vect.end()));
    // }

    vector<ll> from(8);
    for (auto i = 0; i < 8; i++){
        ll p;
        cin >> p;
        p--;
        from[i] = p;
    }
    // dfs(from);
    map<vector<ll>, ll> dist;
    map<vector<ll>, bool> seen;
    queue<vector<ll>> que;
    dist[from] = 0;
    seen[from] = true;
    que.push(from);
    vector<ll> end {0, 1, 2, 3, 4, 5, 6, 7};

    while (!que.empty()) {
        vector<ll> v = que.front();
        que.pop();
        dump(v);
        if (v == end){
            cout << dist[v] << endl;
            return 0;
        }
        // for (auto nv : mp[v]) {
        for (auto i = 0; i < m; i++){
            dump(edges[i]);
            vector<ll> nv;
            ll n_u = edges[i][0], n_v = edges[i][1];

            nv = v;
            // edge[i][0], edge[i][1]
            vector<bool> used(8);
            for (auto k = 0; k < 8; k++){
                used[nv[k]] = true;
            }
            ll missing_no;
            for (auto k = 0; k < 9; k++){
                if (!used[k]){
                    missing_no = k;
                    break;
                }
            }
            if (missing_no == n_u){
                for (auto k = 0; k < 8; k++){
                    if (nv[k] == n_v){
                        nv[k] = n_u;
                        break;
                    }
                }
            } else if (missing_no == n_v) {
                for (auto k = 0; k < 8; k++){
                    if (nv[k] == n_u){
                        nv[k] = n_v;
                        break;
                    }
                }
            }
            dump(nv,missing_no);
            // dump(v, edges[i], nv);
            if (seen[nv] != true){ // すでに発見済みの頂点は探索しない
                dist[nv] = dist[v] + 1;
                seen[nv] = true;
                que.push(nv);
            }
        }
    }
    cout << -1 << endl;
    return 0;
}