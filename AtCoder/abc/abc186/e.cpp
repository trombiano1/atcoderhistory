#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        long long n, s, k;
        cin >> n >> s >> k;
        long long g = gcd(n, gcd(s, k));
        n /= g;
        s /= g;
        k /= g;
        if (gcd(n, k) != 1){
            cout << -1 << endl;
            continue;
        }
        if (-s * modinv(k, n) < 0){
            cout << -s * modinv(k, n) % n + n << endl;
        } else {
            cout << -s * modinv(k, n) << endl;
        }
    }
    return 0;
}