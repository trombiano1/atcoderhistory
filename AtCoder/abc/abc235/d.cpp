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

ll a, n;
ll found = false;

ll dfs(ll m, ll c, map<ll, bool> mp){
    dump(m, c, mp);
    if (m == n){
        found = true;
        cout << c << endl;
        return 0;
    }
    if (log10(m) > log10(n)) return 0;

    if (!mp[m] && !found){
        map<ll, bool> new_mp = mp;
        new_mp[m] = true;

        ll lst = m%10;
        ll dgt = (ll)log10(m);
        ll swap = lst * pow(10, dgt) + m/10;
        ll dbl = m * a;
    
        if (log10(swap) <= log10(n)) dfs(swap, c+1, new_mp);

        if (log10(dbl) <= log10(n)) dfs(dbl, c+1, new_mp);
    }
    return 0;
}

int main(void) {
    map<ll, bool> mp;
    cin >> a >> n;
    dfs(1, 0, mp);
    if (!found){
        cout << -1 << endl;
    }
    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;

// #define ll long long
// #define rep(i, n) for (int i = 0; i < (int)(n); i++)

// ll a;
// map<ll,bool> seen;

// ll dfs(ll n){
//     if (seen[n]) return -1;
//     seen[n] = true;
//     // cout << "n" << n << endl;
//     if (n==1) return 0;
//     bool d_flag = false;
//     bool f_flag = false;
//     if (n % a == 0) {
//         // cout << "divide ok" << endl;
//         d_flag = true;
//     }
//     ll dig = (ll)log10(n);
//     ll top = (ll)(n/pow(10,dig));
//     ll flipped = (n - top * pow(10,dig))*10+top;
//     ll new_top = (ll)(flipped/pow(10,dig));
//     if (new_top != 0 && dig > 0){
//         f_flag = true;
//     }
//     if (!f_flag && !d_flag){
//         return -1;
//     }
//     if (d_flag && f_flag){
//         ll dfs1 = dfs(n/a);
//         ll dfs2 = dfs(flipped);
//         if (dfs1 > -1 && dfs2 > -1){
//             return min(dfs1 + 1, dfs2 + 1);
//         }
//         if (dfs1 > -1){
//             return dfs1 + 1;
//         }
//         if (dfs2 > -1){
//             return dfs2 + 1;
//         }
//         return -1;
//     }
//     if (d_flag){
//         ll dfs1 = dfs(n/a);
//         if (dfs1 > -1){
//             return dfs1+1;
//         }
//         return -1;
//     }
//     if (f_flag){
//         ll dfs1 = dfs(flipped);
//         if (dfs1 > -1){
//             return dfs1+1;
//         }
//         return -1;
//     }
//     // cout << (ll)(n/pow(10,(ll)log10(n))) << endl;
//     return 0;
//     // return min(dfs(n/a),dfs(n));
// }

// int main(void) {
//     ll n;
//     cin >> a >> n;
//     ll ans = dfs(n);
//     cout << ans << endl;
//     return 0;
// }


// // #include<iostream>
// // #include<string>
// // #include<math.h>
// // #include<algorithm>
// // #include<functional>
// // #include<vector>
// // using namespace std;

// // int smallest = 1000000;

// // vector<int> the_vect;

// // bool solve(int a, int N){
// //     cout << a << " " << N << endl;
// //     if (N == 1) return true;
// //     if (N%a == 0){
// //         if (solve(a, N/a)) return true;
// //     }
// //     if (N > 9){
// //         if (solve(a, (N%10)*pow(10,(int)(log10(N)))+(int)(N/10))) return true;
// //     }
// //     return false;
// // }

// // int main() {
// //     int a, N;
// //     cin >> a >> N;
// //     return 0;
// // }