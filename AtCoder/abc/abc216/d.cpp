#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

using namespace std;

using Graph = vector<vector<ll>>;

// #include <bits/stdc++.h>
// using namespace std;
// struct Edge {
//     ll to;
// };
// using Graph = vector<vector<Edge>>;

/* topo_sort(G): グラフG をトポロジカルソート
    返り値: トポロジカルソートされた頂点番号
    計算量: O(|E|+|V|)
 */
vector<ll> topo_sort(const Graph &G) {  // bfs
    vector<ll> ans;
    ll n = (ll)G.size();
    vector<ll> ind(n);            // ind[i]: 頂点iに入る辺の数(次数)
    for (ll i = 0; i < n; i++) {  // 次数を数えておく
        for (auto e : G[i]) {
            ind[e]++;
        }
    }
    queue<ll> que;
    for (ll i = 0; i < n; i++) {  // 次数が0の点をキューに入れる
        if (ind[i] == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) {  // 幅優先探索
        ll now = que.front();
        ans.push_back(now);
        que.pop();
        for (auto e : G[now]) {
            ind[e]--;
            if (ind[e] == 0) {
                que.push(e);
            }
        }
    }
    return ans;
}

// vector<ll> topo_sort(const Graph &G){
//     vector<ll> ans;
//     ll n = (ll)G.size();
//     vector<ll> ind(n);
//     for (ll i = 0; i < n; i++){
//         for (auto e : G[i]){
//             ind[e]++;
//         }
//     }
//     queue<ll> que;
//     for (ll i = 0; i < n; i++){
//         if (ind[i] == 0){
//             que.push(i);
//         }
//     }
//     while (!que.empty()){
//         ll now = que.front();
//         ans.push_back(now);
//         que.pop();
//         for (auto e : G[now]){
//             ind[e]--;
//             if (ind[e] == 0){
//                 que.push(ind[e]);
//             }
//         }
//     }
//     return ans;
// }

int main(void) {
    ll n, m;
    cin >> n >> m;
    Graph G(n);
    for (auto i = 0; i < m; i++){
        ll k; cin >> k;
        ll last_in; cin >> last_in; last_in--;
        for (auto j = 1; j < k; j++){
            ll in; cin >> in; in--;
            G[last_in].push_back(in);
            last_in = in;
        }
    }
    vector<ll> ans;
    ans = topo_sort(G);
    if (ans.size() == n){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}