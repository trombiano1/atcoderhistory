#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll nthDigit(ll a, ll n)
{
    n++;
    // Skip N-1 Digits in Base B
    for (ll i = 1; i < n; i++)
        a = a / 2;
    // Nth Digit from right in Base B
    return a % 2;
}

int main(void) {
    ll t;
    cin >> t;
    for (ll k = 0; k < t; k++){
        bool nope = false;
        ll a, s;
        cin >> a >> s;
        ll dig = max((int)log2(a) + 1, (int)log2(s)+1);
        // cout << "dig" << dig << endl;
        ll c = 0;
        for (ll i = 0; i < dig; i++){
            // cout << c << endl;
            ll a_ = nthDigit(a, i);
            ll s_ = nthDigit(s, i);

            if (a_ == 0 && s_ == 0){
                continue;
            }
            if (a_ == 0 && s_ == 1){
                // if (c == 1){
                //     c = 0;
                //     continue;
                // } else {
                //     cout << "No1" << i << endl;
                //     nope = true;
                // }
                c = 0;
                
            }
            if (a_ == 1 && s_ == 0){
                if (c == 1){
                    cout << "No" << endl;
                    nope = true;
                } else {
                    c = 1;
                }
            }
            if (a_ == 1 && s_ == 1){
                if (c == 1){
                    continue;
                } else {
                    cout << "No" << endl;
                    nope = true;
                }
            }
            if (nope) break;
        }
        if (!nope && c == 0) cout << "Yes" << endl;
        else if (!nope) cout << "No" << endl;
    }
    return 0;
}