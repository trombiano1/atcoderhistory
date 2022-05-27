#include <bits/stdc++.h>

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mod 1000000007

using namespace std;
using Graph = vector<vector<ll>>;

int main(void) {
    ll n, m;
    cin >> n >> m;
    Graph G(n);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<ll> dist(n, -1);
    vector<ll> ways(n, 0);
    queue<ll> que;
    
    dist[0] = 0;
    ways[0] = 1;
    que.push(0);

    while (!que.empty()){
        ll v = que.front();
        que.pop();
        for (ll nv : G[v]){
            if (dist[nv] != -1){
                if (dist[nv] == dist[v]+1){
                    ways[nv] += ways[v] % mod;
                    ways[nv] %= mod;
                }
            } else {
                dist[nv] = dist[v] + 1;
                que.push(nv);
                ways[nv] = ways[v];
                ways[nv] %= mod;
            }
        }
    }
    
    // for (int v = 0; v < n; ++v) cout << v << ": " << dist[v] << ways[v] << endl;
    cout << ways[n-1] << endl;

    return 0;
}