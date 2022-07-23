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
    vector<double> a(n);
    vector<double> b(n);
    double total = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        total += a[i] / b[i];
    }
    dump(a, b, total);
    total /= 2;
    dump(total);
    double res = 0;
    for(int i = 0;;i++){
        if (total > a[i] / b[i]){
            total -= a[i] / b[i];
            res += a[i];
        } else {
            res += total * b[i];
            break;
        }
    }
    cout << setprecision(20) << res << endl;
    return 0;
}