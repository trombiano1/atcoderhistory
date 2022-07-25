#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    map<char, int> mp;
    for(int i = 0; i < (long long)s.size(); i++){
        mp[s[i]]++;
    }
    for(auto m : mp){
        if (m.second == 1){
            cout << m.first << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}