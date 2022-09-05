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
    int h1, w1;
    cin >> h1 >> w1;
    vector<vector<long long>> a(h1, vector<long long>(w1));
    for (int i = 0; i < h1; i++){
        for (int j = 0; j < w1; j++){
            cin >> a[i][j];
        }
    }
    int h2, w2;
    cin >> h2 >> w2;
    vector<vector<long long>> b(h2, vector<long long>(w2));
    for (int i = 0; i < h2; i++){
        for (int j = 0; j < w2; j++){
            cin >> b[i][j];
        }
    }
    dump(a, b);
    dump(h1);
    // {0, 1, ..., n-1} の部分集合の全探索
    for (long long bit = 0; bit < (1<<h1); ++bit) {
        vector<int> v;
        for (long long i = 0; i < h1; ++i) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                v.push_back(i);
            }
        }
        if ((int)v.size() != h2) continue;
        // SがUの部分集合
        // {0, 1, ..., n-1} の部分集合の全探索
        for (long long bit2 = 0; bit2 < (1<<w1); ++bit2) {
            vector<long long> h;
            for (long long j = 0; j < w1; ++j) {
                if (bit2 & (1<<j)) { // 列挙に i が含まれるか
                    h.push_back(j);
                }
            }
            // SがUの部分集合
            if ((int)h.size() != w2) continue;
            bool foundflag = true;
            for (int i = 0; i < h2; i++){
                for (int j = 0; j < w2; j++){
                    if (a[v[i]][h[j]] != b[i][j]){
                        foundflag = false;
                    }
                }
                if (!foundflag){
                    continue;
                }
            }
            if (foundflag){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}