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
    ll a;
    double b;
    cin >> a >> b;
    double c = b * 100;
    cout << a*c << endl;
    dump(a, b, c);
    cout << (ll)((a * c)/100) << endl;
    return 0;
}