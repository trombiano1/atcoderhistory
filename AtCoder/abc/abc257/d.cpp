#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1001001001;
#define LINF 1001001001001001001ll;
#define all(x) begin(x), end(x)

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

ll n;
vector<vector<ll>> t;

bool check(ll x) {
    bool ok = false;
    for(int i = 0; i < n; i++){
        vector<bool> seen(n, false);
        queue<ll> que;
        
        seen[i] = true;
        que.push(i);
        
        while (!que.empty()) {
            ll v = que.front();
            que.pop();

            for (int nv = 0; nv < n; nv++){
                if (v == nv) continue;
                if (seen[nv]) continue;
                
                if (abs(t[nv][0] - t[v][0]) + abs(t[nv][1] - t[v][1]) <= x * t[v][2]){
                    seen[nv] = true;
                    que.push(nv);
                }
            }
        }
        bool allok = true;
        for(int j = 0; j < n; j++) if (!seen[j]) {
            allok = false;
            break;
        }
        if (allok){
            ok = true;
            break;
        }
    }
    return ok;
}

int main(void) {
    cin >> n;
    t.resize(n);
    for(int i = 0; i < n; i++){
        ll x, y, p;
        cin >> x >> y >> p;
        t[i] = {x, y, p};
    }
    ll ng = -1, ok = 4001001001ll;
    while (ng + 1 != ok) {
        ll md = (ng + ok) / 2;
        if (check(md)) ok = md;
        else ng = md;
    }
    cout << ok << endl;
    return 0;
}