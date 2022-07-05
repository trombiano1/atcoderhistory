#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e9
#define LINF 100000000000000000LL
#define all(x) begin(x), end(x)

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

int main(void) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){cin >> a[i];}
    vector<ll> b(n);
    for(int i = 0; i < n; i++){cin >> b[i];}
    dump(a, b);
    vector<ll> a_size(n), b_size(n);
    set<ll> s_a, s_b;
    vector<ll> a_new, b_new;
    for(int i = 0; i < n; i++){
        if (s_a.count(a[i]) != 1){ // not included
            a_new.push_back(a[i]);
        }
        s_a.insert(a[i]);
        a_size[i] = (ll)s_a.size();

        if (s_b.count(b[i]) != 1){ // not included
            b_new.push_back(b[i]);
        }
        s_b.insert(b[i]);
        b_size[i] = (ll)s_b.size();
    }
    dump(a_size, b_size, a_new, b_new);
    int k_max = (int)max(a_new.size(), b_new.size());
    dump(k_max);
    vector<bool> res(n);
    set<ll> S;
    for(int i = 0; i < k_max; i++){
        if (S.count(a_new[i]) == 1){
            S.erase(a_new[i]);
        } else {
            S.insert(a_new[i]);
        }
        if (S.count(b_new[i]) == 1){
            S.erase(b_new[i]);
        } else {
            S.insert(b_new[i]);
        }
        dump(S);
        if (S.size() == 0) res[i] = true;
    }
    dump(res);
    ll q;
    cin >> q;
    for(int i = 0; i < q; i++){
        ll x, y;
        cin >> x >> y;
        x--; y--;
        if (a_size[x] != b_size[y]){
            cout << "No" << endl;
        } else {
            dump("same");
            if (res[a_size[x] - 1]){
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}