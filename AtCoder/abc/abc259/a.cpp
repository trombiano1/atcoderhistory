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
    int n, m, x, t, d;
    cin >> n >> m >> x >> t >> d;
    dump(x, m);
    if (x > m){
        dump(t - (n-x) * d);
        cout << t - x*d + d * m << endl;
    } else {
        cout << t << endl;
    }
    return 0;
}