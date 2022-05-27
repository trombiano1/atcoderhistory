#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    ll a,b;
    cin >> a >> b;
    for(auto i = 0; i < (ll)log10(max(a,b))+1; i++){
        // cout << (ll)(a / pow(10,i))%10 << endl;
        // cout << pow(10,i) << endl;
        // cout << (b / (ll)pow(10,i)) << endl;
        if ((ll)(a / (ll)pow(10,i))%10 + (ll)(b / (ll)pow(10,i))%10 > 9){
            cout << "Hard" << endl;
            return 0;
        }
    }
    cout << "Easy" << endl;
    return 0;
}