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

int main(void) {
    string s;
    cin >> s;
    int sz = s.size();
    ll res = 0;
    // {0, 1, ..., n-1} の部分集合の全探索
    for (ll bit = 0; bit < (1<<sz); ++bit) {
        vector<int> S1;
        vector<int> S2;
        for (ll i = 0; i < sz; ++i) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                S1.push_back(s[i] - '0');
            } else {
                S2.push_back(s[i] - '0');
            }
        }
        sort(all(S1), greater<>());
        sort(all(S2), greater<>());
        if (S1.size() == 0) continue;
        if (S1[0] == 0) continue;
        if (S2.size() == 0) continue;
        if (S2[0] == 0) continue;

        ll s1 = 0;
        for(int i = 0; i < (int)S1.size(); i++){
            s1 *= 10;
            s1 += S1[i];
        }

        ll s2 = 0;
        for(int i = 0; i < (int)S2.size(); i++){
            s2 *= 10;
            s2 += S2[i];
        }
        res = max(res, s1*s2);
        // SがUの部分集合
    }
    cout << res << endl;
    return 0;
}