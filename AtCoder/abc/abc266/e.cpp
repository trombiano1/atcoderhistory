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
    vector<double> dp(n);
    dp[0] = 3.5;
    for (int i = 1; i < n; i++){
        double sum = 0;
        for (int j = 1; j <= 6; j++){
            if (j < dp[i-1]){
                sum += dp[i-1];
            } else {
                sum += j;
            }
        }
        dp[i] = sum/6.;
    }
    cout << fixed << setprecision(10) << dp[n-1] << endl;
    dump(dp);
    return 0;
}