#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    ll n, x, y;
    ll c = 0;
    cin >> n;
    map<pair<ll, ll>, bool> a;
    vector<pair<ll, ll>> p(n);
    for(auto i = 0; i < n; i++){
        cin >> x >> y;
        a[make_pair(x,y)] = true;
        p[i] = make_pair(x,y);
    }
    for (auto i = 0; i < p.size(); i++){
        for (auto j = 0; j < i; j++){
            ll i_ = i;
            ll j_ = j;
            if (p[i_].first > p[j_].first) swap(i_,j_);
            if (p[i_].first >= p[j_].first) continue;
            if (p[i_].second >= p[j_].second) continue;
            // cout << "(" << p[i_].first << "," << p[i_].second << ") (" << p[j_].first << "," << p[j_].second << ")" << endl;
            if (a[make_pair(p[i_].first,p[j_].second)] && a[make_pair(p[j_].first,p[i_].second)]) c++;
        }
    }
    // cin >> x >> y;
    // cout << a[make_pair(x,y)] << endl;
    cout << c << endl;
    return 0;
}