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
    long long x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    map<pair<int, long long>, long long> mp;
    function<long long(long long, int)> Rec = [&](long long cost, int i){
        assert(cost % a[i] == 0 && cost >= 0);
        if (mp.count({i, cost})){
            return mp[{i, cost}];
        }
        if (i + 1 == n){
            return cost / a[i];
        }
        long long val = min((cost%a[i+1])/a[i] + Rec(cost - (cost%a[i+1]), i+1),
        (a[i+1] - (cost%a[i+1]))/a[i] + Rec(cost - (cost%a[i+1]) + a[i+1], i+1));
        mp[{i, cost}] = val;
        return val;
    };
    cout << Rec(x, 0) << endl;
    return 0;
}