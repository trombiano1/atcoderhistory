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
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    int res = min(r1, r2) - max(l1, l2);
    if (res < 0) res = 0;
    cout << res << endl;
    return 0;
}