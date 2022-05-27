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
ostream &operator<<(ostream &os, const pair<T, U> &pair_var) {
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}
// vector
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    os << "{";
    for (int i = 0; i < (int)vec.size(); i++) {
        os << "\033[0;90m[" << i << "]:\033[0m" << vec[i] << (i + 1 == (int)vec.size() ? "" : ", ");
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
    DUMPOUT << " \033[1m" << varname << "\033[0m " << '\t' << head;
    if (sizeof...(Tail) > 0) {
        DUMPOUT << endl << " ";
    }
    dump_func(vas.substr(vas.find(",")+1, vas.size()), std::move(tail)...);
}
#ifdef DEBUG_
#define DEB
#define dump(...)                                                              \
    DUMPOUT << "\033[0;90m[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]\033[0m"        \
            << endl                                                            \
            << " " ,                                                         \
        dump_func(#__VA_ARGS__,__VA_ARGS__)
#else
#define DEB if (false)
#define dump(...)
#endif
#pragma endregion dump

bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b){
    return (a.second > b.second);
}

int main(void) {
    ll n, m, q;
    cin >> n >> m >> q;
    vector<pair<ll,ll>> nim(n);
    for (auto i = 0; i < n; i++){
        ll w, v;
        cin >> w >> v;
        nim[i] = make_pair(v,w);
    }
    vector<ll> x(m);
    for (auto i = 0; i < m; i++){
        cin >> x[i];
    }
    for (auto i = 0; i < q; i++){
        dump(i);
        ll l, r;
        cin >> l >> r;
        l--; r--;
        priority_queue<pair<ll,ll>> nim_que;
        for (auto j : nim){
            nim_que.push(make_pair(j.first,j.second));
        }
        vector<ll> box(m,-1);
        vector<bool> used(m, false);
        for (auto j = 0; j < m; j++){
            if (j < l || j > r){
                box[j] = x[j];
            }
        }
        sort(box.begin(),box.end());
        ll res = 0;
        while (!nim_que.empty()){
            pair<ll,ll> top_ = nim_que.top();
            nim_que.pop();
            dump(top_.first,top_.second);
            for (auto j = 0; j < m; j++){
                if (used[j]) continue;
                if (box[j] < top_.second) continue;
                res += top_.first;
                used[j] = true;
                dump(box,used);
                break;
            }
        }
        dump(res);
        cout << res << endl;
    }
    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;

// #define INF 1e18
// #define ll long long
// #define repi(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)

// #pragma region dump
// // vector
// template <typename T>
// istream &operator>>(istream &is, vector<T> &vec) {
//     for (T &x : vec) is >> x;
//     return is;
// }
// // pair
// template <typename T, typename U>
// ostream &operator<<(ostream &os, pair<T, U> &pair_var) {
//     os << "(" << pair_var.first << ", " << pair_var.second << ")";
//     return os;
// }
// // vector
// template <typename T>
// ostream &operator<<(ostream &os, const vector<T> &vec) {
//     os << "{";
//     for (int i = 0; i < (int)vec.size(); i++) {
//         os << vec[i] << (i + 1 == (int)vec.size() ? "" : ", ");
//     }
//     os << "}";
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

// void dump_func() {
//     DUMPOUT << endl;
// }
// template <class Head, class... Tail>
// void dump_func(Head &&head, Tail &&... tail) {
//     DUMPOUT << head;
//     if (sizeof...(Tail) > 0) {
//         DUMPOUT << ", ";
//     }
//     dump_func(std::move(tail)...);
// }
// #ifdef DEBUG_
// #define DEB
// #define dump(...)                                                              \
//     DUMPOUT << "  \033[1m" << string(#__VA_ARGS__) << "\033[0m: "                            \
//             << "\033[0;90m[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]\033[0m"        \
//             << endl                                                            \
//             << "    " ,                                                         \
//         dump_func(__VA_ARGS__)
// #else
// #define DEB if (false)
// #define dump(...)
// #endif
// #pragma endregion dump

// bool compare_by_b(pair<int, int> a, pair<int, int> b) {
//     if(a.second != b.second){
//         return a.second < b.second;
//     }else{
//         return a.first < b.first;
//     }
// }

// int main(void) {
//     ll n, m, q;
//     cin >> n >> m >> q;
//     vector<pair<ll, ll>> nim(n);
//     vector<ll> box(m+1);
//     for (auto i = 0; i < n; i++){
//         ll w, v;
//         cin >> w >> v;
//         nim[i] = make_pair(w,v);
//     }
//     for (auto i = 1; i <= m; i++){
//         cin >> box[i];
//     }
//     sort(nim.begin(),nim.end(),compare_by_b);
//     for (auto k = 0; k < q; k++){
//         ll l, r;
//         cin >> l >> r;
//         ll value = 0;
//         priority_queue<ll, vector<ll>, greater<ll>> pque;
//         for (auto j = 1; j < m+1; j++){
//             if (j < l || j > r){
//                 pque.push(box[j]);
//             }
//         }
//         while (!pque.empty()){
            
//         }
//     }
//     return 0;
// }