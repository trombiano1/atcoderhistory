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
    vector<ll> x(n);
    vector<ll> y(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
        cin >> y[i];
    }
    ll res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if (i == j) continue;
                if (j == k) continue;
                if (i == k) continue;
                
                // i = 1 j = 2
                ll y1 = y[i], y2 = y[j], x1 = x[i], x2 = x[j];
                if ((y[k] - y1) * (x2-x1) != (y2-y1) * (x[k]-x1)){
                    res++;
                }
                
            }
        }
    }
    cout << res / 6 << endl;
    return 0;
}