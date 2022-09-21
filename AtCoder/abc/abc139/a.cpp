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
    string s, t;
    cin >> s >> t;
    int res = 0;
    for (int i = 0; i < (int) t.size(); i++) {
        if (s[i] == t[i]) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}