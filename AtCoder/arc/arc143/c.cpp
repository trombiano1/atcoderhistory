#include <bits/stdc++.h>
using namespace std;
#define INF 1e18
#define ll long long
#define all(x) begin(x), end(x)

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif



int main(void) {
    dump("a");
    mint i;
    cin >> i;
    dump(i);
    ll n = 5;
    C(2 * n * n, 0);
    dump(C(5, 3));
    return 0;
}