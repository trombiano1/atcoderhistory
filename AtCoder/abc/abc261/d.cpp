#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e9
#define LINF 100000000000000000LL
#define all(x) begin(x), end(x)

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<ll> x(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    vector<ll> c(n+1, 0);
    for(int i = 0; i < m; i++){
        int c_;
        ll y;
        cin >> c_ >> y;
        c[c_] = y;
    }
    dump(c);
    vector<vector<ll>> dp(n+1);
    for(int i = 0; i < n+1; i++){
        dp[i].assign(n+1, -LINF);
    }
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (dp[i][j] != -LINF){
                dp[i+1][0] = max(dp[i+1][0], dp[i][j] + c[0]);
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + x[i] + c[j+1]);
            }
        }
    }
    dump(dp);
    ll res = 0;
    for(int i = 0; i < n+1; i++){
        res = max(res, dp[n][i]);
    }
    cout << res << endl;
    return 0;
}

