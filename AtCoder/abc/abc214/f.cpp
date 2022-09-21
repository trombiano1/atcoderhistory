#include<bits/stdc++.h>
using namespace std;

int main(){
    string S; cin >> S;
    int N = S.size();
    vector<long long> dp(N+2); dp[0] = 1;
    for(int i = 0; i < N; i++){
        for(int j = i-1; ; j--){
            dp[i+2] = (dp[i+2] + dp[j+1]) % 1000000007;
            if(j == -1 || S[j] == S[i]) break;
        }
    }
    long long ans=0;
    for(int i = 2; i < N+2; i++) ans += dp[i];
    cout << ans%1000000007 << endl;
}
