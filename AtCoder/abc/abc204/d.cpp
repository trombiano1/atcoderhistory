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
#define dump(...)															  \
    DUMPOUT << "  \033[1m" << string(#__VA_ARGS__) << "\033[0m: "							\
            << "\033[0;90m[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]\033[0m"		\
            << endl															\
            << "	" ,														 \
        dump_func(__VA_ARGS__)
#else
#define DEB if (false)
#define dump(...)
#endif
#pragma endregion dump

int main(void) {
    ll n;
    cin >> n;
    vector<ll> t(n);
    ll sum = 0;
    for (auto i = 0; i < n; i++){
        cin >> t[i];
        sum += t[i];
    }
    dump(sum);
    vector<bool> dp_last(sum+1,false);
    dp_last[sum] = true;
    vector<bool> dp(sum+1, false);
    for (auto k = 0; k < n; k++){
        for (auto i = 0; i < sum+1; i++){
            if (dp_last[i]){
                dp[i] = true;
            } else if (i + t[k] < sum + 1 && dp_last[i+t[k]]){
                dp[i] = true;
            } else {
                dp[i] = false;
            }
        }
        swap(dp,dp_last);
    }
    dump(dp);
    ll res = 0;
    if (sum %2 == 0){
        for (auto i = 0;;i++){
            if (dp[sum/2 + i] == true){
                res = max(sum/2+i, sum/2-i);
                dump(res);
                cout << res << endl;
                break;
            }
            if (dp[sum/2 - i] == true){
                res = max(sum/2+i, sum/2-i);
                dump(res);
                cout << res << endl;
                break;
            }
        }
    } else {
        for (auto i = 0;;i++){
            if (dp[(ll)(sum/2) + 1 + i] == true){
                res = max((ll)(sum/2)+1+i, sum-((ll)(sum/2)+1+i));
                dump(res,i,1);
                cout << res << endl;
                break;
            }
            if (dp[(ll)(sum/2) - i] == true){
                res = max((ll)(sum/2)-i, sum- ((ll)(sum/2)-i));
                dump(res,i,2);
                cout << res << endl;
                break;
            }
        }
    }
    return 0;
}