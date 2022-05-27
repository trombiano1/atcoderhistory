#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    ll a, b;
    cin >> a >> b;
    if (6 * a < b){
        cout << "No" << endl;
    } else if (a > b){
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}