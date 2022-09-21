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
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0;; i++) {
        assert(i < (int) s.size());
        if (s[i] == '1') {
            if (i % 2 == 0) {
                cout << "Takahashi" << endl;
                return 0;
            } else {
                cout << "Aoki" << endl;
                return 0;
            }
        }
    }
    return 0;
}