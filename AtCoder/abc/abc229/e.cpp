#include <bits/stdc++.h>

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using Graph = vector<vector<ll>>;

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号 (例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る:root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時:xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main(void) {
    ll n, m;
    cin >> n >> m;
    UnionFind tree(n);
    Graph G(n);
    ll res = 0;
    for (auto i = 0; i < m; i++){
        ll a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<ll> res_vec;
    for (auto i = n-1; i >= 0; i--){
        res++;
        res_vec.push_back(res-1);
        // cout << " " << i+1 << "res" << res-1 << endl;
        for (auto j : G[i]){
            if (j >= i){
                // cout << j+1 << endl;
                if (!tree.same(j,i)){
                    res--;
                    tree.unite(i, j);
                }
            }
        }
    }
    for (auto i = n-1; i >= 0; i--){
        cout << res_vec[i] << endl;
    }
    return 0;
}