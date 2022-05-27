#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    ll n, x_, y_, max = 0, max_;
    cin >> n;
    vector<ll> x(n);
    vector<ll> y(n);
    for(auto i = 0; i < n; i ++){
        cin >> x_ >> y_;
        x[i] = x_;
        y[i] = y_;
    }
    for(auto i = 0; i < n-1; i++){
        for(auto j = i; j < n; j++){
            max_ = pow(x[i]-x[j],2)+pow(y[i]-y[j],2);
            if (max_ > max){
                max = max_;
            }
        }
    }
    cout << setprecision(15) << sqrt(max) << endl;
    return 0;
}