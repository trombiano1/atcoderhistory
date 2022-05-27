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

void print_queue(priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> q)
{
  while (!q.empty())
  {
    dump(q.top());
    q.pop();
  }
}

int main(void) {
    ll n, C;
    cin >> n >> C;
    vector<ll> a(n), b(n), c(n);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> que_start;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> que_end;
    for (auto i = 0; i < n; i++){
        cin >> a[i] >> b[i] >> c[i];
        que_start.push(make_pair(a[i],c[i]));
        que_end.push(make_pair(b[i]+1,c[i]));
    }
    ll current_date = 0;
    ll current_cost = 0;
    ll res = 0;
    while (!que_end.empty()){
        // dump(current_date, current_cost, res);
        print_queue(que_start);
        print_queue(que_end);
        if (!que_start.empty()){
            if (que_start.top().first > que_end.top().first){
                // dump(current_cost * (que_end.top().first - current_date));
                if (current_cost > C){
                    res += C * (que_end.top().first - current_date);
                } else {
                    res += current_cost * (que_end.top().first - current_date);
                }
                current_date = que_end.top().first;
                current_cost = current_cost - que_end.top().second;
                que_end.pop();
            } else {
                // dump(current_cost * (que_start.top().first - current_date));
                if (current_cost > C){
                    res += C * (que_start.top().first - current_date);
                } else {
                    res += current_cost * (que_start.top().first - current_date);
                }
                current_date = que_start.top().first;
                current_cost = current_cost + que_start.top().second;
                que_start.pop();
            }
        } else {
            // dump(current_cost * (que_end.top().first - current_date));
            if (current_cost > C){
                res += C * (que_end.top().first - current_date);
            } else {
                res += current_cost * (que_end.top().first - current_date);
            }
            current_date = que_end.top().first;
            current_cost = current_cost - que_end.top().second;
            que_end.pop();
        }
    }
    dump(res);
    cout << res << endl;
    return 0;
}