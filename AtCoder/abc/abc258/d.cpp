#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e9
#define LINF 9000000000000000000LL
#define all(x) begin(x), end(x)

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

int main(void) {
    unsigned long long n, x;
    cin >> n >> x;
    unsigned long long res = 18000000000000000000ULL;
    unsigned long long t = 0;
    for(int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        t += a + b;
        dump(t);
        unsigned long long nt = t + (x - i - 1) * b;
        dump(nt);
        res = min(nt, res);
    }
    cout << res << endl;
    return 0;
}