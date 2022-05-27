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

ll h, w;

pair<ll, ll> getcoord(ll n){
    pair<ll, ll> coord;
    coord.first = n / w;
    coord.second = n % w;
    return coord;
}

ll getnum(pair<ll,ll> coord){
    return coord.first * w + coord.second;
}

bool validcoord(pair<ll, ll> c){
    if (0 <= c.first && c.first < h && 0 <= c.second && c.second < w) return true;
    return false;
}

int main(void) {
    cin >> h >> w;
    ll N = h * w; // 頂点の数
    vector<bool> board(N);
    for (auto i = 0; i < h; i++){
        string s;
        cin >> s;
        for (auto j = 0; j < w; j++){
            if (s[j] == '.'){
                board[i*w+j] = true;
            }
        }
    }
    vector<vector<pair<ll,ll>>> G(N); // cost, to
    for (auto i = 0; i < N; i++){
        if (board[i]) for (auto a = -1; a <= 1; a++) for (auto b = -1; b <= 1; b++){
            if ((a + b)%2 == 0) continue;
            pair<ll, ll> newcoord = getcoord(i);
            newcoord.first += a;
            newcoord.second += b;
            if (validcoord(newcoord)) if(board[getnum(newcoord)]){
                G[i].push_back({0, getnum(newcoord)});
            }
            if (validcoord(newcoord)) if(!board[getnum(newcoord)]){
                G[getnum(newcoord)].push_back({0, i});
            }
        }
    }
    dump(G);
    for (auto i = 0; i < N; i++){
        for (auto a = -2; a <= 2; a++) for (auto b = -2; b <= 2; b++){
            if (abs(a) == 2 && abs(b) == 2) continue;
            if (a == 0 && b == 0) continue;
            pair<ll, ll> newcoord = getcoord(i);
            newcoord.first += a;
            newcoord.second += b;
            if (validcoord(newcoord)){
                G[i].push_back({1, getnum(newcoord)});
            }
        }
    }
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pque;
    vector<ll> dist(N, INF);
    dist[0] = 0;
    pque.push({0, 0});

    while (!pque.empty()) {
        // vは確定
        pair<ll,ll> p = pque.top();
        dump(pque.top(),pque,dist);
		ll d = p.first;
        ll v = p.second;
        pque.pop();
				
        // 最短以外は無視
        if (dist[v] < d) continue;

        // vに繋がってる点が更新できれば候補に入れる
        for (auto edge : G[v]) {
            if (dist[edge.second] > dist[v] + edge.first) {
                dist[edge.second] = dist[v] + edge.first;
                pque.push({dist[edge.second], edge.second});
            }
        }
    }
    dump(dist);
    cout << dist[N-1] << endl;
    return 0;
}