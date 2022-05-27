#include <bits/stdc++.h>
using namespace std;
#define INF 1e18
#define ll long long
#define ALL(x) begin(x), end(x)

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
#pragma region funcs
struct UnionFind {
    vector<int> par; // par[i]:iの親の番号 (例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る:root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時:xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

template <typename T>
struct SegTree { // Lazy Seg Tree
    vector<T> dat, lazy;
    ll n, size;
    T def;

    // defines function.
    // make sure fx(x, def) = x (モノイド)
    //   ex. min(INF, INF) = INF, min(x, INF) = x
    //       max(-INF, INF) = INF, max(x, INF) = x
    //       lcm(1, 1) = 1, lcm(1, a) = a
    //       gcf(全ての数の倍数, a) = a
    //           fxでINFが来たら相手になるように実装
    T fx(T a, T b){
        return a + b;
    }

    // 木の構築. 全てをdefにセット.
    SegTree(int N, T def_) : dat(2*pow(2,ceil(log2(N)))-1), lazy(2*pow(2,ceil(log2(N)))-1) {
        n = pow(2,ceil(log2(N)));
        size = 2 * n - 1;
        def = def_;
        for (size_t i = 0; i < dat.size(); i++){
            dat[i] = def;
            lazy[i] = def;
        }
    }

    // [a, b)の区間をxにセット. 
    void update(int a, int b, T x, int k, int l, int r){
        eval(k);
        if (a <= l && r <= b){
            lazy[k] = x;
            eval(k);
        } else if (a < r && l < b){
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);
            dat[k] = fx(dat[k * 2 + 1], dat[k * 2 +  2]);
        }
    }
    void update(int a, int b, T x) { update(a, b, x, 0, 0, n); }
    void update(int a, T x) { update(a, a+1, x, 0, 0, n); }
    
    // 遅延評価用. 
    void eval(int k) { // 配列のk番目を更新
        if (lazy[k] == def) return; // 更新するものがなければ終了
        if (k < n-1){ // 葉でなければ子に伝搬
            lazy[k*2 + 1] = lazy[k];
            lazy[k*2 + 2] = lazy[k];
        }
        // update self
        dat[k] = lazy[k];
        lazy[k] = def;
    }

    // [a, b)のfxを返す.
    T query(int a, int b){ return query_sub(a, b, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r){
        eval(k);
        if(b <= l || r <= a) return def;
        if(a <= l && r <= b) return dat[k];
        T vl = query_sub(a, b, 2*k+1, l, (l+r)/2);
        T vr = query_sub(a, b, 2*k+2, (l+r)/2, r);
        return fx(vl,vr);
    }

    // print functions
    void print(){
        vector<T> seg;
        for (auto i = size-n; i < size; i++){
            seg.push_back(dat[i]);
        }
        dump(seg);
    }
    void print_all(){
        ll c = 0;
        while (pow(2,c) < size){
            vector<T> seg;
            for (auto i = 0; i < pow(2,c); i++){
                seg.push_back(dat[i]);
            }
            dump(seg);
            c++;
        }
    }
};
#pragma endregion funcs

int main(void) {
    string s;
    cin >> s;
    if (s.size() == 1){
        for (auto i = 0; i < 6; i++){
            cout << s;
        }
        cout << endl;
    } else if (s.size() == 2){
        cout << s << s << s << endl;
    } else {
        cout << s << s << endl;
    }
    return 0;
}