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
    int n;
    cin >> n;
    vector<pair<long double, long double>> c(n);
    for (int i = 0; i < n; i++){
        long double x, y;
        cin >> x >> y;
        c[i] = {atan2(y-1, x), atan2(y, x-1)};
    }
    sort(c.begin(), c.end(), [&](auto i, auto j){
        return i.second < j.second;
    });
    dump(c);
    long double now = 0;
    int ans = 0;
    for (auto p : c){
        if (now <= p.first){
            ans++;
            now = p.second;
        }
    }
    cout << ans << endl;
    return 0;
}