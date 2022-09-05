#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

const long long inf = 1e18;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector d(n, vector<long long>(n, inf));
    vector<tuple<int, int, long long>> e(m);
    for (int i = 0; i < m; i++){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--; b--;
        d[a][b] = c;
        d[b][a] = c;
        e[i] = {a, b, c};
    }
    
    for (int k = 0; k < n; k++){       // 経由する頂点
        for (int i = 0; i < n; i++) {    // 始点
            for (int j = 0; j < n; j++) {  // 終点
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    dump(d);
    long long ans = 0;
    for (auto edge : e){
        bool unused = false;
        for (int i = 0; i < n; i++){
            if (d[get<0>(edge)][i] + d[i][get<1>(edge)] <= get<2>(edge)){
                unused = true;
            }
        }
        ans += (int)unused;
    }
    cout << ans << endl;
    return 0;
}