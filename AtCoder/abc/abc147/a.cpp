#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e9
#define LINF 100000000000000000LL
#define all(x) begin(x), end(x)

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

int main(void) {
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    if (a1 + a2 + a3 >= 22){
        cout << "bust" << endl;
    } else {
        cout << "win" << endl;
    }
    return 0;
}