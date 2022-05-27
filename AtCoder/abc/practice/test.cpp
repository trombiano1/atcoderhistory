#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    vector<ll> a(5);
    for(auto i = 0; i < 5; i++){
        a.push_back(i);
    }
    sort(a.begin(),a.end());
    cout << distance(a.begin(),lower_bound(a.begin(),a.end(),3)) << endl;
    return 0;
}