#include <bits/stdc++.h>

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using Graph = vector<vector<ll>>;

int main(void) {
    ll n, q;
    cin >> n >> q;
    Graph G(n);
    for (int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<ll> oe(n, -1);
    queue<ll> que;
    oe[0] = 0;
    que.push(0);
    while (!que.empty()){
        ll v = que.front();
        que.pop();
        for (ll nv: G[v]){
            if (oe[nv] != -1) continue;
            oe[nv] = (oe[v] + 1) % 2;
            que.push(nv);
        }
    }
    // for (int v = 0; v < n; ++v) cout << v << ": " << oe[v] << endl;
    for (ll i = 0; i < q; i++){
        int c, d;
        cin >> c >> d;
        c--; d--;
        if ((oe[c]+oe[d])%2 == 0) cout << "Town" << endl;
        else cout << "Road" << endl;
    }
    return 0;
}