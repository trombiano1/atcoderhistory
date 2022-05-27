#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    ll n, s, c=0;
    cin >> n;
    vector<bool> possible(1121,false);
    for(auto a = 1; a <= 150; a++){
        for (auto b = 1; b <= a; b++){
            // cout << a << " " << b << " " << 4*a*b + 3*a+3*b << endl;
            possible[4*a*b + 3*a + 3*b] = true;
        }
    }
    rep(i, n){
        cin >> s;
        if (possible[s]){
            c++;
        }
    }
    cout << n - c << endl;
    return 0;
}