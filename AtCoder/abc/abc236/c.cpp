#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    ll n, m;
    string input;
    cin >> n >> m;
    map<string, int> mp;
    bool stops[n];
    for(auto i = 0; i < n; i++){
        stops[i] = false;
        cin >> input;
        mp[input] = i;
    }
    for(auto i = 0; i < m; i++){
        cin >> input;
        stops[mp[input]] = true;
    }
    for(auto i = 0; i < n; i++){
        if (stops[i]){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}