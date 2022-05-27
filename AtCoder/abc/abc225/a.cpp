#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    string s;
    cin >> s;
    map<char, int> mp;
    for (unsigned long i = 0; i < s.size(); i++){
        mp[s[i]]++;
    }
    ll divisor = 1;
    for (auto i : mp){
        for(int j = 1; j <= i.second; ++j) {
            divisor *= j;
        }
    }
    // cout << divisor << endl;
    ll res = 1;
    for (auto i = 1; i <= 3; i++){
        res *= i;
    }
    cout << res / divisor << endl;
    return 0;
}