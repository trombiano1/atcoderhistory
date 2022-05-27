#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;

int main() {
    ll N, K;
    cin >> N >> K;
    ll A[N];
    for(auto i = 0; i < N; i++){
        cin >> A[i];
    }
    ll S[N];
    for(auto i = 0; i < N; i++){
        S[i+1] = A[i] + S[i];
    }
    ll ans = 0;
    map<ll, ll> mp;
    for(auto r = 1; r < N+1; r++){
        mp[S[r-1]]++;
        ans += mp[S[r] - K];
    }
    cout << ans << endl;
    return 0;
}