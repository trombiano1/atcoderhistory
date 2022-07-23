#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e9
#define LINF 100000000000000000LL
#define all(x) begin(x), end(x)

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

int main(void) {
    int n;
    cin >> n;
    map<ll, ll> mp;
    ll sum = 0;
    for (int i = 0; i < n; i++){
        ll a;
        cin >> a;
        mp[a]++;
        sum += a;
    }
    dump(mp, sum);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        ll b, c;
        cin >> b >> c;
        sum += c * mp[b];
        sum -= b * mp[b];
        mp[c] += mp[b];
        mp[b] = 0;
        cout << sum << endl;
    }
    return 0;
}