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
    int n;
    cin >> n;
    vector<long long> x(n);
    vector<long long> y(n);
    for (int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    dump(x, y);
    int m;
    cin >> m;
    vector<long long> u = {0, 0};
    vector<long long> mx = {1, 0, 0, 1};
    vector<vector<long long>> u_his;
    vector<vector<long long>> mx_his;
    u_his.push_back(u);
    mx_his.push_back(mx);
    dump(mx);
    for(int i = 0; i < m; i++){
        int t;
        cin >> t;
        if (t == 1){
            u = {u[1], -u[0]};
            mx = {mx[2], mx[3], -mx[0], -mx[1]};
        }
        if (t == 2){
            u = {-u[1], u[0]};
            mx = {-mx[2], -mx[3], mx[0], mx[1]};
        }
        if (t == 3){
            long long p;
            cin >> p;
            u = {2 * p - u[0], u[1]};
            mx = {-mx[0], -mx[1], mx[2], mx[3]};
        }
        if (t == 4){
            long long p;
            cin >> p;
            u = {u[0], 2 * p - u[1]};
            mx = {mx[0], mx[1], -mx[2], -mx[3]};
        }
        dump(mx, u);
        u_his.push_back(u);
        mx_his.push_back(mx);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        b--;
        cout << u_his[a][0] + mx_his[a][0] * x[b] + mx_his[a][1] * y[b];
        cout << " ";
        cout << u_his[a][1] + mx_his[a][2] * x[b] + mx_his[a][3] * y[b];
        cout << endl;
    }
    return 0;
}