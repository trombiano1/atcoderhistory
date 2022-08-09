#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

int h, w;

bool inside(int a, int b){
    if (0 <= a && a < h && 0 <= b && b < w) return true;
    return false;
}

vector<vector<int>> DIRS = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> h >> w;
    int ch, cw, dh, dw;
    cin >> ch >> cw >> dh >> dw;
    ch--; cw--; dh--; dw--;
    vector<string> b(h);
    for(int i = 0; i < h; i++){
        cin >> b[i];
    }
    // vector<vector<pair<long long,int>>> G(n); // {cost, to}
    const long long inf = 1e18;
    vector<vector<long long>> dist(h, vector<long long>(w, inf));
    
    priority_queue<tuple<long long, int, int>, vector<tuple<long long,int, int>>, greater<tuple<long long, int, int>>> pque;
    
    dist[ch][cw] = 0;
    pque.push({0, ch, cw});
    
    while (!pque.empty()) {
        tuple<long long, int, int> p = pque.top();
        pque.pop();
        long long d = get<0>(p); // dist (minなら確定)
        int v1 = get<1>(p); // point
        int v2 = get<2>(p);
    
        if (dist[v1][v2] < d) continue; // 最短以外は無視 else vは確定
        // ここでreturn 0で出ても良い (見つからなかった場合の処理を忘れない)
    
        for (int i = -2; i <= 2; i++) { // vに繋がってる点が更新できれば候補に入れる
            for(int j = -2; j <= 2; j++){
                int nv1 = v1 + i;
                int nv2 = v2 + j;
                if (inside(nv1, nv2) && b[nv1][nv2] == '.'){
                    if (dist[nv1][nv2] > dist[v1][v2] + 1) {
                        dist[nv1][nv2] = dist[v1][v2] + 1;
                        pque.push({dist[nv1][nv2], nv1, nv2});
                    }
                }
            }
        }
        for(int i = 0; i < 4; i++){
            int nv1 = v1 + DIRS[i][0];
            int nv2 = v2 + DIRS[i][1];
            if (inside(nv1, nv2) && b[nv1][nv2] == '.'){
                if (dist[nv1][nv2] > dist[v1][v2]) {
                    dist[nv1][nv2] = dist[v1][v2];
                    pque.push({dist[nv1][nv2], nv1, nv2});
                }
            }
        }
    }
    if (dist[dh][dw] == inf){
        cout << -1 << endl;
    } else {
        cout << dist[dh][dw] << endl;
    }
    return 0;
}