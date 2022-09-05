#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    
    dump(a, b);

    const long long inf = 1e18;
    long long res = inf;
    vector dp(n, vector(2, vector<long long>(2,inf)));
    dp[0][0][0] = a[0]; // 同じ色
    dp[0][0][1] = 0; // 違う色
    for (int i = 0; i < n-1; i++){
        for (int k = 0; k < 2; k++){
            // 0なら次は切らなくてよくて1
            dp[i+1][1][k] = min(dp[i+1][1][k], dp[i][0][k]);
            dp[i+1][0][k] = min(dp[i+1][0][k], dp[i][0][k]+a[i+1]+b[i]);
            // dp[i+1][0][k] = min(dp[i+1][1][k], dp[i][0][k] + [i+1]);

            // 1ならa[i]かb[i+1]を切る
            dp[i+1][1][k] = min(dp[i+1][1][k], dp[i][1][k]+b[i]); // b[i]を切ると次も1
            dp[i+1][0][k] = min(dp[i+1][0][k], dp[i][1][k]+a[i+1]); // a[i+1]を切ると次は0
        }
    }
    dump(dp);
    for (int i = 0; i < 2; i++){
        for (int k = 0; k < 2; k++){
            res = min(res, dp[n-1][i][k] + (i==k?b[n-1]:0));
        }
    }
    cout << res << endl;
    return 0;
}