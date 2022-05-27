#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    ll n, q, in, last_in;
    cin >> n >> q;
    vector<ll> a(n);
    vector<ll> diff(n);
    vector<ll> sum_diff(n);
    last_in = 0;
    for (auto i = 0; i < n; i++){
        cin >> in;
        a[i] = in;
        diff[i]  = in - last_in - 1;
        last_in = in;
    }
    sum_diff[0] = diff[0];
    for (auto i = 1; i < n; i++){
        sum_diff[i] = diff[i] + sum_diff[i-1];
    }
    for (auto p = 0; p < q; p++){
        // for (auto i : a){
        //     cout << i << endl;
        // }
        // cout << endl;
        // for (auto i : diff){
        //     cout << i << endl;
        // }
        // cout << endl;
        // for (auto i : sum_diff){
        //     cout << i << endl;
        // }
        ll k;
        cin >> k;
        // cout << endl;
        auto itr = lower_bound(sum_diff.begin(), sum_diff.end(), k);
        if (itr == sum_diff.begin()){
            cout << k << endl;
        } else {
            // cout << itr - sum_diff.begin() << endl;
            cout << k - sum_diff[itr - sum_diff.begin()-1] + a[itr - sum_diff.begin()-1] << endl;
        }
        // cout << a[itr - sum_diff.begin()]-1-(sum_diff[itr - sum_diff.begin()] - k) << endl;
    }
    return 0;
}