#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mod 998244353

int main(void) {
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    vector<ll> b(n+1);
    for(auto i = 0; i < n; i++){
        ll a_;
        cin >> a_;
        a[i] = a_;
    }
    for(auto i = 0; i < n; i++){
        ll b_;
        cin >> b_;
        b[i] = b_;
    }
    ll bmax = 3001;
    // cout << n << " " << bmax+1 << endl;
    // vector<vector<ll>> dp(n+1); //[bmax+1];
    vector<ll> dp_lst(bmax+1);
    vector<ll> dp_nxt(bmax+1);
    // for (auto i : dp){
    //     i.resize(bmax+1);
    // }
    // cout << "a" << endl;
    for (auto i = 0; i <= bmax; i++){
        dp_lst[i] = 0;
        dp_nxt[i] = 0;
    }
    // cout << b[0] << 'k' << endl;
    for (auto i = a[0]; i <= b[0]; i++){
        dp_lst[i]++;
        dp_nxt[i]++;
    }
    for (auto i = 1; i < n; i++){
        for (auto j = 0; j <= bmax; j++){
            dp_lst[j] = dp_nxt[j];
        }
        for (auto j = 0; j <= bmax; j++){
            dp_nxt[j] = 0;
        }
        vector<ll> rui(bmax+1);
        rui[0] = dp_lst[0];
        for (ll k = 1; k <= bmax; k++){
            rui[k] = (rui[k-1] + dp_lst[k]) % mod;
            // cout << rui[k] << endl;
        }
        for (ll j = a[i]; j <= b[i]; j++){
            // for (ll k = a[i-1]; k <= min(j,b[i-1]); k++){
            //     dp[i][j] += dp[i-1][k];
            // }
            dp_nxt[j] = rui[j];
            // cout << j << " " << dp[i][j] << " " << rui[j] << endl;
        }
        // for (ll j = 0; j < bmax; j++){
        //     for (auto k = max(a[i+1],j); k <= b[i+1]; k++){
        //         dp[i+1][k] += dp[i][j];
        //         dp[i+1][k] %= mod;
        //     }

        //     // cout << endl;
        // }
        
    }
    ll res = 0;
    // for (auto i : dp[1]) cout << i << endl;
    // cout << endl;
    for (auto i : dp_nxt) res += i;
    cout << res % mod << endl;
    return 0;
}