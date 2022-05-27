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

ll ncr(ll n, ll r){
    if (r == 0) return 1;
    ll res = 1;
    // for (auto i = n-r+1; i <= n; i++){
    //     res *= i;
    // }
    for (auto i = 1; i <= r; i++){
        res *= (n-i+1);
        res /= i;
    }
    return res;
}

int main(void) {
    ll a, b, k;
    cin >> a >> b >> k;
    k--;
    ll c = 0;
    vector<ll> digs;
    ll counter = 0;
    ll max_dig = -1;
    for (auto p = 0; b-1-p >= 0; p++){
        counter++;
        c = 0;
        for (auto i = b-1-p; i <= a+b-p ; i++){
            // dump("a",i,b-1-p,c);
            if (ncr(i,b-1-p) > k-c){
                dump(i,c,k);
                digs.push_back(i);
                if (max_dig == -1) max_dig = i;
                k-=c;
                break;
            }
            c += ncr(i,b-1-p);
            // dump(i,b-1-p,ncr(i,b-1-p));
        }
        // k-=c;
    }
    dump(digs);
    map<ll, ll> mp;
    for (auto i : digs){
        mp[i] = 1;
    }
    dump(max_dig);
    for (auto i = a+b-1; i >= 0; i--){
        if (mp[i] == 0){
            cout << "a";
        } else {
            cout << "b";
        }
    }
    cout << endl;
    return 0;
}