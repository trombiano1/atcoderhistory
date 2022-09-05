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
    int x, y, n;
    cin >> x >> y >> n;
    cout << min(n*x, (n/3)*y + (n%3)*x) << endl;
    return 0;
}