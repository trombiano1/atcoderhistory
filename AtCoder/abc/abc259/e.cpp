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
    map<ll, tuple<ll, ll, ll>> mp; //最大値, 個数, 場所
    for(int i = 0; i < n; i++){
        ll m;
        cin >> m;
        for(int j = 0; j < m; j++){
            ll p, e;
            cin >> p >> e;

            if (get<0>(mp[p]) < e){
                mp[p] = {e, 1, i};
            } else if (get<0>(mp[p]) == e) {
                get<1>(mp[p])++;
            }
        }
    }
    
    dump(mp);
    vector<bool> inout(n);
    for(auto i : mp){
        if (get<1>(i.second) == 1){
            inout[get<2>(i.second)] = true;
        }
    }
    dump(inout);
    ll res = accumulate(all(inout), 0);
    cout << min(res + 1ll, (ll)n) << endl;

    return 0;
}