#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    ll n;
    cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> a;
    priority_queue<ll, vector<ll>, greater<ll>> c;
    vector<ll> d(n+1);
    for (auto i = 0; i < n; i++){
        d[i] = 0;
    }
    for (auto i = 0; i < n; i++){
        ll a_, b_;
        cin >> a_ >> b_;
        a.push(a_);
        c.push(a_+b_-1);
    }
    ll k = 0;
    ll last = 0;
    for (auto i = 0;!a.empty();i++){
        // cout << "a" << a.top() << endl;
        // cout << a.top() << " to " << last << ": " << k << endl;
        d[k] += a.top()-last;
        last = a.top();
        a.pop();
        k++;
        // cout << k << endl;
        while (c.top() < a.top()){
            // cout << "c" << c.top()+1 << endl;
            // cout << c.top()+1 << " to " << last << ": " << k << endl;
            d[k] += c.top()+1-last;
            last = c.top()+1;
            k--;
            c.pop();
            // cout << k << endl;
        }
    }
    for (auto i = 0; !c.empty(); i++){
        // cout << c.top()+1 << " to " << last << ": " << k << endl;
        d[k] += c.top()+1-last;
        last = c.top()+1;
        k--;
        c.pop();
        // cout << k << endl;
    }
    for (auto i = 0; i < n-1; i++){
        cout << d[i+1] << " ";
    }
    cout << d[n] << endl;
    return 0;
}