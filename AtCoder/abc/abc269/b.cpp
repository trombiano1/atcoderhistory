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
    vector<string> s(10);
    for (int i = 0; i < 10; i++) {
        cin >> s[i];
    }
    int a = 11, b = 0, c = 11, d = 0;
    for (int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if (s[i][j] == '#') {
                a = min(a, j);
                b = max(b, j);
                c = min(c, i);
                d = max(d, i);
            }
        }
    }
    cout << c + 1 << " " << d + 1 << endl;
    cout << a + 1 << " " << b + 1 << endl;
    return 0;
}