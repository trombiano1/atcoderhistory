#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

map<pair<int, int>, ll> mp;

int main(void) {
    ll n, x, y;
    cin >> n;
    pair<int, int> cities[n];
    for(auto i = 0; i < n; i++){
        cin >> x >> y;
        for(auto j = 0; j < i; j++){
            ll diff_x = x-cities[j].first;
            ll diff_y = y-cities[j].second;
            if (diff_x < 0){
                diff_x *= -1;
                diff_y *= -1;
            }
            if (diff_x == 0 && diff_y < 0){
                diff_y *= -1;
            }
            ll gcd_x_y = gcd(diff_x, diff_y);
            diff_x /= gcd_x_y;
            diff_y /= gcd_x_y;
            // cout << "(" << diff_x << "," << diff_y << ")" << endl;
            pair<int, int> new_pair = make_pair(diff_x,diff_y);
            mp[new_pair] += 1;
        }
        // ll gcd_x_y = gcd(x,y);
        // cout << x/gcd_x_y << " " << y/gcd_x_y << endl;
        cities[i] = make_pair(x,y);
    }
    cout << mp.size()*2 << endl;
    return 0;
}