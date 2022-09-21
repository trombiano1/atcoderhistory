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
    for (int i = 0; i < 5; i++){
        int a;
        cin >> a;
        mp[a]++;
    }
    int res = 0;
    for (auto i : mp){
        res++;
    }
    cout << res << endl;
    return 0;
}