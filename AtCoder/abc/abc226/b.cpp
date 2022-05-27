#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    ll n;
    cin >> n;
    set<vector<ll>> s;
    for (auto i = 0; i < n; i++){
        ll l;
        cin >> l;
        vector<ll> a(l);
        for (auto j = 0; j < l; j++){
            cin >> a[j];
        }
        s.insert(a);
    }
    cout << s.size() << endl;
    return 0;
}