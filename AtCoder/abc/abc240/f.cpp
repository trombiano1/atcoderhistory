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
    int t;
    cin >> t;
    for(int qy = 0; qy < t; qy++){
        int n;
        ll m;
        cin >> n >> m;
        m++;
        vector<ll> x(n), y(n);
        for(int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }
        dump(x, y);
        ll a=0, b=0;
        ll mx = x[0];
        ll count = 0;
        for(int i = 0; i < n; i++){
            if (count + y[i] > m){
                ll rest = m-count;
                a += rest * b + x[i] * rest * (rest+1) / 2;
                mx = max(mx, a);
                dump(mx, rest);
                break;
            }
            if (b >= 0 && b + x[i] * y[i] < 0 && i != 0){
                ll ti = b / (-1 * x[i]);
                ll cand = a + ti * b + x[i] * ti * (ti+1) / 2;
                dump(cand);
                mx = max(cand, mx);
                dump(mx);
            }
            a += y[i] * b + x[i] * y[i] * (y[i]+1) / 2;
            b += x[i] * y[i];
            count += y[i];
            dump(a,b);
        }
        mx = max(a, mx);
        cout << mx << endl;
    }
    return 0;
}