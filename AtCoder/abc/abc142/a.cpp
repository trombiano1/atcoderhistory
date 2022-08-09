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
    double n;
    cin >> n;
    cout << setprecision(10) << 1 - ((double)((int)n / 2) / n) << endl; 
    return 0;
}