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
    ll h, w, K;
    cin >> h >> w >> K;
    vector<vector<bool>> mp(h);
    for (auto i = 0; i < h; i++){
        mp[i].resize(w);
        string s;
        cin >> s;
        for (auto j = 0; j < w; j++){
            if (s[j] == '.'){
                mp[i][j] = false;
            } else {
                mp[i][j] = true;
            }
        }
    }
    ll res = 0;
    for (int bit1 = 0; bit1 < (1<<h); ++bit1) {
        vector<bool> hor;
        hor.assign(h,false);
        for (int i = 0; i < h; ++i) {
            if (bit1 & (1<<i)) { // 列挙に i が含まれるか
                hor[i] = true;
            }
        }
        for (int bit2 = 0; bit2 < (1<<w); ++bit2) {
            vector<bool> ver;
            ver.assign(w,false);
            for (int j = 0; j < w; ++j) {
                if (bit2 & (1<<j)) { // 列挙に i が含まれるか
                    ver[j] = true;
                }
            }

            vector<vector<bool>> test(h);
            for (auto k = 0; k < h; k++){
                test[k].assign(w,false);
                for (auto l = 0; l < w; l++){
                    if (mp[k][l] == true && hor[k] == false && ver[l] == false){
                        test[k][l] = true;
                    }
                }
            }
            ll count = 0;
            for (auto k = 0; k < h; k++){
                for (auto l = 0; l < w; l++){
                    if (test[k][l] == true){
                        count++;
                    }
                }
            }
            dump(hor, ver,test, count);
            if (count == K){
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}