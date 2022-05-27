#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    ll n;
    ll out = 0;
    cin >> n;
    ll dig = (int)log10(n)+1;
    for(ll i = 1; i <= dig-1; i++) {
        // cout << ((9*(ll)pow(10,i-1) % 998244353 )*(9*(ll)pow(10,i-1)+1) % 998244353)/2 << endl;
        out += ((9*(ll)pow(10,i-1) % 998244353 )*((9*(ll)pow(10,i-1)+1)% 998244353) /2);
        out %= 998244353;
        // cout << "dig" << i;
        // cout << out << endl;
    }
    out += ((n - (ll)pow(10,dig-1) + 1) % 998244353)*((n - (ll)pow(10,dig-1) + 2) % 998244353) / 2;
    out %= 998244353;
    // cout << dig <<endl;
    cout << out << endl;
    return 0;
}