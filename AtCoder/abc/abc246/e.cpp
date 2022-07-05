#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e9
#define LINF 100000000000000000LL
#define all(x) begin(x), end(x)

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

vector<pair<int, int>> dirs = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
int n;

bool inside(int x, int y){
    if (x < 0) return false;
    if (x >= n) return false;
    if (y < 0) return false;
    if (y >= n) return false;
    return true;
}

int main(void) {
    int ax, ay, bx, by;
    cin >> n >> ax >> ay >> bx >> by;
    ax--; ay--; bx--; by--;

    if ((ax+ay)%2 != (bx+by)%2){
        cout << "-1" << endl;
        return 0;
    }

    vector<string> b(n);
    for(int i = 0; i < n; i++) cin >> b[i];
    dump(b);
    
    // vector<vector<pair<ll,ll>>> G(n); // {cost, to}
    vector<vector<vector<ll>>> dist(n);
    for(int i = 0; i < n; i++){
        dist[i].assign(n, {LINF, LINF, LINF, LINF});
    }

    priority_queue<pair<ll, tuple<int, int, int>>, vector<pair<ll, tuple<int, int, int>>>, greater<pair<ll, tuple<int, int, int>>>> pque;
    

    for(int k = 0; k < 4; k++){
        dist[ax][ay][k] = 1;
        pque.push({1, {ax, ay, k}});
    }
    
    while (!pque.empty()) {
        pair<ll, tuple<int, int, int>> p = pque.top();
        dump(p.first, p.second);
        pque.pop();
        ll d = p.first; // dist (minなら確定)
        tuple<int,int,int> v = p.second; // point name
        int x = get<0>(v);
        int y = get<1>(v);
        int dir = get<2>(v);

        if (dist[x][y][dir] < d) continue; // 最短以外は無視 else vは確定
        
        if (x == bx && y == by){
            cout << d << endl;
            return 0;
        }

        for(int k = 0; k < 4; k++){
            if (k == dir){
                int nx = x+dirs[k].first;
                int ny = y+dirs[k].second;
                if (inside(nx, ny)){
                    if (b[nx][ny] == '#') continue;
                    if (dist[nx][ny][k] > dist[x][y][dir]){
                        dist[nx][ny][k] = dist[x][y][dir];
                        pque.push({dist[x][y][dir], {nx, ny, k}});
                    }
                }
            } else {
                int nx = x+dirs[k].first;
                int ny = y+dirs[k].second;
                if (inside(nx, ny)){
                    if (b[nx][ny] == '#') continue;
                    if (dist[nx][ny][k] > dist[x][y][dir] + 1){
                        dist[nx][ny][k] = dist[x][y][dir] + 1;
                        pque.push({dist[x][y][dir] + 1, {nx, ny, k}});
                    }
                }
            }

        }
    }
    cout << "-1" << endl;
    return 0;
}