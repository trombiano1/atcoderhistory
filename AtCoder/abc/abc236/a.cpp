#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    string S;
    ll a, b;
    cin >> S;
    cin >> a >> b;
    for(auto i = 0; i < S.length(); i++){
        if (i == a - 1){
            cout << S[b-1];
        } else if (i == b-1){
            cout << S[a-1];
        } else {
            cout << S[i];
        }
    }
    cout << endl;
    return 0;
}