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
    vector<vector<bool>> G(n, vector<bool>(n));
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--; 
        G[u][v] = true;
        G[v][u] = true;
    }
    dump(G);
    long long res = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                if (G[i][j] && G[j][k] && G[k][i]){
                    res++;
                }
            }
        }
   }
    cout << res / 6 << endl;
    return 0;
}