#include <bits/stdc++.h>

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using Graph = vector<vector<ll>>;

int main(void) {
    ll n, m;
    cin >> n >> m;
    Graph G(n);
    for (auto i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
    }
    ll count = 0;
    for (ll i = 0; i < n; i++){
        vector<ll> seen(n, false);
        queue<ll> que;
        seen[i] = true;
        que.push(i);
        
        while (!que.empty()){
            ll v = que.front();
            que.pop();
            for (ll nv : G[v]){
                if (seen[nv] != false) continue;
                seen[nv] = true;
                que.push(nv);
            }
        }
        for (int v = 0; v < n; ++v){
            // cout << v << ": " << seen[v] << endl;
            if (seen[v]) count++;
        }
    }
    cout << count << endl;
    return 0;
}
