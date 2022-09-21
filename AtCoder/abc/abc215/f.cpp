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
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(), p.end());
    dump(p);
    const int inf = 1e9;
    
    int low = 0;
    int high = inf;
    while (high - low > 1) {
        int mid = (high + low) >> 1;
        int k = mid;

        int tp = -inf;
        int btm = inf;
        bool ok = [&]{
            int right = 1, left = 0;
            for (; right < n; right++) {
                for (; p[left].first <= p[right].first - k; left++) {
                    tp = max(tp, p[left].second);
                    btm = min(btm, p[left].second);
                }
                if (tp >= p[right].second + k || btm <= p[right].second - k) {
                    return true;
                }
            }
            return false;
        }();

        if (ok) {
            low = mid; // 上半分
        } else {
            high = mid; //下半分
        }
    }
    cout << low << '\n';
    return 0;
}