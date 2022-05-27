#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    ll n, k, a;
    cin >> n >> k >> a;
    k--;
    a--;
    cout << (a + k)% n + 1 << endl;
    return 0;
}