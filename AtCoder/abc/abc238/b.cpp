#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll current = 0;
    vector<bool> cuts(361);
    for (auto i : cuts){
        i = false;
    }
    cuts[0] = true;
    cuts[360] = true;
    for (auto i = 0; i < n; i++){
        cin >> a[i];
        current += a[i];
        if (current > 359){
            current -= 360;
        }
        // cout << current << endl;
        cuts[current] = true;
    }
    vector<ll> pieces;
    ll last_ = 0;
    for (auto i = 0; i < 361; i++){
        if (cuts[i] == true){
            pieces.push_back(i-last_);
            last_ = i;
        }
    }
    cout << *max_element(pieces.begin(),pieces.end()) << endl;
    // for (auto i : pieces){
    //     cout << i << endl;
    // }
    return 0;
}