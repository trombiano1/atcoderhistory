#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    ll n;
    string s;
    deque<ll> a={n};
    for(ll i=n-1; i>=0; i--){
        if(s[i]=='L')a.push_back(i);
        else a.push_front(i);
    }
    for(ll i = 0; i <= n; i++){
        if (i<n) cout << a[i] << " ";
        else cout << a[i] << endl;
    }
    return 0;
}