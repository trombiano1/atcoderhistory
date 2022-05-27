#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<pair<ll,ll>> t;

void print_train(ll pos){
    deque<ll> train;
    // cout << t[pos].first << " " << t[pos].second << endl;
    train.push_back(pos);
    ll next_pos = pos;
    while (1){
        next_pos = t[next_pos].second;
        if (next_pos == -1) break;
        train.push_back(next_pos);
    }
    next_pos = pos;
    while (1){
        assert(next_pos != 0);
        // cout << next_pos << endl;
        // cout << t[next_pos].first << " " << t[next_pos].second << endl;
        next_pos = t[next_pos].first;
        if (next_pos == -1) break;
        train.push_front(next_pos);
    }
    // cout << "train" << endl;
    cout << train.size() << " ";
    for (unsigned long i = 0; i < train.size(); i++){
        if (i == train.size()-1) cout << train[i] << endl;
        else cout << train[i] << " ";
    }
}

int main(void) {
    ll n, q, c, x, y;
    cin >> n >> q;
    t.resize(n+1);
    rep(i, n+1){
        t[i] = pair(-1,-1);
    }
    rep(i, q){
        cin >> c;
        if (c == 1){
            cin >> x >> y;
            t[x].second = y;
            t[y].first = x;
        }
        if (c == 2){
            cin >> x >> y;
            t[x].second = -1;
            t[y].first = -1;
        }
        if (c == 3){
            cin >> x;
            print_train(x);
        }
    }
    return 0;
}