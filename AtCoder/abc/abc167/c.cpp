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
    int n, m, x;
    cin >> n >> m >> x;
    vector<ll> c(n);
    vector<vector<ll>> a(n);
    for(int i = 0; i < n; i++){
        cin >> c[i];
        a[i].resize(m);
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    ll res = INF;
    // {0, 1, ..., n-1} の部分集合の全探索
    for (ll bit = 0; bit < (1<<n); ++bit) {
        vector<ll> S;
        for (ll i = 0; i < n; ++i) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                S.push_back(i);
            }
        }
        // SがUの部分集合
        ll pre_cost = 0;
        vector<ll> learned(m);
        bool ok = true;
        for(auto i : S){
            pre_cost += c[i];
            for(int j = 0; j < m; j++){
                learned[j] += a[i][j];
            }
        }
        for(int i = 0; i < m; i++){
            if (learned[i] < x){
                ok = false;
                break;
            }
        }
        if (ok){
            res = min(res, pre_cost);
        }
        dump(S);
    }
    if (res == INF){
        cout << -1 << endl;
    } else {
        cout << res << endl;
    }
    return 0;
}