#include <bits/stdc++.h>
using namespace std;
#define INF 1e18
#define ll long long
#define all(x) begin(x), end(x)

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

int main(void) {
    vector<ll> a(3);
    for(int i = 0; i < 3; i++) cin >> a[i];
    ll mx = max({a[0], a[1], a[2]});
    dump(mx);
    ll ops = 0;
    for(int i = 0; i < 3; i++){
        ops += mx - a[i];
    }
    dump(ops);
    if (mx - ops >= 0){
        cout << mx << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}