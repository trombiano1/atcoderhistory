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
    int a, b;
    cin >> a >> b;
    if (max(a, b) >= 10){
        cout << -1 << endl;
        return 0;
    }
    if (min(a, b) < 1){
        cout << -1 << endl;
        return 0;
    }
    cout << a * b << endl;
    return 0;
}