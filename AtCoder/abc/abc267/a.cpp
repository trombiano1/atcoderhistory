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
    if (s == "Monday") {
        cout << 5 << endl;
    } else if (s == "Tuesday") {
        cout << 4 << endl;
    } else if (s == "Wednesday") {
        cout << 3 << endl;
    } else if (s == "Thursday") {
        cout << 2 << endl;
    } else {
        cout << 1 << endl;
    }
    return 0;
}