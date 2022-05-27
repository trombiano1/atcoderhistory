#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll INF = 1e18;
#define dump(x)  cout << #x << " = " << (x) << endl;
#define VECCIN(x) for(auto&y: (x) )cin>>y
#define VECCOUT(x) for(auto&y: (x) )cout<<y<<" ";cout<<endl


int main(void) {
    ll n, x, y;
    cin >> n;
    cin >> x >> y;
    vector<vector<vector<ll>>> dp(n+1);
    vector<ll> a(n+1);
    vector<ll> b(n+1);
    for (auto i = 0; i <= n; i++){
        dp[i].resize(x+1);
        for (auto j = 0; j <= x; j++){
            dp[i][j].resize(y+1);
            fill(dp[i][j].begin(), dp[i][j].end(), INF);
        }
    }
    for (auto i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
    }
    dp[0][0][0] = 0;
    for (auto i = 1; i <= n; i++){
        for (auto j = 0; j <= x; j++){
            for (auto k = 0; k <= y; k++){
                dp[i][min(j+a[i],x)][min(k+b[i],y)] = 
                    min(dp[i][min(j+a[i],x)][min(k+b[i],y)], dp[i-1][j][k]+1);
                dp[i][j][k] = min(dp[i][j][k],dp[i-1][j][k]);
            }
        }
    }
    if (dp[n][x][y] == INF){
        cout << -1 << endl;
    } else {
        cout << dp[n][x][y] << endl;
    }
    return 0;
}