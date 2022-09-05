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
    int n, m;
    long long t;
    cin >> n >> m >> t;
    vector<long long> a(n - 1);
    for (int i = 0; i < n - 1; i++){
        cin >> a[i];
    }
    vector<long long> b(n);
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;
        b[x] = y;
    }
    string ans = "Yes";
    for (int i = 0; i < n - 1; i++){
        assert(t > 0);
        t += b[i];
        if (t <= a[i]){
            ans = "No";
            break;
        }
        t -= a[i];
    }
    cout << ans << endl;
    return 0;
}