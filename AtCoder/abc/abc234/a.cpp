#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll f(int x){
    return x*x + 2*x + 3;
}

int main(void) {
    ll t;
    cin >> t;
    cout << f(f(f(t)+t)+f(f(t))) << endl;
    return 0;
}