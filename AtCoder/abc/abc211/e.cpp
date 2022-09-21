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
    int n, k;
    cin >> n >> k;
    vector s(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        string sin;
        cin >> sin;
        dump(sin);
        for (int j = 0; j < n; j++) {
            s[i][j] = (sin[j] == '#') ? false : true;
        }
    }
    
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    auto inside = [&](int i, int j){
        if (0 <= i && i < n && 0 <= j && j < n){
            return true;
        }
        return false;
    };

    vector now(n, vector<int>(n));
    // 0: undecided, 1: chosen, 2: front, -1: not chosen
    function<long long(int)> Dfs = [&](int m) -> long long {
        if (m == k){
            return 1;
        }
        dump(now, m);
        vector<pair<int, int>> fronts;
        vector<vector<int>> oldest = now;
        
        // fronts
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (now[i][j] == 2){
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dirs[k].first, nj = j + dirs[k].second;
                        if (inside(ni, nj) && s[ni][nj] && now[ni][nj] == 0){
                            fronts.push_back({ni, nj});
                        }
                    }
                    now[i][j] = 1;
                }
            }
        }
        // remove duplicates
        sort(fronts.begin(), fronts.end());
        fronts.erase(unique(fronts.begin(), fronts.end()), fronts.end());
        dump(fronts);
        int size = fronts.size();
        long long res = 0;
        vector<vector<int>> old = now;
        for (long long bit = 0; bit < (1 << size); ++bit) {
            int new_count = 0;
            for (long long i = 0; i < size; ++i) {
                if (bit & (1<<i)) {
                    now[fronts[i].first][fronts[i].second] = 2;
                    new_count++;
                } else {
                    now[fronts[i].first][fronts[i].second] = -1;
                }
            }
            if (new_count == 0){
                continue;
            }
            if (new_count + m > k){
                continue;
            }
            res += Dfs(new_count + m);
            now = old;
        }
        now = oldest;
        return res;
    };
    
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j]){
                now[i][j] = 2;
                ans += Dfs(1);
                now[i][j] = 0;
            }
        }
    }
    cout << ans / k << endl;
    return 0;
}
