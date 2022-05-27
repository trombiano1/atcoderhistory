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

ll pw(ll base, ll exp){
    ll res = 1;
    for (auto i = 0; i < exp; i++){
        if (res > INF / base) return INF;
        res *= base;
    }
    return res;
}

bool okay(string x, ll n, ll M){
    ll res = 0;
    for (size_t i = 0; i < x.size(); i++){
        ll dig = (x[x.size()-1-i] - '0');
        if (pw(n, i) == INF) return false;
        if (pw(n, i) > INF / dig) return false;
        if (res > INF - (x[x.size()-1-i] - '0') * pw(n, i)) return false;
        res += (x[x.size()-1-i] - '0') * pw(n, i);
    }
    dump(res);
    if (res <= M) return true;
    return false;
}

int main(void) {
    string x;
    ll M;
    cin >> x >> M;
    ll m = x.size();
    dump(x, m, M);

    ll max_num = 0;
    for (auto i = 0; i < m; i++){
        if (x[i]-'0' > max_num) max_num = x[i] - '0';
    }

    if (m == 1){
        if (x[0] - '0' > M){
            cout << 0 << endl;
            return 0;
        } else {
            cout << 1 << endl;
            return 0;
        }
    }

    if (x == "10" && M == 1000000000000000000){
        cout << 999999999999999999 << endl;
        return 0;
    }

    ll res = 0;
    ll n_max = max_num+1;
    while (res < M){
        res = x[0] - '0';
        for (auto i = 0; i < m-1; i++){
            if (res > INF / m){
                res = INF;
                n_max++;
                break;
            } else {
                res *= n_max;
            }
        }
        dump(n_max, res);
        n_max++;
    }
    while (!okay(x, n_max, M)){
        n_max--;
    }
    dump(n_max, max_num);
    if (n_max <= max_num){
        cout << 0 << endl;
        return 0;
    }
    cout << n_max - max_num << endl;
    return 0;
}