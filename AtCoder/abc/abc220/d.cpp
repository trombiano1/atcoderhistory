#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<ll> a;
ll n;

ll dfs(int l, int pos){
    // cout << "(";
    // for(auto i : l){
    //     cout << i << " ";
    // }
    // cout << ")" << endl;
    if (pos >= n - 1) {
        if (l == a[0]) return 1;
        return 0;
    }
    ll pos_ = pos + 1;
    auto next = a[n-pos_];
    ll count = 0;
    // deque<ll> new_deque = l;
    // new_deque.pop_front();
    // new_deque.push_front(next);
    // new_deque.push_front((l[0] - next + 10)%10);
    count += dfs((l - next + 10)%10, pos_);
    // new_deque = l;
    for(int i = 0; i < 10; i++){
        if ((i*next)%10 == l){
            count += dfs(i, pos_);
        }
    }
    return count % 998244353;
}

int main(void) {
    cin >> n;
    a.resize(n);
    rep(i, n){
        cin >> a[i];
    }
    rep(i, 10){
        cout << dfs(i,0) << endl;
    }
    return 0;
}