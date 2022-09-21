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
    long long x;
    cin >> x;
    vector<long long> bt;
    for (long long i = 0; i < 60; i++) {
        if (x & (1ll << i)) {
            bt.push_back(i);
        }
    }
    dump(bt);
    // {0, 1, ..., n-1} の部分集合の全探索
    int size = (int) bt.size();
    for (long long bit = 0; bit < (1<<size); ++bit) {
        long long res = 0;
        for (long long i = 0; i < size; ++i) {
            if (bit & (1<<i)) {
                res |= 1ll << bt[i];
            }
        }
        cout << res << endl;
    }
    return 0;
}