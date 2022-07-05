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
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    dump(a);
    vector<pair<int, ll>> p;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        if (p.size() >= 1 && p[p.size()-1].first == a[i]){
            p[p.size()-1] = {p[p.size()-1].first, p[p.size()-1].second+1};
            sum += 1;
            if (p[p.size()-1].second == p[p.size()-1].first){
                sum -= p[p.size()-1].second;
                p.pop_back();
            }
        } else {
            p.push_back({a[i], 1});
            sum += 1;
        }
        dump(p);
        cout << sum << endl;
    }
    return 0;
}