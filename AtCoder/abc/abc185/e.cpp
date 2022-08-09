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
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    vector<long long> b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m ; i++){
        cin >> b[i];
    }
    vector<vector<long long>> dp(n, vector<long long>(m));
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            
        }
    }
    return 0;
}