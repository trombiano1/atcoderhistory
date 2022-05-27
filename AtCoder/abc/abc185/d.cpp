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
    ll n, m;
    cin >> n >> m;
    vector<ll> a_i(m);
    vector<ll> blanks;
    for (auto i = 0; i < m; i++){
        cin >> a_i[i];
    }
    sort(a_i.begin(), a_i.end());
    vector<ll> a(m+2);
    for (auto i = 0; i < m; i++){
        a[i+1] = a_i[i];
    }
    a[0] = 0;
    a[m+1] = n+1;
    for (auto i = 1; i < m+2; i++){
        if (a[i] - a[i-1] > 1){
            blanks.push_back(a[i] - a[i-1] - 1);
        }
    }
    sort(blanks.begin(), blanks.end());
    dump("a");
    if (blanks.size() == 0){
        cout << 0 << endl;
        return 0;
    }
    ll k = blanks[0];
    dump("a");
    dump(k, blanks);
    ll res = 0;
    for (unsigned ll i = 0; i < blanks.size(); i++){
        dump(blanks[i]/k);
        res += (ll)(blanks[i]/k);
        if (blanks[i]%k != 0){
            res += 1;
        }
    }
    dump(res);
    cout << res << endl;
    // if (a[0] > 0){
    //     blanks.push_back(a[0]);
    // }
    // for (auto i = 1; i < m; i++){
    //     if (a[i] - a[i-1] - 1 > 0){
    //         blanks.push_back(a[i]-a[i-1]-1);
    //     }
    // }
    // if (n - 1 - a[m-1] > 0){
    //     blanks.push_back(n - 1 - a[m-1]);
    // }
    // dump(a, blanks);
    return 0;
}