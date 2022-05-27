#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    ll n;
    cin >> n;
    if (n == 0){
        cout << "0000" << endl;
        return 0;
    }
    for (auto i = 0; i < 4-((int)log10(n)+1); i++){
        cout << "0";
    }
    cout << n << endl;
    return 0;
}