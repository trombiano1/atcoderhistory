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
#define dump(...)															  \
    DUMPOUT << "\033[0;90m[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]\033[0m"		\
            << endl															\
            << " " ,														 \
        dump_func(#__VA_ARGS__,__VA_ARGS__)
#else
#define DEB if (false)
#define dump(...)
#endif
#pragma endregion dump

int main(void) {
    ll n;
    cin >> n;
    double res = 0;
    for (auto i = 1; i < n; i++){
        res += (double)n/((double)n-(double)i);
    }
    cout << setprecision(20) << res << endl;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define INF 1e18
// #define ll long long

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
// #define dump(...)															  \
//     DUMPOUT << "\033[0;90m[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]\033[0m"		\
//             << endl															\
//             << " " ,														 \
//         dump_func(#__VA_ARGS__,__VA_ARGS__)
// #else
// #define DEB if (false)
// #define dump(...)
// #endif
// #pragma endregion dump

// int main(void) {
//     ll n;
//     cin >> n;
//     vector<ll> dp_last(n,0);
//     //初期化
//     double res = 0;
//     dp_last[n-1] = 1;
//     for (auto j = 0; j < 1000; j++){
//         vector<ll> dp(n,0);
//         for (auto i = n-1; i > 0; i--){
//             dp[i] += (n-i)*dp_last[i];
//             dp[i-1] += (i)*dp_last[i];
//         }
//         swap(dp,dp_last);
//         // dump(dp_last);
//         res += (double)(j+1)*(double)dp_last[0]*pow((1.0/(double)n),(double)(j+1));
//         if (j<10) dump(dp);
//     }
//     cout << setprecision(20) << res << endl;
//     return 0;
// }