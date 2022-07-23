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
    vector<ll> a(n);
    ll a_sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a_sum += a[i];
    }
    ll x;
    cin >> x;
    dump(x/a_sum);
    ll res = 0;
    res += x/a_sum * n;
    x -= (x/a_sum)*a_sum;
    for(int i = 0; i < n; i++){
        x -= a[i];
        if (x < 0){
            cout << res + i + 1 << endl;
            return 0;
        }
    }
    return 0;
}