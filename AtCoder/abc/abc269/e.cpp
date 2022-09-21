#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

int main(void) {
    int n;
    cin >> n;
    int low = 0, high = n;
    int a, b;
    while (low + 1 != high) {
        int md = (low + high) / 2;
        // if (check(md)) low = md;
        cout << "? " << low + 1 << " " << md << " " << 1 << " " << n << endl;
        int t;
        cin >> t;
        dump(md - low + 1, t);
        if (t != md - low) {
            high = md;
        } else {
            low = md;
        }
        a = low;
    }

    low = 0, high = n;
    while (low + 1 != high) {
        int md = (low + high) / 2;
        // if (check(md)) low = md;
        cout << "? 1 " << n  << " " << low + 1 << " " << md << endl;
        int t;
        cin >> t;
        if (t != md - low) {
            high = md;
        } else {
            low = md;
        }
        b = low;
        dump(md, low, b);
    }
    cout << "! " << a + 1 << " " << b + 1 << endl;

    return 0;
}