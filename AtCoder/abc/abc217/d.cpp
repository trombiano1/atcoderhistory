#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    ll l, q;
    cin >> l >> q;
    set<ll> cuts;
    cuts.insert(0);
    cuts.insert(l);
    for (auto i = 0; i < q; i++){
        ll c, x;
        cin >> c >> x;
        if (c == 1){
            cuts.insert(x);
        }
        if (c==2){
            auto itr = cuts.lower_bound(x);
            cout << (*itr) - *(prev(itr)) << endl;
        }
    }
    return 0;
}