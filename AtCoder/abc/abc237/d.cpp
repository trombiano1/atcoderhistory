#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    ll n;
    string s;
    cin >> n;
    cin >> s;
    vector<ll> positions(n+1);
    vector<ll> order(n+1);
    ll min = 0;
    ll max = 0;
    // cout << output << endl;
    for(ll i = s.length() - 1; i >= 0; i--){
        // cout << s[i] << endl;
        if (s[i] == 'R'){
            min--;
            positions[i] = min;
            // output = to_string(i) + ' ' + output;
        }
        if (s[i] == 'L'){
            max++;
            positions[i] = max;
            // output = output + ' ' + to_string(i);
        }
    }
    positions[n] = 0;
    for(auto i = 0; i < n + 1; i++){
        // cout << i << " " << positions[i] - min << endl;
        order[positions[i]-min] = i;
    }
    for(auto i = 0; i < n + 1; i++){
        cout << order[i];
        if (i != n){
            cout << " ";
        }
    }
    cout << endl;
    // for(auto i = 0; i < n; i++){
    //     cout << output[i] << " " << endl;
    // }
    return 0;
}


