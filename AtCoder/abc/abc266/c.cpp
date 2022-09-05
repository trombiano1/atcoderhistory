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
    int ax, ay, bx, by, cx, cy, dx, dy;
    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
    if (((dy - ay)*(cx-ax) - (cy-ay)*(dx-ax)) * ((by - ay)*(cx-ax) - (cy-ay)*(bx-ax)) >= 0){
        cout << "No" << endl;
        return 0;
    }
    if (((ay - by)*(dx-bx) - (dy-by)*(ax-bx)) * ((cy - by)*(dx-bx) - (dy-by)*(cx-bx)) >= 0){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}