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
    int h, w, m;
    cin >> h >> w >> m;

    map<pair<int, int>, bool> mp;
    vector<long long> h_c(h);
    vector<long long> w_c(w);
    for(int i = 0; i < m; i++){
        int h_, w_;
        cin >> h_ >> w_;
        h_--; w_--;
        mp[{h_, w_}] = 1;
        h_c[h_]++;
        w_c[w_]++;
    }
    long long h_max=0, w_max=0;
    for(int i = 0; i < h; i++){
        if (h_c[i] > h_max){
            h_max = h_c[i];
        }
    }
    vector<long long> h_m;
    for(int i = 0; i < h; i++){
        if (h_c[i] == h_max){
            h_m.push_back(i);
        }
    }
    for(int i = 0; i < w; i++){
        if (w_c[i] > w_max){
            w_max = w_c[i];
        }
    }
    vector<long long> w_m;
    for(int i = 0; i < w; i++){
        if (w_c[i] == w_max){
            w_m.push_back(i);
        }
    }
    dump(h_m, w_m);
    for(auto i : h_m){
        for(auto j : w_m){
            if (!mp[{i, j}]){
                cout << h_max + w_max << endl;
                return 0;
            }
        }
    }
    cout << h_max + w_max - 1 << endl;
    return 0;
}