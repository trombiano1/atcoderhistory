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
    int q;
    cin >> q;
    multiset<ll> s;
    for(int i = 0; i < q; i++){
        int t;
        ll x;
        cin >> t >> x;
        if (t == 1){
            s.insert(x);
        } else if (t == 2){
            int k;
            cin >> k;
            auto itr = s.upper_bound(x);
            bool broken = false;
            for(int j = 0; j < k; j++){
                if (itr != s.begin()){
                    itr--;
                } else {
                    broken = true;
                    break;
                }
            }
            if (broken){
                cout << -1 << endl;
            } else {
                cout << *itr << endl;
            }
        } else {
            int k;
            cin >> k;
            auto itr = s.lower_bound(x);
            bool broken = false;
            for(int j = 0; j < k - 1; j++){
                if (itr != s.end()){
                    itr++;
                } else {
                    broken = true;
                    break;
                }
            }  
            if (broken){
                cout << -1 << endl;
            } else {
                if (itr == s.end()) cout << -1 << endl;
                else cout << *itr << endl;
            }
        }
        dump(s);
    }
    return 0;
}