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
    int r, c;
    cin >> r >> c;
    vector<vector<bool>> mp;
    mp.push_back({0,0,0,0,0,0,0,0,0,0,0,0,0,0,0});
    mp.push_back({0,1,1,1,1,1,1,1,1,1,1,1,1,1,0});
    mp.push_back({0,1,0,0,0,0,0,0,0,0,0,0,0,1,0});
    mp.push_back({0,1,0,1,1,1,1,1,1,1,1,1,0,1,0});
    mp.push_back({0,1,0,1,0,0,0,0,0,0,0,1,0,1,0});
    mp.push_back({0,1,0,1,0,1,1,1,1,1,0,1,0,1,0});
    mp.push_back({0,1,0,1,0,1,0,0,0,1,0,1,0,1,0});
    mp.push_back({0,1,0,1,0,1,0,1,0,1,0,1,0,1,0});
    mp.push_back({0,1,0,1,0,1,0,0,0,1,0,1,0,1,0});
    mp.push_back({0,1,0,1,0,1,1,1,1,1,0,1,0,1,0});
    mp.push_back({0,1,0,1,0,0,0,0,0,0,0,1,0,1,0});
    mp.push_back({0,1,0,1,1,1,1,1,1,1,1,1,0,1,0});
    mp.push_back({0,1,0,0,0,0,0,0,0,0,0,0,0,1,0});
    mp.push_back({0,1,1,1,1,1,1,1,1,1,1,1,1,1,0});
    mp.push_back({0,0,0,0,0,0,0,0,0,0,0,0,0,0,0});
    
    if (mp[r-1][c-1]){
        cout << "white" << endl;
    } else {
        cout << "black" << endl;
    }
    return 0;
}