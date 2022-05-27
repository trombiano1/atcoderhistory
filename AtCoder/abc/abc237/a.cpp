#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    ll n;
    cin >> n;
    // cout << (ll)pow(2,31) << endl;
    if (-(ll)pow(2,31) <= n && n < (ll)pow(2,31)){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}