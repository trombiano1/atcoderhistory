#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    ll n;
    cin >> n;
    ll k = 1;
    ll k_total = 0;
    double a = (double)n;
    ll a_ll = (ll)a;
    double a_diff = 0;
    ll res = 0;
    while (1){
        k++;
        a_diff = (double)a - (double)n/k;
        a = (double)n/k;
        k_total += a_ll - (ll)a;
        res += (k-1)*(a_ll-(ll)a);
        if (a_ll - (ll)a  < 1) break;
        a_ll = (ll)a;
    }
    for (ll i = 1; i <= n - k_total; i++){
        res += (ll)(n/i);
    }
    cout << res << endl;
    return 0;
}