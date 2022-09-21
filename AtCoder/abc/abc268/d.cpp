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
    vector<string> s(n);
    map<string, bool> t;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    for (int i = 0; i < m; i++) {
        string t_;
        cin >> t_;
        t[t_] = true;
    }
    
    do{
        vector<int> left(n);
        left[n - 1] = s[n - 1].size();
        for (int i = n - 2; i >= 0; i--) {
            left[i] = left[i + 1] + s[i].size();
        }

        function<void(int, string)> Dfs = [&](int nxt, string ans) {
            dump(ans);
            if ((int) ans.size() > 16) {
                return;
            }
            if (nxt == n){
                if (!t[ans] && (int) ans.size() >= 3) {
                    cout << ans << endl;
                    exit(0);
                    return;
                }
                return;
            } 
            for (int i = 0; (int) ans.size() <= 16 - left[nxt]; i++) {
                ans += '_';
                Dfs(nxt + 1, ans + s[nxt]);
            }
        };
        Dfs(1, s[0]);
    } while (next_permutation(s.begin(), s.end()));
    cout << -1 << endl;
    return 0;
}