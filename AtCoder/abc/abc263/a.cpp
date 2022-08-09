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
    map<int, int> mp;
    for(int i = 0; i < 5; i++){
        int a;
        cin >> a;
        mp[a]++;
    }
    bool f2 = false, f3 = false;
    for(auto i : mp){
        if (i.second == 2){
            f2 = true;
        }
        if (i.second == 3){
            f3 = true;
        }
    }
    if (f2 && f3){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}