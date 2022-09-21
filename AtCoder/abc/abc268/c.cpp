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
    cin >> n;
    vector<int> turn(n);
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        turn[(p - i + n) % n]++;
        turn[(p - i - 1 + n) % n]++;
        turn[(p - i + 1 + n) % n]++;
    }
    cout << *max_element(turn.begin(), turn.end()) << endl;
    return 0;
}