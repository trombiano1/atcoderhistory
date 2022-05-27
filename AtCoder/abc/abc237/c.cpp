#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    string s;
    cin >> s;
    ll last_a = 0;
    ll first_a = 0;
    ll last_i = 0;
    // cout << s.length() << endl;
    for(ll i = 0; i < s.length(); i++){
        if (s[i] != 'a'){
            s = s.substr(i, s.length());
            first_a = i;
            break;
        }
    }
    // cout << s << endl;
    for(ll i = s.length() - 1; i >= 0; i--){
        if (s[i] == 'a'){
        } else {
            // cout << "nope" << endl;
            last_a = s.length() - (i + 1);
            last_i = i;
            break;
        }
    }
    s = s.substr(0, last_i+1);
    // cout << s << endl;
    if (first_a > last_a){
        cout << "No" << endl;
        return 0;
    }
    // cout << s << endl;
    // cout << s << endl;
    for(ll i = 0; i < (s.length()+1) / 2; i++){
        // cout << i << " " << s.length()-1-i << endl;
        // cout << s[i] << s[s.length()-1-i] << endl;
        if (s[i] != s[s.length()-1-i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}