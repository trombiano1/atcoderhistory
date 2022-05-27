#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    ll q;
    cin >> q;
    queue<ll> que;
    priority_queue<ll, vector<ll>, greater<ll>> sorted_que;
    for (auto i = 0; i < q; i++){
        ll c;
        cin >> c;
        if (c == 1){
            ll x;
            cin >> x;
            que.push(x);
        }
        if (c == 2){
            if (!sorted_que.empty()){
                cout << sorted_que.top() << endl;
                sorted_que.pop();
            } else {
                cout << que.front() << endl;
                que.pop();
            }
        }
        if (c == 3){
            while (!que.empty()){
                sorted_que.push(que.front());
                que.pop();
            }
        }
    }
    return 0;
}