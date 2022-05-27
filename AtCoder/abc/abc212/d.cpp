#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    ll n;
    cin >> n;
    vector<ll> asdf(1000000);
    priority_queue<ll, vector<ll>, greater<ll>> q;
    ll sum = 0;
    for (auto i = 0; i < n; i++){
        ll c, x;
        cin >> c;
        if (c==1){
            cin >> x;
            q.push(x - sum);
        }
        if (c==2){
            cin >> x;
            sum += x;
        }
        if (c==3){
            cout << q.top() + sum << endl;
            q.pop();
        }
    }
    return 0;
}