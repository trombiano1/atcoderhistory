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
    int n;
    cin >> n;
    vector<ll> x(n);
    ll all = 0;
    for(int i = 0; i < n; i++){
        cin >> x[i];
        all ^= x[i];
    }
    for(int i = 0; i < n; i++){
        cout << (all ^ x[i]) << " ";
    }
    cout << endl;
    return 0;
}