#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll n = pow(2,20);

struct Node{
    ll value = -1;
};

int main(void) {
    ll q;
    cin >> q;
    set<pair<ll,ll>> u;
    u.insert(make_pair(0, n));
    u.insert(make_pair(-1,-1));
    u.insert(make_pair(n+1,n+1));
    // u.insert(make_pair(2,100));
    // u.insert(make_pair(101,170));
    // u.insert(make_pair(171,n));
    map<ll, Node> mp;
    for (ll i = 0; i < q; i++){
        ll t, x;
        cin >> t >> x;
        if (t == 1){
            ll h = x % n;
            auto itr = lower_bound(u.begin(),u.end(), make_pair(h, numeric_limits<ll>::min()));
            // cout << (*(prev(itr))).first << endl;
            // cout << (*(prev(itr))).first << " " << (*(prev(itr))).second << endl;
            if ((*(prev(itr))).second < h){
                mp[(*(itr)).first].value = x;
            } else {
                mp[h].value = x;
                pair<ll,ll> first, second;
                first = make_pair((*(prev(itr))).first,h-1);
                second = make_pair(h+1,(*(prev(itr))).second);
                u.erase(prev(itr));
                u.insert(first);
                u.insert(second);
            }
        }
        if (t == 2){
            x %= n;
            cout << mp[x].value << endl;
        }
        // for (auto itr = u.begin(); itr != u.end(); itr = next(itr)){
        //     // cout << (*itr.first << " " << itr.second << endl;
        //     cout << (*itr).first << " " << (*itr).second << endl;
        // }
    }
    return 0;
}

// #include <bits/stdc++.h>

// #define ll long long
// #define rep(i, n) for (int i = 0; i < (int)(n); i++)

// using namespace std;

// ll n = pow(2,20);

// struct Node{
//     ll value = -1;
// };

// int main(void) {
//     ll q;
//     cin >> q;
//     map<ll, Node> mp;
//     for (ll i = 0; i < q; i++){
//         ll t, x;
//         cin >> t >> x;
//         if (t == 1){
//             ll h = x % n;
//             for (;;){
//                 if (mp[h].value == -1){
//                     mp[h].value = x;
//                     break;
//                 }
//                 h = (h + 1)%n;
//             }
//         }
//         if (t == 2){
//             x %= n;
//             cout << mp[x].value << endl;
//         }
//     }
//     return 0;
// }