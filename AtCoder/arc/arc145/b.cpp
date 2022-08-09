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
    long long n, a, b;
    cin >> n >> a >> b;
    if (n < a){
        cout << 0 << endl;
        return 0;
    }
    cout << (n/a-1) * min(a, b) + 1 + min(n % a, b - 1) << endl;
    return 0;
}