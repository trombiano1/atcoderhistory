#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[i] *= 1000;
    }
    vector<long long> b(n);

    auto Check1 = [&](long long x){
        vector<long long> b(n);
        for (int i = 0; i < n; i++){
            b[i] = a[i] - x;
        }
        vector<long long> f(n), g(n);
        
        f[0] = b[0];
        g[0] = 0;
        for (int i = 1; i < n; i++){
            f[i] = max(f[i-1], g[i-1]) + b[i];
            g[i] = f[i-1];
        }
        if (g[n-1] >= 0 || f[n-1] >= 0){
            return false;
        } else {
            return true;
        }
    };

    long long ng = -1, ok = 1e14;
    while (ng + 1 != ok) {
        long long md = (ng + ok) / 2;
        if (Check1(md)) ok = md;
        else ng = md;
    }
    
    cout << fixed << (double)ng/1000. << endl;

    // divide
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[i] /= 1000;
    }

    auto Check2 = [&](long long x){
        vector<long long> b(n);
        for (int i = 0; i < n; i++){
            if (a[i] < x){
                b[i] = -1;
            } else {
                b[i] = 1;
            }
        }
        vector<long long> f(n), g(n);
        
        f[0] = b[0];
        g[0] = 0;
        for (int i = 1; i < n; i++){
            f[i] = max(f[i-1], g[i-1]) + b[i];
            g[i] = f[i-1];
        }
        if (g[n-1] > 0 || f[n-1] > 0){
            return false;
        } else {
            return true;
        }
    };

    ng = -1, ok = 1e10;
    while (ng + 1 != ok) {
        long long md = (ng + ok) / 2;
        if (Check2(md)) ok = md;
        else ng = md;
    }
    dump(ng, ok); // ng + 1 = ok
    cout << ng << endl;

    return 0;
}