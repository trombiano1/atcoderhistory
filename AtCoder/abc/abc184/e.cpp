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
template <typename T>
ostream &operator<<(ostream &os, const priority_queue<T> &que) {
    os << "{";
    priority_queue<T> que_copy = que; ll i = 0;
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

ll h, w;

bool valid_coord(pair<ll, ll> p){
    if (0 <= p.first && p.first < h && 0 <= p.second && p.second < w) return true;
    return false;
}

int main(void) {
    cin >> h >> w;
    vector<vector<vector<pair<ll, pair<ll, ll>>>>> G(h);
    for (auto i = 0; i < h; i++){    
        G[i].resize(w);
    }
    dump(G);
    vector<string> town(h);
    vector<pair<ll,ll>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
    cin >> town;
    pair<ll,ll> start, goal;
    vector<vector<pair<ll,ll>>> alp(26);
    for (auto i = 0; i < h; i++){
        for (auto j = 0; j < w; j++){
            if (town[i][j] == '#') continue;
            if (town[i][j] == 'S') start = {i,j};
            if (town[i][j] == 'G') goal = {i,j};
            for (auto k = 0; k < 4; k++){
                ll new_i = i + dirs[k].first;
                ll new_j = j + dirs[k].second;
                if (valid_coord({new_i,new_j}) && town[new_i][new_j] != '#'){
                    G[i][j].push_back({1, {new_i,new_j}});
                }
            }
            if (town[i][j] - 'a' >= 0 && town[i][j] - 'a' < 26){
                alp[town[i][j]-'a'].push_back({i,j});
            }
        }
    }

    // for (auto i = 0; i < 26; i++){
    //     for (auto v : alp[i]){
    //         for (auto nv : alp[i]){
    //             if (v != nv) G[v.first][v.second].push_back({1, {nv.first, nv.second}});
    //         }
    //     }
    // }
    
    vector<vector<ll>> dist(h);
    for (auto i = 0; i < h; i++){
        dist[i].assign(w, INF);
    }
    
    priority_queue<pair<ll,pair<ll,ll>>, vector<pair<ll,pair<ll,ll>>>, greater<pair<ll,pair<ll,ll>>>> pque;
    
    dist[start.first][start.second] = 0;
    pque.push({0, start});

    vector<ll> alp_used(26, false);
    
    while (!pque.empty()) {
        pair<ll, pair<ll,ll>> p = pque.top();
        pque.pop();
        ll d = p.first; // dist (minなら確定)
        pair<ll,ll> v = p.second; // point name

        if (v == goal){
            cout << dist[v.first][v.second] << endl;
            return 0;
        }

        if (dist[v.first][v.second] < d) continue; // 最短以外は無視 else vは確定
    
        for (auto edge : G[v.first][v.second]) { // vに繋がってる点が更新できれば候補に入れる
            ll c = edge.first;
            pair<ll,ll> nv = edge.second;
            if (dist[nv.first][nv.second] > dist[v.first][v.second] + c) {
                dist[nv.first][nv.second] = dist[v.first][v.second] + c;
                pque.push({dist[nv.first][nv.second], nv});
            }
        }
        ll ch = town[v.first][v.second] - 'a';
        if (ch >= 0 && ch < 26 && !alp_used[ch]){
            alp_used[ch] = true;
            for (auto nv : alp[ch]){
                if (nv != v){
                    ll c = 1;
                    if (dist[nv.first][nv.second] > dist[v.first][v.second] + c) {
                        dist[nv.first][nv.second] = dist[v.first][v.second] + c;
                        pque.push({dist[nv.first][nv.second], nv});
                    }
                }
            }
        }
    }
    
    dump(dist);
    dump(G, alp);
    ll res = dist[goal.first][goal.second];
    if (res == INF){
        cout << -1 << endl;
    } else {
        cout << res << endl;
    }
    return 0;
}