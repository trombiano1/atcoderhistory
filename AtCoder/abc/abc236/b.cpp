#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    ll n, input;
    cin >> n;
    map<ll, ll> mp;
    for(auto i = 0; i < 4*n-1; i++){
        cin >> input;
        mp[input]++;
    }
    for(auto i = 1; i <= n; i++){
        if (mp[i] != 4){
            cout << i << endl;
            return 0;
        }
        
    }
    return 0;
}