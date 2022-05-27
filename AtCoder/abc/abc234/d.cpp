#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    ll n, k, ans = 0;
    cin >> n >> k;
    vector<ll> p(n);
    vector<bool> a(n);
    for(auto i = 0; i < n; i++){
        cin >> p[i];
        p[i]--;
        a[i] = false;
    }
    for(auto i = 0; i < k; i++){
        a[p[i]] = true;
    }
    // for(auto i = 0; i < n; i++){
    //     cout << i+1 << " " << a[i] << endl;
    // }
    for(auto i = 0; i < n; i++){
        if (a[i] == true){
            ans = i;
            break;
        }
    }
    cout << ans+1 << endl;
    for(auto i = k; i < n; i++){
        // cout << "p " << p[i] << endl;
        a[p[i]] = true;
        if (p[i] > ans){
            for(auto j = ans+1; j < n; j++){
                if (a[j] == true){
                    ans = j;
                    break;
                }
            }
        }
        // cout << "ans " << ans << endl;
        // print_vect(a);
        cout << ans+1 << endl;
    }
    return 0;
}