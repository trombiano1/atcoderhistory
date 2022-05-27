#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll res = 0;
    ll p = 1;
    for (auto i = n-1; i >= 0;i--){
        // cout << "a[i]" << a[i] << endl;
        // cout << "a[i-1]" << a[i-1] << endl;
        // cout << p*(a[i]-a[i-1]) << endl;
        if (i > 0 && k >= p*(a[i]-a[i-1])){
            res += p * (a[i]*(a[i]+1)/2 - a[i-1]*(a[i-1]+1)/2);
            // cout << " i " << i << " res " << res << endl;
            k -= p*(a[i]-a[i-1]);
            p++;
        } else {
            ll m = (ll)(k/p);
            // cout << "m " << m << endl;
            // cout << a[0] << endl;
            if (m > a[i]) m = a[i];
            res += p * (a[i]*(a[i]+1)/2 - (a[i]-m)*(a[i]-m+1)/2);
            res += (k%p)*(a[i]-m);
            break;
        }
    }
    cout << res << endl;
    return 0;
}