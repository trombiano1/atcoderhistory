#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    ll s,t,x;
    cin >> s >> t >> x;
    if (t < s){
        t += 24;
    }
    if ((s < x + 0.5 && x + 0.5 < t) || (s < x + 24 + 0.5 && x + 24 + 0.5 < t)){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}