#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    ll x;
    cin >> x;
    if (x < 40){
        cout << 40-x << endl;
        return 0;
    }
    if (x < 70){
        cout << 70-x << endl;
        return 0;
    }
    if (x < 90){
        cout << 90 - x << endl;
        return 0;
    }
    cout << "expert" << endl;
    return 0;
}