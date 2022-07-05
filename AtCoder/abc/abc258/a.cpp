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
    int k;
    cin >> k;
    if (k < 60){
        if (k < 10){
            cout << "21:0" << k << endl;
        } else {
            cout << "21:" << k << endl;
        }
    } else {
        k -= 60;
        if (k < 10){
            cout << "22:0" << k << endl;
        } else {
            cout << "22:" << k << endl;
        }
    }
    return 0;
}