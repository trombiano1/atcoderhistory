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
    ll a, b;
    cin >> a >> b;
    if (a == b){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}