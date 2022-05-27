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

int main(void) {
    ll h, w, n, m;
    cin >> h >> w >> n >> m;
    vector<pair<ll,ll>> light(n);
    for (auto i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        a--; b--;
        light[i] = make_pair(a,b);
    }
    vector<vector<int>> coord(h);
    for (auto i = 0; i < h; i++){
        coord[i].assign(w, 0);
    }
    // 2はブロック
    // 1は点灯
    // 0は消灯
    for (auto i = 0; i < m; i++){
        ll c, d;
        cin >> c >> d;
        c--; d--;
        coord[c][d] = 2;
    }
    vector<vector<int>> coord2(h);
    coord2 = coord;
    for (auto i = 0; i < n; i++){
        ll f = light[i].first; ll s = light[i].second;
        if (coord[f][s] == 0){
            coord[f][s] = 1;
            while (s < w-1){
                s++;
                if (coord[f][s] != 2){
                    coord[f][s] = 1;
                } else {
                    break;
                }
            }
            s = light[i].second;
            while (s > 0){
                s--;
                if (coord[f][s] != 2){
                    coord[f][s] = 1;
                } else {
                    break;
                }
            }
        }
    }
    for (auto i = 0; i < n; i++){
        ll f = light[i].first; ll s = light[i].second;
        dump(f,s);
        if (coord2[f][s] == 0){
            coord2[f][s] = 1;
            while (f < h-1){
                f++;
                if (coord2[f][s] != 2){
                    coord2[f][s] = 1;
                } else {
                    break;
                }
            }
            f = light[i].first;
            dump("a");
            while (f > 0){
                f--;
                if (coord2[f][s] != 2){
                    coord2[f][s] = 1;
                } else {
                    break;
                }
            }
        }
    }
    dump(coord,coord2);
    ll res = 0;
    for (auto i = 0; i < h; i++){
        for (auto j = 0; j < w; j++){
            if (coord[i][j] == 1 || coord2[i][j] == 1){
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}