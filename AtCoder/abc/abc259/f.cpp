#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

vector<vector<pair<int, long long>>> G;
vector<int> d;
vector<long long> dp_less;
vector<long long> dp_leq;

const long long inf = 1e18;

void dfs(int k, int frm){
    long long sum = 0;
    vector<long long> u_vec;
    for (auto edge: G[k]){
        int nv = edge.first;
        long long c = edge.second;
        if (nv == frm) continue;
        dfs(nv, k);
        u_vec.push_back(dp_less[nv] - dp_leq[nv] + c);
        sum += dp_leq[nv];
    }
    if (u_vec.size() == 0){
        if (d[k] == 0){
            dp_leq[k] = 0;
            dp_less[k] = -inf;
        } else {
            dp_leq[k] = 0;
            dp_less[k] = 0;
        }
        return;
    }
    dump(G[k]);
    sort(u_vec.begin(), u_vec.end(), greater<>());
    dump(u_vec, d[k], k+1, frm+1, sum);
    long long less = 0, leq = 0;
    for (int i = 0; i < (int)u_vec.size() && i < d[k]-1 && u_vec[i] > 0; i++){
        less += u_vec[i];
    }
    dp_less[k] = sum + less;
    for (int i = 0; i < (int)u_vec.size() && i < d[k] && u_vec[i] > 0; i++){
        leq += u_vec[i];
    }
    dp_leq[k] = sum + leq;
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    d.resize(n);
    G.resize(n);
    dp_less.resize(n);
    dp_leq.resize(n);
    for (int i = 0; i < n; i++){
        cin >> d[i];
    }
    for (int i = 0; i < n-1; i++){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        u--; v--;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    dfs(0, -1);
    dump(dp_less);
    dump(dp_leq);
    cout << dp_leq[0] << endl;
    return 0;
}