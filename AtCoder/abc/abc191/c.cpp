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

int main(void) {
    ll h, w;
    cin >> h >> w;
    vector<vector<bool>> s(h);
    for (auto i = 0; i < h; i++){
        string sin;
        cin >> sin;
        s[i].resize(w);
        for (unsigned long j = 0; j < sin.size(); j++){
            if (sin[j] == '#'){
                s[i][j] = true;
            } else {
                s[i][j] = false;
            }
        }
    }
    bool firstfound = false;
    ll res = 0;
    for (auto i = 1; i < h; i++){
        for (auto j = 1; j < w; j++){
            ll count = s[i-1][j-1] + s[i-1][j] + s[i][j-1] + s[i][j];
            if (count == 1 || count == 3){
                res++;
            }
        }
    }
    cout << res << endl;
    // vector<vector<bool>> vis(h);
    // for (auto i = 0; i < h; i++){
    //     vis[i].assign(w,false);
    // }
    // pair<ll,ll> pos = first_pos;
    // char m = 'a';
    // char first_m;
    // ll res = 0;
    // ll count = 0;
    // do {
    //     dump(pos);
    //     char last_m = m;
    //     vis[pos.first][pos.second] = true;
    //     bool ul = s[pos.first-1][pos.second-1];
    //     bool ur = s[pos.first-1][pos.second];
    //     bool dl = s[pos.first][pos.second-1];
    //     bool dr = s[pos.first][pos.second];
    //     // dump(ul,ur,dl,dr);
    //     bool u = (ul && !ur) || (!ul && ur);
    //     bool l = (ul && !dl) || (!ul && dl);
    //     bool r = (ur && !dr) || (!ur && dr);
    //     bool d = (dl && !dr) || (!dl && dr);
    //     // dump(u,l,d,r);
    //     if (u && pos.first-1 != 0 && !vis[pos.first-1][pos.second]){
    //         m = 'u';
    //         pos = make_pair(pos.first-1,pos.second);
    //     } else if (l && pos.second-1 != 0 && !vis[pos.first][pos.second-1]){
    //         m = 'l';
    //         pos = make_pair(pos.first,pos.second-1);
    //     } else if (d && pos.first+1 != h && !vis[pos.first+1][pos.second]){
    //         m = 'd';
    //         pos = make_pair(pos.first+1,pos.second);
    //     } else if (r && pos.second+1 != w && !vis[pos.first][pos.second+1]){
    //         m = 'r';
    //         pos = make_pair(pos.first,pos.second+1);
    //     } else {
    //         dump("end");
    //         dump(first_m);
    //         dump(u,l,r,d);
    //         vis[first_pos.first][first_pos.second] = false;
    //         if (u && pos.first-1 != 0 && !vis[pos.first-1][pos.second]){
    //             m = 'u';
    //             pos = make_pair(pos.first-1,pos.second);
    //         } else if (l && pos.second-1 != 0 && !vis[pos.first][pos.second-1]){
    //             m = 'l';
    //             pos = make_pair(pos.first,pos.second-1);
    //         } else if (d && pos.first+1 != h && !vis[pos.first+1][pos.second]){
    //             m = 'd';
    //             pos = make_pair(pos.first+1,pos.second);
    //         } else if (r && pos.second+1 != w && !vis[pos.first][pos.second+1]){
    //             m = 'r';
    //             pos = make_pair(pos.first,pos.second+1);
    //         }
    //         dump("last_m",m);
    //         if (m != first_m){
    //             res++;
    //         }
    //         break;
    //     }
    //     if (count == 0){
    //         first_m = m;
    //     }
    //     count++;
    //     dump(m);
    //     if (last_m != m && last_m != 'a'){
    //         res++;
    //     }
    // } while (pos != first_pos);
    // dump(res);
    // cout << res << endl;
    return 0;
}