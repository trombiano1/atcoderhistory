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
    string s;
    cin >> s;
    bool okay1 = false, okay2 = false;
    for (int i = 1; i < 4; i++) {
        if (s[i] - '0' != s[i - 1] - '0') {
            okay1 = true;
        }
        if (s[i] - '0' != (s[i - 1] -  '0' + 1) % 10) {
            okay2 = true;
        }
    }
    if (okay1 && okay2) {
        cout << "Strong" << endl;
    } else {
        cout << "Weak" << endl;
    }
    return 0;
}