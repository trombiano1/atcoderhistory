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
    int y;
    cin >> y;
    if (y % 4 == 0){
        cout << y + 2 << endl;
    } else if (y % 4 == 1){
        cout << y + 1 << endl;
    } else if (y % 4 == 2){
        cout << y << endl;
    } else {
        cout << y + 3 << endl;
    }
    return 0;
}