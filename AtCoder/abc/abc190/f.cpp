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

template <typename T>
struct SegTree {
    vector<T> node;
    ll n, size;
    T def;

    SegTree(int N, T def_) : node(2*pow(2,ceil(log2(N)))-1) {
        n = pow(2,ceil(log2(N)));
        size = 2 * n - 1;
        def = def_;
        for (size_t i = 0; i < node.size(); i++) node[i] = def;
    }

    T f(T a, T b){ // define function
        return a + b;
    }

    void update(int i, T x){
        i += n - 1;
        node[i] = x;
        while (i > 0){
            i = (i-1)/2; // parent
            node[i] = f(node[2*i+1], node[2*i+2]);
        }
    }
    
    T query(int a, int b){ return query_sub(a, b, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r){
        if(b <= l || r <= a) return def;
        if(a <= l && r <= b) return node[k];
        T vl = query_sub(a, b, 2*k+1, l, (l+r)/2);
        T vr = query_sub(a, b, 2*k+2, (l+r)/2, r);
        return f(vl,vr);
    }

    void print(){
        vector<T> seg;
        for (auto i = size-n; i < size; i++){
            seg.push_back(node[i]);
        }
        dump(seg);
    }

    void print_all(){
        vector<T> seg;
        for (auto i = 0; i < size; i++){
            seg.push_back(node[i]);
        }
        dump(seg);
    }
};

int main(void) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    cin >> a;
    dump(a);
    SegTree<ll> tree(n, 0);
    vector<ll> s(n, 0);
    vector<ll> p(n, 0);
    for (auto i = 0; i < n; i++){
        tree.update(a[i], 1);
        s[i] = tree.query(a[i]+1, n);
        p[i] = tree.query(0, a[i]);
    }
    dump(s,p);
    ll res = 0;
    for (auto i = 0; i < n; i++){
        res += s[i];
    }
    cout << res << endl;
    for (auto i = 0; i < n-1; i++){
        res = res - s[a[i]] - p[a[i]] + (n-a[i]-1);
        cout << res << endl;
    }
    return 0;
}