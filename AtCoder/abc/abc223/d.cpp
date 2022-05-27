#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> G(n);
    vector<ll> c(n, 0);
    priority_queue<ll, vector<ll>, greater<ll>> u;
    vector<ll> res;
    for (auto i = 0; i < m; i++){
        ll a_, b_;
        cin >> a_ >> b_;
        a_--; b_--;
        c[b_]++;
        G[a_].push_back(b_);
    }
    for (unsigned long i = 0; i < c.size(); i++){
        if (c[i] == 0){
            u.push(i);
        }
    }
    for (auto j = 0; j < n; j++){
        if (u.empty()){
            cout << -1 << endl;
            return 0;
        }
        ll next = u.top();
        u.pop();
        res.push_back(next);
        for (auto i : G[next]){
            c[i]--;
            if (c[i] == 0){
                u.push(i);
            }
        }
    }
    for (auto i = 0; i < n-1; i++){
        cout << res[i]+1 << " ";
    }
    cout << res[n-1]+1 << endl;
    return 0;
}