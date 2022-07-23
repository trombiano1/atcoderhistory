#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string ans = "No";
    auto f = [&](long long x, long long y, long long a, long long b) {
        long long z = x - (y + a - 1) / y;
        if (z * y >= b) {
            ans = "Yes";
        }
    };
    long long x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<long long> d = {a, b, c};
    for (int i = 0; i < 2; i++) {
        sort(d.begin(), d.end());
        do {
            long long z = x - (y + d[0] - 1) / y;
            if (z > 0) {
                f(z, y, d[1], d[2]);
                f(y, z, d[1], d[2]);
            }
        } while (next_permutation(d.begin(), d.end()));
        swap(x, y);
    }
    cout << ans << '\n';
    return 0;
}