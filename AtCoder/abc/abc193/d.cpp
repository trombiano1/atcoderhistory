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

ll point(vector<ll> c){
    vector<ll> cards(10,0);
    for (auto i : c){
        cards[i]++;
    }
    ll point = 0;
    for (auto i = 1; i <= 9; i++){
        point += i * pow(10,cards[i]);
    }
    return point;
}

int main(void) {
    ll k;
    string a_, b_;
    cin >> k;
    cin >> a_;
    cin >> b_;
    vector<ll> cards(10,k);
    cards[0] = 0;
    vector<ll> a(5,0);
    vector<ll> b(5,0);
    for (auto i = 0; i < 4; i++){
        a[i] = a_[i]-'0';
        cards[a[i]]--;
    }
    for (auto i = 0; i < 4; i++){
        b[i] = b_[i]-'0';
        cards[b[i]]--;
    }
    dump(a,b);
    dump(cards);
    ll a_count = 0;
    ll all_count = 0;
    for (auto i = 1; i <= 9; i++){
        vector<ll> c_cards = cards;
        if (cards[i] == 0) continue;
        a[4] = i;
        cards[i]--;
        for (auto j = 1; j <= 9; j++){
            if (cards[j] == 0) continue;
            b[4] = j;
            all_count += cards[j]*(cards[i]+1);
            // dump(a,b);
            if (point(a) > point(b)){
                a_count += cards[j]*(cards[i]+1);
            }
            dump(cards[j],a,b,point(a),point(b),point(a)>point(b));
        }
        cards[i]++;
    }
    dump(all_count, a_count);
    cout << setprecision(15) << (double)a_count/(double)all_count << endl;
    return 0;
}