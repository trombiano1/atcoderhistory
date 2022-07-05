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

vector<pair<ll,ll>> DIRS = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

int main(void) {
    ll n;
    cin >> n;
    vector<string> m(n);
    for(int i = 0; i < n; i++) cin >> m[i];
    dump(m);
    ll mx = -LINF;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < 8; k++){
                ll res = 0;
                for(int l = 0; l < n; l++){
                    res *= 10;
                    ll ni = (i + l * DIRS[k].first) % n;
                    if (ni < 0) ni += n;
                    ll nj = (j + l * DIRS[k].second) % n;
                    if (nj < 0) nj += n;
                    res += (ll)(m[ni][nj] - '0');
                }
                dump(res);
                mx = max(mx, res);
            }
        }
    }
    cout << mx << endl;
    return 0;
}