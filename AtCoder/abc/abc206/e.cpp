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
    int l, r;
    cin >> l >> r;
    vector<long long> x(r + 1);
    for (int i = 2; i <= r; i++) {
        x[i] = (r / i) - ((l - 1) / i);
    }

    vector<long long> just(r + 1);
    for (int i = r; i >= 1; i--) {
        long long res = x[i] * x[i];
        for (int j = 2; j * i <= r; j++) {
            res -= just[j * i];
        }
        just[i] = res;
    }

    long long ans = 0;
    for (int i = 2; i <= r; i++) {
        ans += just[i];
        if (l <= i && 2 <= i && i <= r) {
            ans -= 2 * x[i] - 1;
        }
    }
    cout << ans << endl;
    return 0;
}