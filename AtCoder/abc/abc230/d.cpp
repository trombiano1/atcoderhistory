#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<pair<ll,ll>> wall;

bool sortbysec(pair<ll, ll> &a, pair<ll, ll> &b){
    return (a.second < b.second);
}

int main(void) {
    ll n, d;
    cin >> n >> d;
    wall.resize(n);
    for (ll i = 0; i < n; i++){
        ll l, r;
        cin >> l >> r;
        l--; r--;
        wall[i] = make_pair(l,r);
    }
    sort(wall.begin(), wall.end(), sortbysec);
    ll x = -d-5;
    ll c = 0;
    for (auto i : wall){
        // cout << i.first+1 << " " << i.second+1 << endl;
        if (i.first > x + d - 1){
            // cout << "not destroyed yet " << i.second+1 << endl;
            x = i.second;
            c++;
        }
    }
    cout << c << endl;
    return 0;
}