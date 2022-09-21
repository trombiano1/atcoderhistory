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
    map<string, bool> mp;
    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        mp[s] = true;
    }
    if (mp["H"] && mp["2B"] && mp["HR"] && mp["3B"]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}