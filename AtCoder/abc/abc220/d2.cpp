#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n){
        cin >> a[i];
    }
    vector<vector<ll>> dp(n);
    rep(i, n){
        dp[i].resize(10);
        for (auto j:dp[i]){
            j = 0;
        }
    }
    dp[0][a[0]] = 1;
    for (auto i = 0; i < n-1; i++){
        for (auto j = 0; j < 10; j++){
            dp[i+1][(j+a[i+1])%10] += dp[i][j];
            dp[i+1][(j+a[i+1])%10] %= 998244353;
            dp[i+1][(j*a[i+1])%10] += dp[i][j];
            dp[i+1][(j*a[i+1])%10] %= 998244353;
        }
    }
    rep(i, 10){
        cout << dp[n-1][i] << endl;
    }
    return 0;
}