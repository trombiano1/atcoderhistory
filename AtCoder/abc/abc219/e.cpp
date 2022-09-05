#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

struct unionfind {
    vector<int> par;
    vector<int> siz;

    unionfind(int sz_) : par(sz_), siz(sz_, 1) {
        for(int i = 0; i < sz_; i++) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void merge(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        if (siz[rx] < siz[ry]) swap(rx, ry); // 小を大にくっつける(ry<rx)
        siz[rx] += siz[ry];
        par[ry] = rx;
    }

    bool same(int x, int y) {
       return root(x) == root(y);
    }

    int size(int x) {
        return siz[root(x)];
    }
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector mp(4, vector<bool>(4));
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            bool b;
            cin >> b;
            mp[i][j] = b;
        }
    }
    // {0, 1, ..., n-1} の部分集合の全探索
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    auto inside = [](int i, int j){
        if (0 <= i && i < 4 && 0 <= j && j < 4){
            return true;
        }
        return false;
    };

    int size = 16;
    long long res = 0;
    for (long long bit = 0; bit < (1<<size); ++bit) {
        [&]{ // bit
            vector nmp(4, vector<bool>(4));
            unionfind tree(17);
            int in = 0;
            for (long long i = 0; i < size; ++i) {
                if (bit & (1<<i)) {
                    nmp[i/4][i%4] = true;
                    in++;
                }
            }
            for (int i = 0; i < 4; i++){
                for (int j = 0; j < 4; j++){
                    if (mp[i][j] && !nmp[i][j]){ // break if not mp is in nmp
                        return; // ng bit
                    }
                    for (auto dir : dirs){
                        int ni = i + dir.first, nj = j + dir.second;
                        if (inside(ni, nj) && nmp[ni][nj] && nmp[i][j]){
                            tree.merge(i*4+j, ni*4+nj);
                        }
                        if (inside(ni, nj) && !nmp[ni][nj] && !nmp[i][j]){
                            tree.merge(i*4+j, ni*4+nj);
                        }
                        if (!inside(ni, nj) && !nmp[i][j]){
                            tree.merge(i*4+j, 16);
                        }
                    }
                }
            }
            for (int i = 0; i < 16; i++){
                if (!nmp[i/4][i%4]){
                    continue;
                }
                if (tree.siz[tree.root(i)] == in && tree.siz[tree.root(16)] == 16 - in + 1){
                    res++;
                    break; 
                }
            }
        }();
    }
    cout << res << endl;
    return 0;
}