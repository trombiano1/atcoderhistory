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
    int h, w;
    long long c;
    cin >> h >> w >> c;
    vector<vector<long long>> a(h, vector<long long>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> a[i][j];
        }
    }
    const long long linf = 1e18;
    long long res = linf;
    for(int q = 0; q < 2; q++){
        vector<vector<long long>> dp(h, vector<long long>(w));
        dp[0][0] = a[0][0];
        for(int i = 1; i < h; i++){
            dp[i][0] = min(a[i][0], dp[i-1][0]+c);
        }
        for(int i = 1; i < w; i++){
            dp[0][i] = min(a[0][i], dp[0][i-1]+c);
        }
        for(int i = 1; i < h; i++){
            for(int j = 1; j < w; j++){
                dp[i][j] = min({a[i][j], dp[i-1][j]+c, dp[i][j-1]+c});
                dump(a[i][j], dp[i-1][j]+c, dp[i][j-1]+c);
            }
        }
        vector<vector<long long>> x(h, vector<long long>(w));
        x[0][0] = linf;
        for(int i = 1; i < h; i++){
            x[i][0] = dp[i-1][0] + c + a[i][0];
        }
        for(int i = 1; i < w; i++){
            x[0][i] = dp[0][i-1] + c + a[0][i];
        }
        for(int i = 1; i < h; i++){
            for(int j = 1; j < w; j++){
                x[i][j] = min(dp[i-1][j]+c+a[i][j], dp[i][j-1]+c+a[i][j]);
            }
        }
        dump(x);
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                res = min(res, x[i][j]);
            }
        }
        vector<vector<long long>> a_(h, vector<long long>(w));
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                a_[i][j] = a[i][w-j-1];
            }
        }
        swap(a_, a);
    }
    cout << res << endl;
    return 0;
}