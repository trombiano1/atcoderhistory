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
    int t_max = 100100;
    // int t_max = 6;
    vector s(t_max, vector<long long>(5));    
    for (int i = 0; i < n; i++){
        int t, x;
        long long a;
        cin >> t >> x >> a;
        s[t][x] += a;
    }
    vector dp(t_max, vector<long long>(5));
    dp[0][0] = s[0][0];

    s[0][1] = 0;
    s[0][2] = 0;
    s[0][3] = 0;
    s[0][4] = 0;

    s[1][2] = 0;
    s[1][3] = 0;
    s[1][4] = 0;

    s[2][3] = 0;
    s[2][4] = 0;

    s[3][4] = 0;

    // dump(s);
    for (int i = 0; i < t_max-1; i++){
        for (int j = 0; j < 5; j++){
            if (j == 0){
                dp[i+1][j] = max(dp[i][0], dp[i][1]) + s[i+1][j];
                continue;
            }
            if (j == 4){
                dp[i+1][j] = max(dp[i][3], dp[i][4]) + s[i+1][j];
                continue;
            }
            dp[i+1][j] = max(dp[i][j-1], max(dp[i][j], dp[i][j+1])) + s[i+1][j];
        }
    }
    long long ans = 0;
    for (int i = 0; i < 5; i++){
        ans = max(dp[t_max-1][i], ans);
    }
    dump(dp);
    cout << ans << endl;
    return 0;
}