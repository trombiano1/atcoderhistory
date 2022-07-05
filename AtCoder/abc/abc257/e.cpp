#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e9;
#define LINF 1e18;
#define all(x) begin(x), end(x)

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

int main(void) {
    ll n;
    cin >> n;
    vector<ll> c(9);
    ll c_min = LINF;
    for(int i = 0; i < 9; i++){
        cin >> c[i];
        c_min = min(c_min, c[i]);
    }
    ll digs = n/c_min;
    dump(digs);
    string res = "";
    for(int i = 0; i < digs; i++){
        for(int j = 8; j >= 0; j--){
            if (c[j] <= n - (digs-i-1)*c_min){
                res += (char)('0'+(j+1));
                n -= c[j];
                dump(j, c[j]);
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}