#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    ll n, x;
    cin >> n >> x;
    x--;
    vector<bool> seen(n,false);
    vector<int> a(n);
    for(auto i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }
    ll count = 0;
    while (1){
        // cout << x << endl;
        if (seen[x] == true) break;
        seen[x] = true;
        count++;
        x = a[x];
    }
    cout << count << endl;
    return 0;
}