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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n), c(m), d(m);
    vector<tuple<ll, ll, ll>> bc;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < m; i++) cin >> c[i];
    for(int i = 0; i < m; i++) cin >> d[i];
    for(int i = 0; i < n; i++){
        bc.push_back({a[i], 0, b[i]});
    }
    for(int i = 0; i < m; i++){
        bc.push_back({c[i], 1, d[i]});
    }
    sort(all(bc), greater<>());
    dump(bc);
    multiset<ll> s;
    for(int i = 0; i < m+n; i++){
        dump(s);
        if (get<1>(bc[i]) == 1){ // choco
            s.insert(get<2>(bc[i]));
        }
        if (get<1>(bc[i]) == 0){
            auto itr = s.lower_bound(get<2>(bc[i]));
            if (itr == s.end()){
                cout << "No" << endl;
                return 0;
            } else {
                s.erase(itr);
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}