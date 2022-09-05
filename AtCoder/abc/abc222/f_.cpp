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
    int n;
    cin >> n;
    vector<vector<pair<long long, int>>> G(n);
    for (int i = 0; i < n - 1; i++){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back({c, b});
        G[b].push_back({c, a});
    }
    vector<long long> d(n);
    for (int i = 0; i < n; i++){
        cin >> d[i];
    }
    dump(d);
    vector<bool> seen(n);
    vector<long long> max_from_root(n);
    vector<long long> max_from_root_without_d(n);
    vector<int> mx_v(n);
    vector<long long> second_max_from_root(n);
    function<long long(int)> Dfs = [&](int v) -> long long {
        seen[v] = true;
        long long mx = d[v];
        long long second_mx = -inf;
        for (auto [c, to] : G[v]) { 
            if (seen[to]) {
                continue;
            }
            vector<long long> res;
            res.push_back(Dfs(to)+c);
            res.push_back(mx);
            res.push_back(second_mx);
            sort(res.begin(), res.end(), greater<>());
            mx = res[0];
            second_mx = res[1];
        }
        max_from_root[v] = mx;
        if (mx == d[v]){
            max_from_root_without_d[v] = second_mx;
        } else {
            max_from_root_without_d[v] = mx;
        }
        second_max_from_root[v] = second_mx;
        return mx;
    };
    Dfs(0);
    dump(max_from_root);
    dump(second_max_from_root);

    seen.assign(n, 0);
    long long frm_root = 0;
    vector<long long> ans(n);
    dump(seen);
    function<void(int)> Dfs2 = [&](int v) -> void {
        seen[v] = true;
        long long frm_root_save = frm_root;
        for (auto [c, to] : G[v]){
            if (seen[to]) continue;

            long long cand;
            if (max_from_root[to] + c == max_from_root[v]){
                cand = second_max_from_root[v];
            } else {
                cand = max_from_root[v];
            }
            frm_root = max(frm_root, cand) + c;
            Dfs2(to);
            frm_root = frm_root_save;
        }
        ans[v] = max(frm_root, max_from_root_without_d[v]);

    };
    Dfs2(0);
    dump(ans);
    for (int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }
    return 0;
}