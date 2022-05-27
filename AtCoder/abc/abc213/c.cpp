#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template <typename T>
vector<T> compress(vector<T> &X) {
    vector<T> vals = X;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (int i = 0; i < (int)X.size(); i++) {
        X[i] = lower_bound(vals.begin(), vals.end(), X[i]) - vals.begin();
    }
    return vals;
}

template <typename T>
vector<T> print_vect(vector<T> X){
    for (auto i : X){
        cout << i << endl;
    }
}

int main(void) {
    ll h, w, n, in, a_, b_;
    cin >> h >> w >> n;
    vector<ll> a;
    vector<ll> b;
    for (auto i = 1; i <= n; i++){
        cin >> a_ >> b_;
        a.push_back(a_);
        b.push_back(b_);
    }
    compress(a);
    compress(b);
    for (auto i = 0; i < n; i++){
        cout << a[i]+1 << " " << b[i]+1 << endl;
    }
    return 0;
}